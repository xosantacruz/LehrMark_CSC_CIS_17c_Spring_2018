/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 14th, 2018, 7:40 AM
 * Purpose:  Develop a 2D Array structure
 *     with potential future for different #cols per row
 */

//System Libraries Here
#include <iostream>  //I/O stream library
#include <cstdlib>   //Random number function
#include <ctime>    //Time to set random seed
using namespace std;

//User Libraries Here
#include "Struct2D.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Array2D *filStrc(int,int);
void prtStrc(Array2D *);
void destroy(Array2D *);
void mrkSort(Array2D *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize the 2D Structure
    int rows=1600,cols=15;
    Array2D *x=filStrc(rows,cols);
            
    //Display the contents of the 2D Structure
    //prtStrc(x);
    
    //Sort a column of the array
    mrkSort(x,5);
    
    //Display the contents of the 2D Structure
    //prtStrc(x);
    
    //Destroy allocated memory
    destroy(x);

    //Exit
    return 0;
}

void mrkSort(Array2D *a,int col){
    int O=0,Oo=0,Oi=0,Of=0;
    O++;
    for(int i=0;i<a->rows-1;i++){
        Oo+=5;
        for(int j=i+1;j<a->rows;j++){
            Oi+=3;
            if(a->data[i][col]>a->data[j][col]){
                Of++;
                for(int k=0;k<a->cols;k++){
                    Of+=5;
                    int temp=a->data[i][k];
                    a->data[i][k]=a->data[j][k];
                    a->data[j][k]=temp;
                }
            }
        }
    }
    cout<<"Before Loop Operations = "<<O<<endl;
    cout<<"Outer Loop Operations  = "<<Oo<<endl;
    cout<<"Inner Loop Operations  = "<<Oi<<endl;
    cout<<"Swap Operations        = "<<Of<<endl;
    cout<<"The total Operations   = "<<O+Oo+Oi+Of<<endl;
}


void destroy(Array2D *array){
    //DeAllocate Memory for the 2D array Structure
    for(int i=0;i<array->rows;i++){
        delete []array->data[i];
    }
    delete []array->data;
    delete array;
}

void prtStrc(Array2D *a){
    //Display the Structure
    cout<<"Structure data array size => rows = "<<a->rows
            <<" cols = "<<a->cols<<endl<<endl;
    for(int i=0;i<a->rows;i++){
        for(int j=0;j<a->cols;j++){
            cout<<a->data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

Array2D *filStrc(int row,int col){
    //Declare Variables
    Array2D *array=new Array2D;
    //Fill my 2D array structure
    array->rows=row;
    array->cols=col;
    //Allocate Memory for the 2D array Structure
    array->data=new int*[array->rows];
    for(int i=0;i<array->rows;i++){
        array->data[i]=new int[col];
    }
    //Fill the memory array
    for(int i=0;i<array->rows;i++){
        for(int j=0;j<array->cols;j++){
            array->data[i][j]=rand();
        }
    }
    return array;
}