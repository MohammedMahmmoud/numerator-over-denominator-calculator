#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using namespace std;

class Fraction
{

private:
    int numerator,denominator ;

public:

    friend istream & operator >>(istream &in,Fraction &obj);
    friend ostream & operator <<(ostream &out,Fraction const &obj);
    Fraction simplify(Fraction &frac);
    Fraction operator +(Fraction obj);
    Fraction operator -(Fraction obj);
    Fraction operator *(Fraction obj);
    Fraction operator /(Fraction obj);

    bool operator >(Fraction obj);
    bool operator >=(Fraction obj);
    bool operator <(Fraction obj);
    bool operator <=(Fraction obj);
    bool operator ==(Fraction obj);

};

#endif // FRACTION_H
