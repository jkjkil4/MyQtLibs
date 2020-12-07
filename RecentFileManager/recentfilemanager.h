#ifndef RECENTFILEMANAGER_H
#define RECENTFILEMANAGER_H

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

class RecentFileManager
{
public:
    explicit RecentFileManager(const QString &filePath);

    QStringList loadAll(int limitCount = -1, bool *ok = nullptr);
    void append(const QString &path, bool *ok = nullptr);

private:
    QString filePath;
};

#endif // RECENTFILEMANAGER_H
