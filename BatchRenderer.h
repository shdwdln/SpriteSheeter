#ifndef BATCHRENDERER_H
#define BATCHRENDERER_H

#include <QObject>
#include <QRunnable>
#include <QImage>
#include <QList>
#include <QStringList>
#include <QColor>
#include <QFont>

class BatchRenderer : public QObject, public QRunnable
{
    Q_OBJECT

    QList<QList<QImage> > mSheetFrames;
    QStringList mAnimNames;
    QImage mCurSheet;
    bool bStop;

public:
    explicit BatchRenderer(QObject *parent = 0);

    //Variables for drawing
    QString folder;
    QFont sheetFont;
    int maxSheetWidth;
    int offsetX;
    int offsetY;
    bool animNameEnabled;
    bool sheetBgTransparent;
    QColor sheetBgCol;
    QColor animHighlightCol;
    bool frameBgTransparent;
    QColor frameBgCol;
    QColor fontColor;

    void run();

public slots:
    void stop();

signals:
    void renderingDone();
    void renderingStart(QString sheetName);
};

#endif // BATCHRENDERER_H
