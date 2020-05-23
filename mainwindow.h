#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtPrintSupport>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

void save();

bool maybeSave();

void closeEvent(QCloseEvent *event);

private slots:
    void on_actionE_xit_triggered();

    void on_action_Open_triggered();

    void setModified(bool modified);

    void on_action_New_triggered();

    void on_action_Print_triggered();

       void open();
       void saveAs();
       void print();
       void copy();
       void paste();
       void zoomIn();
       void zoomOut();
       void normalSize();
       void fitToWindow();
       void about();

private:

       void createActions();
           void createMenus();
           void updateActions();
           bool saveFile(const QString &fileName);
           void setImage(const QImage &newImage);
           void scaleImage(double factor);
           void adjustScrollBar(QScrollBar *scrollBar, double factor);

           QImage image;
           QLabel *imageLabel;
           QScrollArea *scrollArea;
           double scaleFactor = 1;




    bool isModified;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
