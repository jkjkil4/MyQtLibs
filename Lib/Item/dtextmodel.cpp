#include "dtextmodel.h"


DTextModel::DTextModel(QObject *parent) : QAbstractListModel(parent) {}

DTextModel::~DTextModel() {
    clear();
}

int DTextModel::rowCount(const QModelIndex &parent) const {
    if (parent.row() == -1)
        return vDatas.size();
    return 0;
}

QVariant DTextModel::data(const QModelIndex &index, int role) const {
    if(role == Qt::TextAlignmentRole) {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    } else if(role >= Qt::UserRole) {
        Data *pData = vDatas.at(index.row());
        switch(role) {
        case Qt::UserRole:
            return pData->text1;
        case Qt::UserRole + 1:
            return pData->text2;
        }
    }
    return QVariant();
}

bool DTextModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role >= Qt::UserRole) {
        Data *pData = vDatas.at(index.row());
        switch(role) {
        case Qt::UserRole:
            pData->text1 = value.toString();
            break;
        case Qt::UserRole + 1:
            pData->text2 = value.toString();
            break;
        default:
            return false;
        }
        return true;
    }
    return false;
}

void DTextModel::clear() {
    for(Data *data : vDatas)
        delete data;
    vDatas.clear();
}

int DTextModel::count() {
    return vDatas.size();
}

int DTextModel::indexOf(Ind ind) {
    return vDatas.indexOf(ind);
}

void DTextModel::insert(int pos, const QString& text1, const QString& text2) {
    vDatas.insert(pos, new Data{ text1, text2 });
}
void DTextModel::insert(Ind pos, const QString& text1, const QString& text2) {
    insert(indexOf(pos), text1, text2);
}

void DTextModel::append(const QString &text1, const QString &text2) {
    vDatas.append(new Data{ text1, text2 });
}

void DTextModel::remove(int pos) {
    if(pos < 0 || pos >= vDatas.size())
        return;
    delete vDatas.takeAt(pos);
}

void DTextModel::remove(Ind pos) {
    remove(indexOf(pos));
}

DTextModel::Ind DTextModel::take(int pos) {
    return vDatas.takeAt(pos);
}

DTextModel::Ind DTextModel::take(Ind pos) {
    return take(indexOf(pos));
}

DTextModel::Ind DTextModel::at(int index) {
    return vDatas.value(index, nullptr);
}
