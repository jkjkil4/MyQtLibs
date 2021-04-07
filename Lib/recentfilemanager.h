#pragma once

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

#include "Lib/header.h"

class RecentFileManager : public QObject
{
    Q_OBJECT
signals:
    void changed();

public:
    RecentFileManager() = default;
    explicit RecentFileManager(const QString &filePath) : mFilePath(filePath) {}

    template<typename CheckFn = bool(*)(const QString&)>
    void load(int limitCount = -1, bool *ok = nullptr, CheckFn fn = nullptr) {
        mFileList = QStringList();

        QFile file(mFilePath);   //文件
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) { //以只读方式打开文件，如果不能打开，则return
            if(ok) *ok = false;
            return;
        }

        QTextStream in(&file);  //输入流
        while(!in.atEnd()) {    //循环直到全部读取
            //得到并处理路径
            QString path = in.readLine().simplified().trimmed();
            path = QFileInfo(path).canonicalFilePath();

            //检测路径是否满足条件 ( 路径不为空 并且 路径存在 )
            if(path.isEmpty() || !QDir().exists(path))
                continue;

            //自定义检测
            if(fn && !(*fn)(path)) continue;

            //如果 路径重复 ， 则删除原先存在的
            if(mFileList.contains(path))
                mFileList.removeOne(path);

            //将路径添加到 list 中
            mFileList.append(path);
        }
        file.close();   //关闭文件

        //检测路径数量是否超过限制(limitCount不等于-1的前提下)
        if(limitCount != -1 && mFileList.size() > limitCount) {
            int ignoreCount = mFileList.size() - limitCount; //要忽略的数量
            for(int i = 0; i < ignoreCount; i++)    //移除过多的路径
                mFileList.removeLast();
        }

        if(ok) *ok = true;
        emit changed();
    }
    void save(bool *ok = nullptr) {
        QFile file(mFilePath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            SET_PTR(ok, false);
            return;
        }

        QTextStream out(&file);
        for(const QString &file : mFileList)
            out << file << "\n";

        file.close();
    }
    void append(const QString &path) {
        QString cPath = QFileInfo(path).canonicalFilePath();
        int index = mFileList.indexOf(cPath);
        if(index == -1) {
            mFileList.insert(0, cPath);
            emit changed();
        } else if(index != 0) {
            mFileList.removeAt(index);
            mFileList.insert(0, cPath);
            emit changed();
        }
    }
    void clear() {
        mFileList.clear();
        emit changed();
    }
    void remove(int index) {
        mFileList.removeAt(index);
        emit changed();
    }

    const QStringList& list() { return mFileList; }

    VAR_FUNC(filePath, setFilePath, mFilePath, QString, , )

private:
    QString mFilePath;
    QStringList mFileList;
};
