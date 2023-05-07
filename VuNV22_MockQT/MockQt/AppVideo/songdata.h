#ifndef SONGDATA_H
#define SONGDATA_H
#include<QObject>

class SongData
{
private:
    QString m_title ;
    QString m_album;
    QString m_artist;
public:
    SongData(QString title,QString album,QString artist); 
    void setTitle(const  QString title);
    QString getTitle() const;
    void setAlbum(const  QString album);
    QString getAlbum() const;
    void setArtist(const  QString artist);
    QString getArtist() const;
};

#endif // SONGDATA_H
