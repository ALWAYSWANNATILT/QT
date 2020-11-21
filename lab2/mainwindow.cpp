#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QTextStream>
#include <QFileInfo>
#include <QFileDialog>

MainWindow::MainWindow(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    settings = new QSettings(this);
    loadFont();
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(documentModified()));
    connect(ui->actionSave, SIGNAL(triggered()), this ,SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    this->setWindowTitle("MainWindow[*]");
    loadFile(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered(const QString &fileName)
{
   MainWindow *txtedt = new MainWindow();
   txtedt->show();
   txtedt->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}


void MainWindow::on_actionExit_triggered()
{
   qApp->closeAllWindows();
}

void MainWindow::documentModified()
{
    this->setWindowModified(true);
}

void MainWindow::setFileName(const QString &fileName)
{
    this->m_fileName=fileName;
    this->setWindowTitle(QString("%1[*] - %2")
        .arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName())
        .arg(QApplication::applicationName()));
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if(this->isWindowModified())
    {
            int result = QMessageBox::warning(this,"Warning","File unsaved. Do you want close it now?",QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
            if (result == QMessageBox::Yes)
            {
                e->accept();
            }
            else e->ignore();
    }
}


void MainWindow::on_actionSelectFont_triggered()
{
    bool ok;
        QFont font = QFontDialog::getFont(&ok, ui->textEdit->font(), this);
        if(ok)
        {
            ui->textEdit->setFont(font);
            saveFont();
        }
}

void MainWindow::saveFont()
{
    settings->setValue("Select Font",ui->textEdit->font());
}
void MainWindow::loadFont()
{
    ui->textEdit->setFont((settings->value("viewFont").value<QFont>()));
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionCut_triggered()
{
  ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actionCopy->setEnabled(b);
    ui->actionCut->setEnabled(b);
}

void MainWindow::on_textEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);

}

void MainWindow::on_textEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}

void MainWindow::on_actionAbout_triggered()
{
    QString titleText("О программе");
    QString aboutText("Хорошая программа ыыыыыыыы");
    QMessageBox::about(this,titleText,aboutText);
}

void MainWindow::loadFile(const QString &fileName)
{
    try{
            if (fileName.isEmpty()) throw new std::exception();

            QFile file(fileName);

            if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
                throw new std::invalid_argument("File opening error");
            //file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream scanner(&file);
            ui->textEdit->setText(scanner.readAll());
            file.close();
            setFileName(fileName);
            this->setWindowModified(false);

        }
        catch(std::invalid_argument &ex){
            QMessageBox::warning(this,"File opening erro","Something is wrong with the file:(");
            setFileName(QString());
        }
        catch(...){
            setFileName(QString());
        }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
       "Open document", QDir::currentPath(), "Text documents (*.txt)");

       if (fileName.isEmpty()) return;
       if(m_fileName.isNull() && !isWindowModified()){  // pass ???
           loadFile(fileName);
       }
       else{
           on_actionNew_triggered(fileName);
       }
}

bool MainWindow::saveFile()
{
    if(m_fileName.isNull())
        return saveFileAs();
    else{
        QFile file(m_fileName);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QMessageBox::warning(this,"ERROR-ERROR:","File coultdn't be opened");
            setFileName(QString());
            return false;
        }
        else{
            QTextStream scanner(&file);
            scanner << ui->textEdit->toPlainText();
        }
        file.close();
        this->setWindowModified(false);
        return true;
    }
}

bool MainWindow::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
       m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if (fileName.isNull())
        return false;
    setFileName(fileName);
    return saveFile();
}




