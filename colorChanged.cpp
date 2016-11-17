#include "mainwindow.h"
#include "resval.h"
#include "ui_ResCalc.h"

void MainWindow::colorChanged(int band, int index)
{
    float res = resVal.resGet(); //Holds the resistance value
    int nBands = ui->NBand_slider->value(); //Holds the number of bands currently in use

    if (band < 4 || (band == 4 && nBands > 4))
    {
        //Updates the resistance values in the screen
        if (res >= 1000000000)
        {
            ui->resValDisp->setValue(res /= 1000000000); //Sets the value of the resistor
            ui->resValDispMult->setCurrentIndex(3); //Sets the multiple in Ohms
        }
        else if (res >= 1000000)
        {
            ui->resValDisp->setValue(res /= 1000000); //Sets the value of the resistor
            ui->resValDispMult->setCurrentIndex(2); //Sets the multiple in Ohms
        }
        else if (res >= 1000)
        {
            ui->resValDisp->setValue(res /= 1000); //Sets the value of the resistor
            ui->resValDispMult->setCurrentIndex(1); //Sets the multiple in Ohms
        }
        else
        {
            ui->resValDisp->setValue(res); //Sets the value of the resistor
            ui->resValDispMult->setCurrentIndex(0); //Sets the multiple in Ohms
        }
    }
    else if ((band == 4 && nBands < 5) || (band == 5 && nBands > 4))
    {
        ui->tolValDisp->setValue(resVal.tolGet()); //Updates the tolerance value
    }
    else if (band == 6)
    {
        ui->tCoefValDisp->setValue(resVal.tempCoefGet()); //Updates the temperature coeficient value
    }

}
