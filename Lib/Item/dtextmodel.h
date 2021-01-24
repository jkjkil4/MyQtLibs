#pragma once

#include <QAbstractListModel>

#include <Lib/header.h>

//#include <QDebug>

class DTextModel : public QAbstractListModel
{
public:
    struct Data
    {
        QString text1;
        QString text2;
    };
    typedef Data* Ind;

    explicit DTextModel(QObject *parent = nullptr);
    ~DTextModel() override;

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void clear();
    int count();
    int indexOf(Ind ind);
    void insert(int pos, const QString& text1, const QString& text2);
    void insert(Ind pos, const QString& text1, const QString& text2);
    void append(const QString& text1, const QString& text2);
    void remove(int pos);
    void remove(Ind pos);
    Ind take(int pos);
    Ind take(Ind pos);
    Ind at(int index);

private:
    QVector<Data*> vDatas;
};
