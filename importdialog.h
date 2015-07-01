#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

namespace Ui {
class importDialog;
}

class importDialog : public QDialog
{
    Q_OBJECT

public:
    explicit importDialog(QWidget *parent = 0);
    ~importDialog();

signals:
    void importOK(int numx, int numy);
    void importAll(int numx, int numy);

public slots:
    void setPreviewImage(QString sImg);

private slots:
    void on_okButton_clicked();
    void on_allButton_clicked();

private:
    Ui::importDialog *ui;

    QGraphicsScene* scene;
    //QGraphicsView* view;
    QGraphicsPixmapItem* item;
};

#endif // IMPORTDIALOG_H
