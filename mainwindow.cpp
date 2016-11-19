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

    colorChanged(1);
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

    colorChanged(2);
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

    colorChanged(3);
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

    colorChanged(4);
}

void MainWindow::on_band5_ColorSel_currentIndexChanged(int index)
{
    resVal.tolChg(tolValPI[index]); //Changes the current tolerance value

    //Sets the currently selected band color
    ui->BAND_5->setStyleSheet("background-color:" + ui->band5_ColorSel->itemText(index) + ";");

    colorChanged(5);
}

void MainWindow::on_band6_ColorSel_currentIndexChanged(int index)
{
    resVal.tempCoefChg(tcValPI[index]);

    //Sets the currently selected band color
    ui->BAND_6->setStyleSheet("background-color:" + ui->band6_ColorSel->itemText(index) + ";");

    colorChanged(6);
}

void MainWindow::on_NBand_slider_valueChanged(int value)
{
    switch (value)
    {
      case 6:
        ui->tolValDisp->setReadOnly(false); //sets this value as modifiable

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
        ui->tolValDisp->setReadOnly(false); //sets this value as modifiable

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
        ui->tolValDisp->setReadOnly(false); //sets this value as modifiable

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
        ui->tolValDisp->setValue(20);

        ui->band3_ColorSel->clear(); //Clears the 3rd band's color indexes
        ui->band3_ColorSel->addItems(MULT_COLORS); //Sets the 3rd band's color indexes

        ui->tolValDisp->setReadOnly(true); //sets this value as read only

        break;
    };
}

void MainWindow::on_resValDisp_editingFinished()
{
    float res = ui->resValDisp->value();

    //if the resistance value is invalid reset it and resume the program
    if(isResValid())
    {
        if (res >= 1000000000)
            ui->resValDisp->setValue(res /= 1000000000); //Sets the value of the resistor
        else if (res >= 1000000)
            ui->resValDisp->setValue(res /= 1000000); //Sets the value of the resistor
        else if (res >= 1000)
            ui->resValDisp->setValue(res /= 1000); //Sets the value of the resistor
        else
            ui->resValDisp->setValue(res); //Sets the value of the resistor
        return;
    }

    res *= 100;
    for(int i=-2; i<=9; i++, res /= 10)
    {
        if((int)res % 10  != 0) //Checks if the next digit is an int
        {
            resVal.signifChg(res);
            resVal.multChg(i);
            break;
        }
    }

    //Updates the color selectors
    if(ui->NBand_slider->value() > 4)
    {
        ui->band1_ColorSel->setCurrentIndex(resVal.signifGet() / 100);
        ui->band2_ColorSel->setCurrentIndex((resVal.signifGet() / 10) % 10);
        ui->band3_ColorSel->setCurrentIndex(resVal.signifGet() % 10);
        ui->band4_ColorSel->setCurrentIndex(resVal.multGet() + 2);
    }
    else
    {
        ui->band1_ColorSel->setCurrentIndex(resVal.signifGet() / 10);
        ui->band2_ColorSel->setCurrentIndex(resVal.signifGet() % 10);
        ui->band3_ColorSel->setCurrentIndex(resVal.multGet() + 2);
    }
}

void MainWindow::on_tolValDisp_editingFinished()
{
    int i;
    //Tests if the tolerance value is valid
    for(i=0; i<TOL_COLORS.size(); i++)
    {
        //if the value exists, change the stored value and update the screen
        if(tolValPI[i] == ui->tolValDisp->value())
        {
            resVal.tolChg(tolValPI[i]);
            if(ui->NBand_slider->value() > 4)
                ui->band5_ColorSel->setCurrentIndex(i);
            else
                ui->band4_ColorSel->setCurrentIndex(i);
            break;
        }
    }
    //if the value doesn't exists undo the modification
    if(i==TOL_COLORS.size()) ui->tolValDisp->setValue(resVal.tolGet());
}

