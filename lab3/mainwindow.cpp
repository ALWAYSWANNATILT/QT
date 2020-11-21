#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(3,3, this);
    model2 = new QStandardItemModel(3,3, this);
    model3 = new QStandardItemModel(3,3, this);

    ui->tableView->setModel(model);
    ui->tableView_2->setModel(model2);
    ui->tableView_3->setModel(model3);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QModelIndex index;
    for(int row = 0; row < model->rowCount(); ++row)
    {
     for(int col = 0; col < model->columnCount(); ++col)
     {
         index = model->index(row,col);
         model->setData(index,rand()%10);
         index = model2->index(row,col);
         model2->setData(index,rand()%10);
     }
    }

    zero();
}

void MainWindow::on_pushButton_2_clicked()
{
    zero();
    QModelIndex index1;
    QModelIndex index2;
    QModelIndex index3;
    QModelIndex index4;

    int max=0;

    for(int row = 0; row < model3->rowCount(); ++row)
    {
     for(int col = 0; col < model3->columnCount(); ++col)
     {
        index1 = model->index(row,col);
        index2 = model2->index(row,col);
        index3 = model3->index(row,col);
        model3->setData(index3, model->data(index1).toInt() + model2->data(index2).toInt());      
   }
    }

    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                index4 = model3->index(row,col);
                if(max < model3->data(index4).toInt()){
                    max = model3->data(index4).toInt();
                }

            }
    }

    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {

                index4 = model3->index(row,col);
                if(max == model3->data(index4).toInt()){
                   model3->setData(index4, QColor(Qt::yellow), Qt::BackgroundRole);
                }

            }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    zero();
    QModelIndex index1;
    QModelIndex index2;
    QModelIndex index3;
    QModelIndex index4;
    int max = 0;
    for(int row = 0; row < model3->rowCount(); ++row)
    {
     for(int col = 0; col < model3->columnCount(); ++col)
     {
         index1 = model->index(row,col);
         index2 = model2->index(row,col);
         index3 = model3->index(row,col);
        model3->setData(index3, model->data(index1).toInt() - model2->data(index2).toInt());

     }
    }

    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                index4 = model3->index(row,col);
                if(max < model3->data(index4).toInt()){
                    max = model3->data(index4).toInt();
                }
            }
    }

    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                index4 = model3->index(row,col);
                if(max == model3->data(index4).toInt()){
                   model3->setData(index4, QColor(Qt::blue), Qt::BackgroundRole);
                }
            }
    }
}

void MainWindow::zero(){
    QModelIndex index;
        for(int row = 0; row < model->rowCount(); ++row)
        {
            for(int col = 0; col < model->columnCount(); ++col)
            {
                index = model3->index(row,col);
                model3->setData(index, QColor(Qt::white), Qt::BackgroundRole);
            }
        }
}

// product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
void MainWindow::on_pushButton_4_clicked()
{
    zero();
    QModelIndex index1;
    QModelIndex index2;
    QModelIndex index3;
    QModelIndex index4;
    int temp = 0;
    int max =0;


    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                temp=0;

                for (int inner = 0; inner < 4; inner++) {

                    index1 = model->index(row,inner);
                    index2 = model2->index(inner,col);
                    index3 = model3->index(row,col);
                    temp += model->data(index1).toInt() * model2->data(index2).toInt();
                }
                 model3->setData(index3, temp);
                // model3->setData(index3, QColor(Qt::red), Qt::BackgroundRole);
    }
}
    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {


                index4 = model3->index(row,col);
                if(max < model3->data(index4).toInt()){
                    max = model3->data(index4).toInt();
                }

            }
    }

    for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                temp=0;

                index4 = model3->index(row,col);
                if(max == model3->data(index4).toInt()){
                   model3->setData(index4, QColor(Qt::red), Qt::BackgroundRole);
                }

            }
    }

}
