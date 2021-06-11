#include "Fraction.h"
#include <iostream>
#include<cstdlib>
#include<math.h>

using namespace std;

istream& operator >>(istream &in,Fraction &obj)
    {
        obj.numerator=0;
        obj.denominator=0;
        string number;  bool bol=false;
        in>>number;

        if(number[number.length()/2]=='/')
        {
            for(int v=0;v<number.length()/2;v++)
            {
                obj.numerator+=((int)number[v]-48)*pow(10,number.length()/2-v-1);
            }

            int po=number.length()-number.length()/2-2;
            for(int v=number.length()/2+1;v<number.length();v++)
            {
                obj.denominator+=((int)number[v]-48)*pow(10,po--);
            }

            bol=true;
        }

        else{
        for(unsigned int i=0;i<number.length();i++)
        {
            if(number[i]=='/')
            {
                for(int v=0;v<i;v++)
                {
                    obj.numerator+=((int)number[v]-48)*pow(10,i-v-1);

                }

                int po=number.length()-i-2;
                for(int v=i+1;v<number.length();v++)
                {
                    obj.denominator+=((int)number[v]-48)*pow(10,po--);
                }

                bol=true;
                break;
            }
        }}
        if(bol==0)
        {
            for(int i=0;i<number.length();i++)
            {
                obj.numerator+=((int)number[i]-48)*pow(10,number.length()-i-1);
                obj.denominator=1;
            }
        }

        return in;
    }

ostream &operator <<(ostream &out,Fraction const &obj)
    {
        if (obj.denominator==1)
        {
            out<<obj.numerator;
        }

        else if(obj.numerator==0)
            out<<0;

        else if(obj.numerator<0||obj.denominator<0)
        {
            cout<<"-( "<<abs(obj.numerator)<<" / "<<abs(obj.denominator)<<" )";
        }

        else if(obj.denominator==0)
            cout <<"error dividing by 0";

        else
        {
        out<<obj.numerator;
        cout<<" / ";
        out<<obj.denominator;
        }
        return out;
    }

Fraction Fraction:: simplify(Fraction& obj)
    {
        if (obj.numerator==0)
        {
             obj.numerator=0;
             return obj;
        }

        else if(obj.denominator==0)
        {
             cout <<"error dividing by 0";
             return obj;
        }

        int common=obj.denominator%obj.numerator;

        if (common==0)
            {
                if(obj.denominator>obj.numerator)
                {
                    obj.denominator/=obj.numerator;
                    obj.numerator=1;
                }
                else
                {
                    obj.numerator/=obj.denominator;     obj.denominator=1;
                }
            }

        else{
             if(obj.denominator%common!=0||obj.numerator%common!=0)
            {
                float frc;  frc=(float)float(obj.numerator)/(float)obj.denominator;
                float tempD=obj.denominator*frc,       tempN=obj.numerator*frc;

                if((tempD==(int)tempD) &&(tempN==(int)tempN) )
                {
                    obj.denominator*=frc;        obj.numerator*=frc;
                }

                else
                {
                    return obj;
                }
                simplify(obj);
            }
            else{
                obj.denominator=obj.denominator/common;       obj.numerator=obj.numerator/common;}
        }

        return obj;
    }

Fraction Fraction:: operator +(Fraction obj)
    {
        Fraction frac;
        frac.denominator=denominator*obj.denominator;
        frac.numerator =(numerator*obj.denominator)+(obj.numerator*denominator);

        simplify(frac);
        return frac;
    }

Fraction Fraction:: operator -(Fraction obj)
    {
        Fraction frac;
        frac.denominator=denominator*obj.denominator;
        frac.numerator =(numerator*obj.denominator)-(obj.numerator*denominator);

        simplify(frac);
        return frac;
    }

Fraction Fraction:: operator *(Fraction obj)
    {
        Fraction frac;
        frac.denominator=this->denominator*obj.denominator;
        frac.numerator=this->numerator*obj.numerator;

        simplify(frac);
        return frac;
    }

Fraction Fraction:: operator /(Fraction obj)
    {
        Fraction frac;
        frac.denominator=this->denominator*obj.numerator;
        frac.numerator=this->numerator*obj.denominator;

        simplify(frac);
        return frac;
    }

bool Fraction:: operator >(Fraction obj)
    {
        float frac1=(float)numerator/denominator,  frac2=(float)obj.numerator/obj.denominator;

        if (frac1>frac2)
            return true;
        else return false;
    }

bool Fraction:: operator >=(Fraction obj)
    {
        float frac1=(float)this->numerator/this->denominator,  frac2=(float)obj.numerator/obj.denominator;
        if (frac1>=frac2)
            return true;
        else return false;
    }

bool Fraction:: operator <(Fraction obj)
    {
        float frac1=(float)this->numerator/this->denominator,  frac2=(float)obj.numerator/obj.denominator;
        if (frac1<frac2)
            return true;
        else return false;
    }

bool Fraction:: operator <=(Fraction obj)
    {
        float frac1=(float)this->numerator/this->denominator,  frac2=(float)obj.numerator/obj.denominator;
        if (frac1<=frac2)
            return true;
        else return false;
    }

bool Fraction:: operator ==(Fraction obj)
    {
        float frac1=(float)this->numerator/this->denominator,  frac2=(float)obj.numerator/obj.denominator;
        if (frac1==frac2)
            return true;
        else return false;
    }

