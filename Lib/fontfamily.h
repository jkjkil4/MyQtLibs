#pragma once

#include <QString>
#include <QFontDatabase>

class FontFamily
{
public:
    void load(const QString &path) {
        int lcdFontId = QFontDatabase::addApplicationFont(path);
        if(lcdFontId != -1) {
            mFamily = QFontDatabase::applicationFontFamilies(lcdFontId)[0];
        } else mFamily = QFont().defaultFamily();
    }

    QString mFamily;
};
