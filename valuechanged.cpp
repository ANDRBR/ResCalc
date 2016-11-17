#include "mainwindow.h"
#include "resval.h"
#include "ui_ResCalc.h"

void MainWindow::valueChanged()
{
    int signif = resVal.signifGet(); //holds the significant value
    int sig[3] = {0}; //holds each digit of the significant value
    int i, j;

    //Changes the temperature coeficient band's color
    for (i=0; i<9; i++){
        if (tcValPI[i] == resVal.tempCoefGet())
        {
            ui->band6_ColorSel->setCurrentIndex(i);
            colorChanged(6, i);
            break;
        }
    }

    //Changes the tolerance band's color
    for (i=0; i<9; i++){
        if (tolValPI[i] == resVal.tolGet())
        {
            if (ui->NBand_slider->value() > 4)
            {
                ui->band5_ColorSel->setCurrentIndex(i);
                colorChanged(5, i);
            }
            else
            {
                ui->band4_ColorSel->setCurrentIndex(i);
                colorChanged(4, i);
            }
            break;
        }
    }

    //Changes the multiplier band's color
    if (ui->NBand_slider->value() > 4)
    {
        ui->band4_ColorSel->setCurrentIndex(i);
        colorChanged(4, i);
    }
    else
    {
        ui->band3_ColorSel->setCurrentIndex(i);
        colorChanged(3, i);
    }


    //Separates the digits in the significant value
    for (i=100, j=2; i > 0; i /= 10, j--)
    {
        sig[j] = signif / i;
        signif %= i;
    }

    //Changes the significant value band's colors
    if (ui->NBand_slider->value() > 4)
    {
        ui->band3_ColorSel->setCurrentIndex(sig[2]);
        colorChanged(3, sig[2]);
        ui->band2_ColorSel->setCurrentIndex(sig[2]);
        colorChanged(2, sig[1]);
        ui->band1_ColorSel->setCurrentIndex(sig[2]);
        colorChanged(1, sig[0]);
    }
    else
    {
        ui->band2_ColorSel->setCurrentIndex(sig[2]);
        colorChanged(2, sig[1]);
        ui->band1_ColorSel->setCurrentIndex(sig[2]);
        colorChanged(1, sig[0]);
    }

}