void MainWindow::on_tCoefValDisp_editingFinished()
{
    int i;
    //Tests if the temperature coeficient value is valid
    for(i=0; i<TC_COLORS.size(); i++)
    {
        //if the value exists, change the stored value and update the screen
        if(tcValPI[i] == ui->tCoefValDisp->value())
        {
            resVal.tempCoefChg(tcValPI[i]);
            ui->band6_ColorSel->setCurrentIndex(i);
            break;
        }
    }
    //if the value doesn't exists undo the modification
    if(i==TC_COLORS.size()) ui->tCoefValDisp->setValue(resVal.tempCoefGet());
}

void MainWindow::on_resValDispMult_editingFinished()
{
    QString aux = ui->resValDispMult->text();
    float res = ui->resValDisp->value();
    int i;

    /*Checks if the introduced text is invalid:
     * doesn't contain the word "ohm"
     * doesn´t have a length <= 4
     * doesn't have a valid prefix
    */
    if(!(aux.contains("Ohm", Qt::CaseInsensitive) && (aux.length() <= 4 || res >= 1 ||
       (aux.length() == 4 && (aux.at(0) == 'k' || aux.at(0) == 'M' || aux.at(0) == 'G')))))
    {
        //Finds the current multiplier
        for(i=0; i <= 3; i++, res *= 1000)
        {
            if(resVal.resGet() == res)
            {
                ui->resValDispMult->setText(OHM_MULT.at(i));
                break;
            }
        }

        return;
    }

    //if "ohm" have a prefix, the corresponding multiplier is added
    if(aux.length() == 4)
    {
        switch (aux.at(0).unicode())
        {
        case 'k':
            res *= pow(10, 3);
            break;
        case 'M':
            res *= pow(10, 6);
            break;
        case 'G':
            res *= pow(10, 9);
            break;
        }
    }

    //Updates the multiplier value
    for(i=0; i<=9; i+=3)
    {
        if(resVal.resGet() * pow(10, i) == res)
        {
            resVal.multChg(resVal.multGet() + i);
            break;
        }
    }

    //Updates the color selectors
    if(ui->NBand_slider->value() > 4)
    {
        ui->band4_ColorSel->setCurrentIndex(i+2);
    }
    else
    {
        ui->band3_ColorSel->setCurrentIndex(i+2);
    }

}

//Function to test if a written resistance is valid
bool MainWindow::isResValid()
{
    float res = ui->resValDisp->value();
    int exp, i;

    if(ui->resValDisp->value() < 0.01) //Checks for the minimum value of resistance
        return false;

    //Checks the current value of the multiplier and stores the maximum value for the exponent
    if(ui->resValDispMult->text().compare("Ohm", Qt::CaseInsensitive) == 0) //if the multiple is "Ohm", exp = 9
        exp = 9;
    else
    {
        //Shearches for the value of the multiplier
        for(exp = 3, i=0; exp <= 9; exp += 3, i++)
        {
            if(ui->resValDispMult->text().compare(OHM_MULT.at(i), Qt::CaseInsensitive) == 0)
                break;
        }
        if(exp > 9) //if it didn't find the multiplier it returns false
            return false;

        exp = 9 - exp; //assigns the value of exp
    }

    //Checks for the maximum value it can have
    if(ui->NBand_slider->value() > 4 && res > 999 * pow(10, exp))
        return false;
    if(ui->NBand_slider->value() <= 4 && res > 99 * pow(10, exp))
        return false;

    //Tests if the number of significative digits is valid
    if (res < 1) res *= 100;
    for(int i=0; i<=9; i++, res /= 10)
    {
        if((int)res % 10  != 0) //Checks if the next digit is an int
        {
            if(ui->NBand_slider->value() > 4 && res > 999)
                return false;
            if(ui->NBand_slider->value() <= 4 && res > 99)
                return false;
            break;
        }
    }
    if(i>9) return false;

    //if it fullfills all the tests return true
    return true;
}
