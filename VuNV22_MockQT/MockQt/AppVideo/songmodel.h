#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QObject>
#include<QAbstractListModel>
#include"songdata.h"
#include<QDebug>
#include<QDir>
#include<QFileInfo>
#include<QStandardPaths>
#include<QUrl>

class SongModel : public QAbstractListModel
{
    Q_OBJECT
    enum InfomationRoles {
        titleRole = Qt::UserRole + 1,
        albumRole,
        artistRole

    };
public:
    SongModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;;
    QVariant data(const QModelIndex &index, int role) const;;
    bool setData(const QModelIndex &index, const QVariant &value, int role);;
    QHash<int, QByteArray> roleNames() const;
    void addSong(const SongData &song);
    QList<SongData> getListSong();

private:
    QList<SongData> m_listSong;

};

#endif // SONGMODEL_H
