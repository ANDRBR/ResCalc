#ifndef RESVAL_H
#define RESVAL_H

class ResVal
{
private:
    enum resistance{significant=0, multiplier=1}; //Enum for each 'res' component
    int tempCoef, res[2]; //Temperature coeficient and resistantce value
    float tol; //Tolerance of the resistor

public:
    ResVal();
    void resChg(int rS, int rM, float t=20, int tc=250); //Modifies ALL the values for the resistance
    float resGet(); //Gets the resistance value

    void signifChg(int rS); //Modifies significant value of the resistance
    int signifGet();  //Gets the significant value of the resistance

    void multChg(int rM); //Modifies the multiplier value of the resistance
    int multGet();  //Gets the multiplier value of the resistance

    void tolChg(float t); //Modifies the tolerance value of the resistance
    float tolGet();  //Gets the tolerance value of the resistance

    void tempCoefChg(int tc); //Modifies the temperature coeficient value of the resistance
    int tempCoefGet();  //Gets the temperature coeficient value of the resistance
};

#endif // RESVAL_H
