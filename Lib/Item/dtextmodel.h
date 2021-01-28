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
        inline bool operator==(const Data &other) const {
            return text1 == other.text1 && text2 == other.text2;
        }
    };

    explicit DTextModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void clear();
    int count() const;
    int indexOf(const Data &ind) const;
    void insert(int pos, const Data &data);
    void insert(const Data &pos, const Data &data);
    void append(const Data &data);
    void remove(int pos);
    void remove(const Data &pos);
    Data take(int pos);
    Data take(const Data &pos);
    const Data &at(int index);

private:
    QList<Data> lDatas;
};
