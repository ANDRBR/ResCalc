#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <QMessageBox>
#include "resval.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_band1_ColorSel_currentIndexChanged(int index);

    void on_band2_ColorSel_currentIndexChanged(int index);

    void on_band3_ColorSel_currentIndexChanged(int index);

    void on_band4_ColorSel_currentIndexChanged(int index);

    void on_band5_ColorSel_currentIndexChanged(int index);

    void on_band6_ColorSel_currentIndexChanged(int index);

    void on_NBand_slider_valueChanged(int value);

    void on_resValDisp_editingFinished();

    void on_tolValDisp_editingFinished();

    void on_tCoefValDisp_editingFinished();

    void on_resValDispMult_editingFinished();

private:
    Ui::MainWindow *ui;

    void colorChanged(int band); //Function to update the screen when colors have changed
    bool isResValid(); //Function to test if a written resistance is valid

    ResVal resVal;
    QMessageBox* msgDialog = new QMessageBox();
    QErrorMessage* errorDialog = new QErrorMessage();

    const QStringList SIG_COLORS = (QStringList() << "Black" << "Brown" << "Red" << "Orange" << "Yellow" << "Green" << "Blue" << "Violet" << "Grey" << "White");
    const QStringList MULT_COLORS = (QStringList() << "Silver" << "Gold" << "Black" << "Brown" << "Red" << "Orange" << "Yellow" << "Green" << "Blue" << "Violet");
    const QStringList TOL_COLORS = (QStringList() << "Silver" << "Gold" << "Brown" << "Red" << "Green" << "Blue" << "Violet");
    const QStringList TC_COLORS = (QStringList() << "Black" << "Brown" << "Red" << "Orange" << "Yellow" << "Green" << "Blue" << "Violet" << "Grey");
    const QStringList OHM_MULT = (QStringList() << "Ohm" << "kOhm" << "MOhm" << "GOhm");

    const float tolValPI[7] = {10, 5, 1, 2, 0.5, 0.25, 0.1}; //Tolerance values per index(in band selector)
    const int tcValPI[9] = {250, 100, 50, 15, 25, 20, 10, 5, 1}; //Temperature coeficient values per index(in band selector)

};

#endif // MAINWINDOW_H
