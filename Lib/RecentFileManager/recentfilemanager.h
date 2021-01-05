#ifndef RECENTFILEMANAGER_H
#define RECENTFILEMANAGER_H

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

#include "Lib/header.h"

class RecentFileManager
{
public:
    RecentFileManager() = default;
    explicit RecentFileManager(const QString &filePath);

    QStringList loadAll(int limitCount = -1, bool *ok = nullptr);
    void append(const QString &path, bool *ok = nullptr);

    VAR_FUNC(FilePath, filePath, QString, , )

private:
    QString filePath;
};

#endif // RECENTFILEMANAGER_H
