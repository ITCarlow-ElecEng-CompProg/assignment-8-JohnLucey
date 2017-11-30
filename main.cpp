
/*
Operational Amplifier
Author John Lucey
Created on 6/11/17
Last Edited on 6/11/17
*/

//Pre-processor directives
#include <math.h>
#include <iostream>
using namespace std;

//Main Function
int main()
{
    //Function Prototypes
    void inv_amp(double, double, double, double, double, double *, double *);
    void non_inv_amp(double, double, double, double, double, double *, double *);
    char menu(void);

    //Variable declared
    char input;
    double Vcc = 0, Vee = 0, Vin = 0,Rin = 0,Rf = 0,r1, r2, Av, Vout;
    double *ptr_Av, *ptr_Vout;

    ptr_Av = &Av;
    ptr_Vout = &Vout




    //Explains program to user
    cout << "Ampifier Output Voltage & Voltage Gain Calculator! \n\n" << endl;

    //Do while loop to ensure the user is looped until 'q' is selected
    do
    {
        //Menu Options diplayed using function
        input = menu();

        //Switch case statement to invoke functions or exit loop
        switch (input)
        {
           case 'a':
                    cout<<"Inverting Amp Calculation : \n\n"<<endl;
                    while ((Rin<=0)||(Rf<=0))
                    {
                         cout << "Enter a Value Greater than 0 for Rin :" << endl;
                         cin >> Rin;
                         cout << "Enter a Value Greater than 0 for Rf :" << endl;
                         cin >> Rf;
                    }
                    cout << "Enter a Value for Vcc :" << endl;
                    cin >> Vcc;
                    cout << "Enter a Value for Vee :" << endl;
                    cin >> Vee;
                    cout << "Enter a Value for Vin :" << endl;
                    cin >> Vin;

                    inv_amp(Vcc, Vee, Vin, Rin, Rf, ptr_Av, ptr_Vout);
                    cout<<" Av =  " << *ptr_Av <<
                          " \n\n Vout = " << *Vout <<endl;
                    break;
          case 'b':
                    cout<<"Inverting Amp Calculation : \n\n"<<endl;
                    while ((r1<=0)||(r2<=0))
                    {
                         cout << "Enter a Value Greater than 0 for R1 :" << endl;
                         cin >> r1;
                         cout << "Enter a Value Greater than 0 for R2 :" << endl;
                         cin >> r2;
                    }
                    cout << "Enter a Value for Vcc :" << endl;
                    cin >> Vcc;
                    cout << "Enter a Value for Vee :" << endl;
                    cin >> Vee;
                    cout << "Enter a Value for Vin :" << endl;
                    cin >> Vin;

                    non_inv_amp(Vcc, Vee, Vin, r1, r2, ptr_Av, ptr_Vout);
                    cout<<" Av =  " << *ptr_Av <<
                          " \n\n Vout = " << *Vout <<endl;
                    break;
          case 'q': cout<<" Goodbye!!!!!!!!! "<<endl;
                    break;
          default : cout<<" Please try again"<<endl;

        }

    }
    //Do while loop condition
    while (input != 'q');
    //nil return of main function
    return 0;
}

//polar to cartesian calculation function
void inv_amp(double Vcc, double Vee, double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout);
{
    //variables declared
    double Av, Vout;

    Av = -1 * (Rf/Rin);
    Vout = Av * Vin;
    *ptr_Av = Av
    *ptr_Vout = Vout

    return ;
}

//Cartisian to polar calulation function
void void non_inv_amp(double Vcc, double Vee, double Vin, double r1, double r2, double *ptr_Av*, double *ptr_Vout*);
{
  //variables declared
    double Av, Vout;

    Av = 1 + (r2/r1);
    Vout = Av * Vin;
    *ptr_Av = Av
    *ptr_Vout = Vout
    return ;
}

char menu(void)
{
    char userChoice;

    cout << "\n Choose from the following options: \n" <<
              "\n Press a to Calculate Voltage Gain & Output Voltage of an Inverting Amplifier\n" <<
              "\n Press b to Calculate Voltage Gain & Output Voltage of a Non-Inverting Amplifier\n" <<
              "\n Press q to quit\n\n" << endl;
    cin >> userChoice;

    return userChoice;
}
