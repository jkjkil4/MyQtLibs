#ifndef FONTFAMILY_H
#define FONTFAMILY_H

#include <QString>
#include <QFontDatabase>

class FontFamily
{
public:
    void load(const QString &path) {
        int lcdFontId = QFontDatabase::addApplicationFont(path);
        if(lcdFontId != -1) {
            family = QFontDatabase::applicationFontFamilies(lcdFontId)[0];
        } else family = QFont().defaultFamily();
    }

    QString family;
};

#endif // FONTFAMILY_H
