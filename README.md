# -10587---List-

https://acm.cs.nthu.edu.tw/problem/10587/

Description

Let’s implement a list class.

    Task 1:

First you are asked to implement class OWList (standing for “one-way list”). You have definitions of classes ListNode and OWList as follows:

         class ListNode
         {
                friend class OWList; //make OWList a friend
                friend class TWList; //make TWList a friend

          public:
                ListNode( const int &info ) //constructor
                : data( info ), nextPtr( NULL )
                {
                } //end ListNode constructor

           private:
               int data; //data
               ListNode *nextPtr; // next node in list

           }; //end class ListNode

           class OWList
           {
           public:
                //default constructor
                OWList();
                //destructor
                ~OWList();
                //insert node at front of list
                void insertAtFront( const int &value );
                //remove node from front of list
                void removeFromFront();
                //is List empty?
                bool isEmpty() const;
                //display contents of List
                void print() const;

            protected:
                ListNode *firstPtr; //pointer to first node
                ListNode *lastPtr;  //pointer to last node
             }; // end class OWList

            Requirement: Implement the member functions

             1. “OWList::OWList();”: initializes the two pointers firstPtr and lastPtr as NULL.

             2. “OWList::~OWList();”: deletes allocated dynamic memory space.

             3. “void OWList::insertAtFront( const int &value );”

             4. “int OWList::removeFromFront();”

             5. “bool OWList::isEmpty() const;”

             6. “void OWList::print() const;”

    Task 2:

Implement another class TWList (standing for “two-way list”), which is derived from class OWList:

        class TWList:public OWList
        {
        public:
             //default constructor
             TWList()
             :OWList()
              {
                    /*It will still work correctly if you omit the constructor call of the base class in the above member                            initializer list. The compiler will invoke this default constructor of OWList implicitly.*/
              }
              //destructor
              ~TWList()
              {
                     /*You don't need to delete the list again because the

                        compiler will invoke the destructor of the base class OWList to do this.*/
              }
              //insert node at back of list
             void insertAtBack( const int &value );
              //delete node from back of list
             void removeFromBack();

          };

            Besides the functions inherited from OWList, TWList has two more functions: insert a node at the end of             the list and remove a node from the end of the list.

           Requirement: Implement the member functions

            7. “void TWList:: insertAtBack( const int &value );”

          8.“int TWList:: removeFromBack();”

Note:

1.      This problem involves three files.

    function.h: Class definitions.
    function.cpp: Member-function definitions.
    main.cpp: A driver program to test your class implementation.

You will be provided with main.cpp and function.h, and asked to implement function.cpp.
function.h

#ifndef FUNCTION_H

#define FUNCTION_H

#include <iostream>

class ListNode

{

    friend class OWList; //make OWList a friend

    friend class TWList; //make TWList a friend

 

public:

    ListNode( const int &info ) //constructor

    : data( info ), nextPtr( NULL )

    {

    } //end ListNode constructor

 

private:

    int data; //data

    ListNode *nextPtr; // next node in list

}; //end class ListNode

 

 

class OWList

{

public:

    //default constructor

    OWList();

    //destructor

    ~OWList();

    //insert node at front of list

    void insertAtFront( const int &value );

    //remove node from front of list

    void removeFromFront();

    //is List empty?

    bool isEmpty() const;

    //display contents of List

    void print() const;

 

protected:

    ListNode *firstPtr; //pointer to first node

    ListNode *lastPtr;  //pointer to last node

 

}; // end class OWList

 

class TWList:public OWList

{

public:

    //default constructor

    TWList()

    :OWList()

    {

        /*It will still work correctly if you omit the constructor call of the base

          class in the above member initializer list. The compiler will invoke this

          default constructor of OWList implicitly.*/

    }

    //destructor

    ~TWList()

    {

        /*You don't need to delete the list again because the compiler

          will invoke the destructor of the base class OWList to do this.*/

    }

    //insert node at back of list

    void insertAtBack( const int &value );

    //delete node from back of list

    void removeFromBack();

};

#endif
main.cpp

#include <iostream>

#include <string>

#include "function.h"

using namespace std;

int main()

{

    TWList integerList;

    int command;

    int value; // store node value

 

    while (cin >> command)

    {

        switch(command)

        {

        case 1: // insert at beginning

            cin >> value;

            integerList.insertAtFront(value);

            break;

        case 2: // insert at end

            cin >> value;

            integerList.insertAtBack(value);

            break;

        case 3: // remove from beginning

            integerList.removeFromFront();

            break;

        case 4: // remove from end

            integerList.removeFromBack();

            break;

        }

    }

    integerList.print();

    cout<<endl;

}

2.      For OJ submission:

        Step 1. Submit only your function.cpp into the submission block.

        Step 2. Check the results and debug your program if necessary.

 
Input

There are four types of command:

    “1 integerA” represents inserting a node with int value A at the head of the list.
    “2 integerB” represents inserting a node with int value B at the end of the list.
    “3” represents removing the node at the head of the list
    “4” represents removing the node at the end of the list

Each command is followed by a new line character.

Input terminated by EOF.
Output

The output should consist of the final state of the list. 
