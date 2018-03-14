//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 21st, 2018 8:40 PM
 * Purpose:  Linked List Template Version 2 - Procedures with ADT
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Link.h"

//Global Constants Only, No Global Variables

//Function Prototypes Here
Link<int> *fillLst(int);            //Fill a linked list, count backwards
void      prntLst(Link<int> *);     //Print each data element in the list
void      destLst(Link<int> *);     //Destroy the list/deallocate
Link<int> *endLst(Link<int> *);    //Find the end of the list
void       addLst(Link<int> *,int);  //Add data at the end of the list
int       findLst(Link<int> *,int); //Determine what link contains the data
Link<int> *fndLst(Link<int> *,int);//Determine address of link that contains the data
int        cntLst(Link<int> *);      //How many elements are in the list

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare a pointer to the linked list and data to test in link creation
    Link<int> *lnkList;
    int numList=8,valAdd=42,valFnd1=5,valFnd2=11;
    
    //Fill the linked list
    lnkList=fillLst(numList);
    
    //Print the entire list
    prntLst(lnkList);
    
    //Add a value to the end of the list
    addLst(lnkList,valAdd);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    //Find some values in the List
    cout<<valFnd1<<" is found at link    "<<findLst(lnkList,valFnd1)<<endl;
    cout<<valFnd1<<" is from the address where data = "
            <<fndLst(lnkList,valFnd1)->data<<endl;
    cout<<valFnd2<<" is found at link   "<<findLst(lnkList,valFnd2)<<endl;
    cout<<"The number of elements in the list = "<<cntLst(lnkList)<<endl;
    
    //Deallocate memory for the Link<int>ed List
    destLst(lnkList);
    
    //Exit
    return 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Create a linked list and fill with data
//Input  -> n      The number of elements in the list to create
//Output -> front  The address to the front of the allocated list.
Link<int> *fillLst(int n){
    //Think of this part as the constructor
    Link<int> *front=new Link<int>;//Allocate a link at the front of the list
    front->data=n;       //Initialize with data
    front->linkPtr=NULL; //At the moment not pointing it to anything
    Link<int> *next=front;    //Create a pointer to progress through the list

    //Fill the rest of the list with decreasing data down to 1
    n--;
    do{
       Link<int> *temp=new Link<int>; //Allocate a new link
       temp->data=n;        //Fill with data
       temp->linkPtr=NULL;  //Place at the end
       next->linkPtr=temp;  //Hook the new link to the end of the list
       next=temp;           //Move the pointer to the end
    }while(--n>0);          //Continue till you count down to Zero
    //Exit by return the original link pointer
    return front;           //Return the front pointer to the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Print the entire contents of the linked list
//Input -> front  The address to the front of the allocated list.
//Output-> Display the entire linked list.
void  prntLst(Link<int> *front){
    Link<int> *next=front;           //Create a pointer to the list
    cout<<endl<<"The Beginning of the List"<<endl;
    do{
        cout<<next->data<<endl; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
    }while(next!=NULL);         //Loop until reaching the end
    cout<<"The End of the List"<<endl<<endl;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Deallocate the entire list from the front to the end.
//Input -> front  The address to the front of the allocated list.
//Output-> Deallocate and return a NULL for the linked list pointer.
void  destLst(Link<int> *front){
    do{
       Link<int> *temp=front->linkPtr;   //Point to the next link in the list
       delete front;                //Delete the front of the list
       front=temp;                  //Swap the front
    }while(front!=NULL);
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the last link in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The address of the last link in the list
Link<int>  *endLst(Link<int> *front){
    Link<int> *temp=front,*next; //Declare pointers used to step through the list
    do{
        next=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
    return next;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Add a link and data to the end of the list
//Input -> front  The address to the front of the allocated list.
//         data   Data to embed at the last link in the list
void   addLst(Link<int> *front,int data){
    Link<int> *last=endLst(front);  //Find the last link
    Link<int> *add=new Link<int>;        //Create the new link
    add->data=data;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    last->linkPtr=add;         //Point to the new end of the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link<int> number from the front where the data is found
int   findLst(Link<int> *front,int value){
    int n=0;                //Initialize the counter
    Link<int> *temp=front;       //Prepare to traverse the Link<int>ed list
    do{
        n++;                //Increment the counter
        if(temp->data==value)return n;//Return where the data is found
        temp=temp->linkPtr; //Move to the next link
    }while(temp!=NULL);     //End when reaching the end of the linked list
    return 0;               //Not found then return a 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link<int> address from the front where the data is found
Link<int>  *fndLst(Link<int> *front,int value){
    Link<int> *temp=front;       //Set the cursor to move through the list
    do{
        if(temp->data==value)return temp;  //Address of data match
        temp=temp->linkPtr;                //Next link in the list
    }while(temp!=NULL);                    //End of the list
    return NULL;                           //Not found
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
int   cntLst(Link<int> *front){
    int n=0;            //Initialize the counter
    Link<int> *temp=front;   //Set the cursor to the front
    do{
        n++;            //Increment the counter
        temp=temp->linkPtr;//Move to the next link
    }while(temp!=NULL); //Loop until the end is reached
    return n;           //Return the counter value
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890