#include "recentfilemanager.h"

RecentFileManager::RecentFileManager(const QString &filePath)
    : filePath(filePath) {}

QStringList RecentFileManager::loadAll(int limitCount, bool *ok) {
    QFile file(filePath);   //文件
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) { //以只读方式打开文件，如果不能打开，则return
        if(ok) *ok = false;
        return QStringList();
    }

    QStringList lRecentFiles;   //最近文件列表
    QTextStream in(&file);  //输入流
    while(!in.atEnd()) {    //循环直到全部读取
        //得到并处理路径
        QString path = in.readLine().simplified().trimmed();
        path = QFileInfo(path).canonicalFilePath();

        //检测路径是否满足条件 ( 路径不为空 并且 路径存在 )
        if(path.isEmpty() || !QDir().exists(path))
            continue;

        //如果 路径重复 ， 则删除原先存在的
        if(lRecentFiles.contains(path))
            lRecentFiles.removeOne(path);

        //将路径添加到 lRecentFiles 中
        lRecentFiles.insert(0, path);
    }
    file.close();   //关闭文件

    //检测路径数量是否超过限制(limitCount不等于-1的前提下)
    if(limitCount != -1 && lRecentFiles.size() > limitCount) {
        QFile writeFile(filePath);  //文件
        int ignoreCount = lRecentFiles.size() - limitCount; //要忽略的数量

        if(!writeFile.open(QIODevice::WriteOnly | QIODevice::Text)) //以只写方式打开文件，若不能，则跳转至End
            goto End;

        QTextStream out(&writeFile); //输出流
        //从第limitCount个向前遍历
        for(auto iter = lRecentFiles.rbegin() + ignoreCount; iter < lRecentFiles.rend(); ++iter) {
            QString path = *iter;
            out << "\n" << path;
        }
        writeFile.close();  //关闭文件

        for(int i = 0; i < ignoreCount; i++)    //移除过多的路径
            lRecentFiles.removeLast();
    }

    End:
    if(ok) *ok = true;
    return lRecentFiles;
}

void RecentFileManager::append(const QString& path, bool *ok) {
    QFile file(filePath);   //文件
    if(!file.open(QIODevice::Append | QIODevice::Text)) {   //以追加的方式打开文件，如果不能打开，则return
        SET_PTR(ok, false);
        return;
    }
    QTextStream(&file) << "\n" << path; //输出
    file.close();   //关闭文件

    SET_PTR(ok, true);
}
