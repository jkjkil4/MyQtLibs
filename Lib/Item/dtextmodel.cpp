#include "dtextmodel.h"


DTextModel::DTextModel(QObject *parent) : QAbstractListModel(parent) {}

int DTextModel::rowCount(const QModelIndex &parent) const {
    if (parent.row() == -1)
        return mDatas.size();
    return 0;
}

QVariant DTextModel::data(const QModelIndex &index, int role) const {
    if(role == Qt::TextAlignmentRole) {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    } else if(role >= Qt::UserRole) {
        const Data &data = mDatas[index.row()];
        switch(role) {
        case Qt::UserRole:
            return data.text1;
        case Qt::UserRole + 1:
            return data.text2;
        }
    }
    return QVariant();
}
QString DTextModel::data(int row) {
    if(row < 0 || row >= mDatas.size())
        return "";
    return mDatas[row].text2;
}

bool DTextModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role >= Qt::UserRole) {
        Data &data = mDatas[index.row()];
        switch(role) {
        case Qt::UserRole:
            data.text1 = value.toString();
            break;
        case Qt::UserRole + 1:
            data.text2 = value.toString();
            break;
        default:
            return false;
        }
        return true;
    }
    return false;
}

void DTextModel::clear() {
    beginRemoveRows(QModelIndex(), 0, mDatas.size() - 1);
    mDatas.clear();
    endRemoveRows();
}

int DTextModel::count() const {
    return mDatas.size();
}

int DTextModel::indexOf(const Data &ind) const {
    return mDatas.indexOf(ind);
}

void DTextModel::insert(int pos, const Data &data) {
    beginInsertRows(QModelIndex(), pos, pos);
    mDatas.insert(pos, data);
    endInsertRows();
}
void DTextModel::insert(const Data &pos, const Data &data) {
    insert(indexOf(pos), data);
}

void DTextModel::append(const Data &data) {
    beginInsertRows(QModelIndex(), mDatas.size(), mDatas.size());
    mDatas.append(data);
    endInsertRows();
}

void DTextModel::remove(int pos) {
    if(pos < 0 || pos >= mDatas.size())
        return;
    beginRemoveRows(QModelIndex(), pos, pos);
    mDatas.removeAt(pos);
    endRemoveRows();
}

void DTextModel::remove(const Data &pos) {
    remove(indexOf(pos));
}

DTextModel::Data DTextModel::take(int pos) {
    beginRemoveRows(QModelIndex(), pos, pos);
    Data data = mDatas.takeAt(pos);
    endRemoveRows();
    return data;
}

DTextModel::Data DTextModel::take(const Data &pos) {
    return take(indexOf(pos));
}

const DTextModel::Data &DTextModel::at(int index) {
    return mDatas[index];
}
