/*Dr. Mark E. Lehr
  March 8th, 2018
  Purpose:  Curve fit of Data Structure empirical timing and/or
            operational analysis
*/
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries 
#include "mArray.h"

//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

//Execution begins here
int main(){
    //Declare the Row and Empirical Data files
    char fn_r[]="r.dat";
    mArray r(fn_r);
    char fn_f[]="f.dat";
    mArray f(fn_f);
    
    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt(false,r,0,r.getRows()-1,0,r.getCols()-1);
    mArray c=mArray::invMat(rt*r)*rt*f;
    
    //Output the results
    char fn_c[]="c.dat";
    c.mPrint(fn_c);
    
    return 0;
}