#include "mainwindow.h"
#include "resval.h"
#include "ui_ResCalc.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_band1_ColorSel_currentIndexChanged(int index)
{
    int nBands = ui->NBand_slider->value(); //Holds the number of bands currently in use
    int signif; //Stores the significant value

    //Changes the current significant value
    if (nBands > 4)
    {
        signif = index * 100 + ui->band2_ColorSel->currentIndex() * 10 + ui->band3_ColorSel->currentIndex();
    }
    else
    {
        signif = index * 10 + ui->band2_ColorSel->currentIndex();
    }
    resVal.signifChg(signif); //Stores the new significant value

    //Sets the currently selected band color
    ui->BAND_1->setStyleSheet("background-color:" + ui->band1_ColorSel->itemText(index) + ";");

    colorChanged(1, index);
}

void MainWindow::on_band2_ColorSel_currentIndexChanged(int index)
{
    int nBands = ui->NBand_slider->value(); //Holds the number of bands currently in use
    int signif; //Stores the significant value

    //Changes the current significant value
    if (nBands > 4)
    {
        signif = ui->band1_ColorSel->currentIndex() * 100 + index * 10 + ui->band3_ColorSel->currentIndex();
    }
    else
    {
        signif = ui->band1_ColorSel->currentIndex() * 10 + index;
    }
    resVal.signifChg(signif); //Stores the new significant value

    //Sets the currently selected band color
    ui->BAND_2->setStyleSheet("background-color:" + ui->band2_ColorSel->itemText(index) + ";");

    colorChanged(2, index);
}

void MainWindow::on_band3_ColorSel_currentIndexChanged(int index)
{
    int nBands = ui->NBand_slider->value(); //Holds the number of bands currently in use

    if (nBands > 4)
    {
        //Changes the current significant value
        int signif = ui->band1_ColorSel->currentIndex() * 100 + ui->band2_ColorSel->currentIndex() * 10 + index;
        resVal.signifChg(signif); //Stores the new significant value
    }
    else
    {
        //Changes the current significant value
        int signif = ui->band1_ColorSel->currentIndex() * 10 + ui->band2_ColorSel->currentIndex();
        resVal.signifChg(signif); //Stores the new significant value
        resVal.multChg(index - 2); //Changes the current multiplier value
    }

    //Sets the currently selected band color
    ui->BAND_3->setStyleSheet("background-color:" + ui->band3_ColorSel->itemText(index) + ";");

    colorChanged(3, index);
}

void MainWindow::on_band4_ColorSel_currentIndexChanged(int index)
{
    int nBands = ui->NBand_slider->value(); //Holds the number of bands currently in use

    if (nBands > 4)
    {
        //Changes the current significant value
        int signif = ui->band1_ColorSel->currentIndex() * 100 + ui->band2_ColorSel->currentIndex() * 10 + ui->band1_ColorSel->currentIndex();
        resVal.signifChg(signif); //Stores the new significant value
        resVal.multChg(index - 2); //Changes the current multiplier value
    }
    else
    {
        resVal.tolChg(tolValPI[index]); //Changes the current tolerance value
    }

    //Sets the currently selected band color
    ui->BAND_4->setStyleSheet("background-color:" + ui->band4_ColorSel->itemText(index) + ";");

    colorChanged(4, index);
}

void MainWindow::on_band5_ColorSel_currentIndexChanged(int index)
{
    resVal.tolChg(tolValPI[index]); //Changes the current tolerance value

    //Sets the currently selected band color
    ui->BAND_5->setStyleSheet("background-color:" + ui->band5_ColorSel->itemText(index) + ";");

    colorChanged(5, index);
}

void MainWindow::on_band6_ColorSel_currentIndexChanged(int index)
{
    resVal.tempCoefChg(tcValPI[index]);

    //Sets the currently selected band color
    ui->BAND_6->setStyleSheet("background-color:" + ui->band6_ColorSel->itemText(index) + ";");

    colorChanged(6, index);
}



void MainWindow::on_NBand_slider_valueChanged(int value)
{
    switch (value)
    {
      case 6:
        ui->BAND_6->show(); //Shows the 6th band
         //Shows the 6th band's data
        ui->tempCoefVal_frame->show();
        ui->Band6_frame->show();

        ui->BAND_5->show(); //Shows the 5th band
        ui->Band5_frame->show(); //Shows the 5th band's data
        ui->band5_ColorSel->clear(); //Clears the 5th band's color indexes
        ui->band5_ColorSel->addItems(TOL_COLORS); //Sets the 5th band's color indexes

        ui->BAND_4->show(); //Shows the 4th band
        ui->Band4_frame->show(); //Shows the 4th band's data
        ui->band4_ColorSel->clear(); //Clears the 4th band's color indexes
        ui->band4_ColorSel->addItems(MULT_COLORS); //Sets the 4th band's color indexes

        ui->band3_ColorSel->clear(); //Clears the 3rd band's color indexes
        ui->band3_ColorSel->addItems(SIG_COLORS); //Sets the 3rd band's color indexes

        break;

      case 5:
        ui->BAND_6->hide(); //Hides the 6th band
        //Hides the 6th band's data
        ui->tempCoefVal_frame->hide();
        ui->Band6_frame->hide();

        ui->BAND_5->show(); //Shows the 5th band
        ui->Band5_frame->show(); //Shows the 5th band's data
        ui->band5_ColorSel->clear(); //Clears the 5th band's color indexes
        ui->band5_ColorSel->addItems(TOL_COLORS); //Sets the 5th band's color indexes

        ui->BAND_4->show(); //Shows the 4th band
        ui->Band4_frame->show(); //Shows the 4th band's data
        ui->band4_ColorSel->clear(); //Clears the 4th band's color indexes
        ui->band4_ColorSel->addItems(MULT_COLORS); //Sets the 4th band's color indexes

        ui->band3_ColorSel->clear(); //Clears the 3rd band's color indexes
        ui->band3_ColorSel->addItems(SIG_COLORS); //Sets the 3rd band's color indexes

        break;

      case 4:
        ui->BAND_6->hide(); //Hides the 6th band
        //Hides the 6th band's data
        ui->tempCoefVal_frame->hide();
        ui->Band6_frame->hide();

        ui->BAND_5->hide(); //Hides the 5th band
        ui->Band5_frame->hide(); //Hides the 5th band's data

        ui->BAND_4->show(); //Shows the 4th band
        ui->Band4_frame->show(); //Shows the 4th band's data
        ui->band4_ColorSel->clear(); //Clears the 4th band's color indexes
        ui->band4_ColorSel->addItems(TOL_COLORS); //Sets the 4th band's color indexes

        ui->band3_ColorSel->clear(); //Clears the 3rd band's color indexes
        ui->band3_ColorSel->addItems(MULT_COLORS); //Sets the 3rd band's color indexes

        break;

      default:
        ui->BAND_6->hide(); //Hides the 6th band
        //Hides the 6th band's data
        ui->tempCoefVal_frame->hide();
        ui->Band6_frame->hide();

        ui->BAND_5->hide(); //Hides the 5th band
        ui->Band5_frame->hide(); //Hides the 5th band's data

        ui->BAND_4->hide(); //Hides the 4th band
        ui->Band4_frame->hide(); //Hides the 4th band's data
        resVal.tolChg(20); //Changes the tolerance to 20%

        ui->band3_ColorSel->clear(); //Clears the 3rd band's color indexes
        ui->band3_ColorSel->addItems(MULT_COLORS); //Sets the 3rd band's color indexes

        break;
    };
}
