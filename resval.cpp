#include "resval.h"
#include <cmath>

ResVal::ResVal() //Establishes initial values for the variables
{
    res[significant]=1;
    res[multiplier]=0;
    tol=20;
    tempCoef=250;
}

void ResVal::resChg(int rS, int rM, float t, int tc)
{
    res[significant]=rS;
    res[multiplier]=rM;
    tol=t;
    tempCoef=tc;
}

float ResVal::resGet()
{
    return (res[significant] * pow(10, res[multiplier]));
}

void ResVal::signifChg(int rS)
{
    res[significant]=rS;
}

int ResVal::signifGet()
{
    return res[significant];
}

void ResVal::multChg(int rM)
{
    res[multiplier]=rM;
}

int ResVal::multGet()
{
    return res[multiplier];
}

void ResVal::tolChg(float t)
{
    tol=t;
}

float ResVal::tolGet()
{
    return tol;
}

void ResVal::tempCoefChg(int tc)
{
    tempCoef=tc;
}

int ResVal::tempCoefGet()
{
    return tempCoef;
}
