#include "mainwindow.h"
#include "resval.h"
#include "ui_ResCalc.h"

void MainWindow::resValDispChanged(float r)
{
    int i;

    //Detects the first digit from right to left
    r *= 100;
    for(i=-2; ((int)r % 10) != 0 || i > 9; i++)
            r /= 10;

    //Checks if the introduced value is valid
    if ((ui->NBand_slider->value() > 4 && r > 999) || (ui->NBand_slider->value() < 5 && r > 99))
        return;

    resVal.signifChg(r); //changes the value of the significant value
    resVal.multChg(i); //changes the value of the multiplier

    valueChanged(); //Updates screen
}
