#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &fileName = QString(),QWidget *parent = nullptr);
    ~MainWindow();
    void saveFont();
    void loadFont();

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_actionNew_triggered(const QString &fileName = nullptr);
    void on_actionClose_triggered();
    void on_actionExit_triggered();
    void documentModified();
    void on_actionSelectFont_triggered();
    void on_actionAboutQt_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionRedo_triggered();
    void on_textEdit_copyAvailable(bool b);
    void on_textEdit_redoAvailable(bool b);
    void on_textEdit_undoAvailable(bool b);
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();
    bool saveFile();
    bool saveFileAs();

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    QSettings *settings;


    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);
};
#endif // MAINWINDOW_H
