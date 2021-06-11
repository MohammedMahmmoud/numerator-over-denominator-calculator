#include<iostream>
#include<stdlib.h>
#include "FractionCalculator.h"
#include"Fraction.h"

using namespace std;

FractionCalculator::FractionCalculator()
{
    Fraction fraction1,fraction2;
    int choice;
    while(true)
    {
    cout<<"Welcome to FCI Fraction Calculator\n"
        <<"----------------------------------------\n"
        <<"1- Perform Fraction Addition\n"
        <<"2- Perform Fraction Subtraction\n"
        <<"3- Perform Fraction Multiplication\n"
        <<"4- Perform Fraction division\n"
        <<"5- perform Fraction Comparison\n"
        <<"6- Exit\n";
    cin>>choice;
    cout<<"enter the two fractions\n";
    cin>>fraction1;
    cin>>fraction2;

    switch(choice)
    {
    case 1:

        cout<<fraction1<<" + "<<fraction2<<" = ";
        cout<<fraction1+fraction2<<endl<<endl;
        break;

    case 2:

        cout<<fraction1<<" - "<<fraction2<<" = ";
        cout<<fraction1-fraction2<<endl<<endl;
        break;

    case 3:

        cout<<fraction1<<" * "<<fraction2<<" = ";
        cout<<fraction1*fraction2<<endl<<endl;
        break;

    case 4:

        cout<<"("<<fraction1<<") / ("<<fraction2<<") = ";
        cout<<fraction1/fraction2<<endl<<endl;
        break;

    case 5:
    {
    int opert;
        cout<<"\n\n1: "<<fraction1<<" > "<<fraction2<<" ?"<<endl
            <<"2: "<<fraction1<<" >= "<<fraction2<<" ?"<<endl
            <<"3: "<<fraction1<<" < "<<fraction2<<" ?"<<endl
            <<"4: "<<fraction1<<" <= "<<fraction2<<" ?"<<endl
            <<"5: "<<fraction1<<" = "<<fraction2<<" ?"<<endl
            <<"6: exit\n";

        cin>>opert;
        switch(opert)
        {
        case 1:
            if(fraction1>fraction2)
                cout<<"true"<<endl;
            else cout<<"false\n\n";

            break;

        case 2:
            if(fraction1>=fraction2)
                cout<<"true"<<endl;
            else cout<<"false\n\n";

            break;

        case 3:
            if(fraction1<fraction2)
                cout<<"true"<<endl;
            else cout<<"false\n\n";

            break;

        case 4:
            if(fraction1<=fraction2)
                cout<<"true"<<endl;
            else cout<<"false\n\n";

            break;

        case 5:
            if(fraction1==fraction2)
                cout<<"true"<<endl;
            else cout<<"false\n\n";

            break;

        case 6:
            break;
        }}
        break;

        case 6:
            exit(0);
        default:
            break;

        }
    }
}

