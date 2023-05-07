#include "songmodel.h"



SongModel::SongModel(QObject *parent)
    : QAbstractListModel (parent)
{

}

int SongModel::rowCount(const QModelIndex &parent) const{
    return  m_listSong.count();
}

QVariant SongModel::data(const QModelIndex &index, int role) const{
    QVariant res;
    int idx = index.row();
    switch (role) {
    case titleRole:
        res = m_listSong.at(idx).getTitle();
        break;
    case  albumRole:
        res = m_listSong.at(idx).getAlbum();
        break;
    case artistRole:
        res = m_listSong.at(idx).getArtist();
        break;
    default:
        break;
    }
    return res;
}

bool SongModel::setData(const QModelIndex &index, const QVariant &value, int role){
    qDebug()<<"setdata is called";
    int idx = index.row();
    switch (role) {
    case titleRole:
        m_listSong[idx].setTitle(value.toString());
        break;
    case albumRole:
        m_listSong[idx].setAlbum(value.toString());
        break;
    case artistRole:
        m_listSong[idx].setArtist(value.toString());
        break;
    default:
        break;
    }
    emit dataChanged(index, index);
}

QHash<int, QByteArray> SongModel::roleNames() const{
    qDebug() << "roleNames called";
    QHash<int, QByteArray> roles;
    roles[titleRole] = "title";
    roles[albumRole] = "album";
    roles[artistRole] = "artist";
    return roles;

}

void SongModel::addSong(const SongData &song){
    m_listSong.clear();
    return  m_listSong.append(song);
}

QList<SongData> SongModel::getListSong(){
    return m_listSong;
}


