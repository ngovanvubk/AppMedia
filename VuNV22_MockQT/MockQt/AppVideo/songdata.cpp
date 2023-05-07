#include "songdata.h"



SongData::SongData(QString title, QString album, QString artist)
    : m_title(title), m_album (album),m_artist(artist)
{

}

void SongData::setTitle(const QString title) {
    m_title = title ;
}

QString SongData::getTitle() const {
    return m_title;
}

void SongData::setAlbum(const QString album) {
    m_album = album ;
}

QString SongData::getAlbum() const {
    return m_album;
}

void SongData::setArtist(const QString artist) {
    m_artist = artist ;
}

QString SongData::getArtist() const {
    return m_artist;
}
