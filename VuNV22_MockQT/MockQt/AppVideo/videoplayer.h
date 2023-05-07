#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAbstractVideoSurface>
#include <QMediaMetaData>
#include <QMediaPlaylist>
#include <QDebug>
class VideoPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
    Q_PROPERTY(QString filename READ filename WRITE setFilename NOTIFY filenameChanged)
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
public:
    explicit  VideoPlayer(QObject *parent = nullptr);
    ~VideoPlayer();

    QAbstractVideoSurface *videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface *surface);

    Q_INVOKABLE void requestPlay();
    Q_INVOKABLE void nextVideo();
    Q_INVOKABLE void prevVideo();
    QMediaPlayer *getPlayer();
    QMediaPlaylist *getPlayList();
    QString filename() const;

    qint64 duration() const;

    qint64 position() const;
    void handleDurationChanged(qint64 duration);
signals:
    void videoSurfaceChanged();
    void filenameChanged(QString filename);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);

public slots:
    void handlePlayingTimeChanged(qint64 position);
    void handlePlaybackStatusChanged(QMediaPlayer::State status);
    void setFilename(QString filename);

    void setDuration(qint64 duration);

    void setPosition(qint64 position);
    void seekSong(qint64 position);
private:
    QAbstractVideoSurface *m_surface;
    QMediaPlayer* mMediaPlayer;
    QMediaPlaylist *m_playlistVideo ;
    QStringList m_fileNames;
    QMediaPlayer::State mCurrentStatus;
    QString m_filename;
    qint64 m_duration;
    qint64 m_position;
};

#endif // VIDEOPLAYER_H
