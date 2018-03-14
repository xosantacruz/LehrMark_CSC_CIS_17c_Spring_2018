/* 
 * Author: Dr. Mark E. Lehr
 * Created on September 21st, 2017 8:40 Pm
 * Purpose:  Structure ADT for the Link
 */

#ifndef LINK_H
#define LINK_H

//Composition of a Link
struct Link{
    int data;		//Any integer data, to be changed any class with templates later
    Link *linkPtr;  //Self Reference which when utilized forms a linked list
};


#endif /* LINK_H */

