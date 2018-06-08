#include <iostream>

#include <string>

#include "function.h"

using namespace std;

class OWList;
class TWList;



    //default constructor

    OWList::OWList()
    {
        firstPtr=0;
        lastPtr=0;
    }

    //destructor

    OWList::~OWList()
    {

    }

    //insert node at front of list

    void OWList::insertAtFront( const int &value )
    {
        ListNode *tmp;
        tmp = firstPtr;
        firstPtr = new ListNode(value);
        if(tmp==0)
            lastPtr = firstPtr;
        firstPtr->nextPtr=tmp;
      //  firstPtr->data=value;
    }

    //remove node from front of list

    void OWList::removeFromFront()
    {
        ListNode *tmp;
        tmp = firstPtr;
                if(tmp==0)
        {
            return ;
        }
        if(tmp->nextPtr!=0)
        {

        firstPtr=firstPtr->nextPtr;
         delete tmp;
        }
         else
        {

        firstPtr=0;
        lastPtr=0;
         delete tmp;
        }

    }

    //is List empty?

    bool OWList::isEmpty() const
    {

    }

    //display contents of List

    void OWList::print() const
    {
        ListNode *tmp=firstPtr;
        while(tmp!=0)
        {
            if(tmp->nextPtr!=0)
            {
                cout<<tmp->data<<' ';

            }
            else
                cout<<tmp->data;
            tmp=tmp->nextPtr;
        }
    }

 // end class OWList




    //default constructor

  /*  TWList::TWList()

    :OWList()

    {

        /*It will still work correctly if you omit the constructor call of the base

          class in the above member initializer list. The compiler will invoke this

          default constructor of OWList implicitly.*/

  //  }


    //destructor

//    TWList::~TWList()

   // {

        /*You don't need to delete the list again because the compiler

          will invoke the destructor of the base class OWList to do this.*/

   // }

    //insert node at back of list

    void TWList::insertAtBack( const int &value )
    {
        ListNode *tmp;
        tmp = lastPtr;



        lastPtr = new ListNode(value);

        if(tmp==0)
            firstPtr = lastPtr;
        if(tmp!=0)

        tmp->nextPtr=lastPtr;
      //  lastPtr->data=value;
    }

    //delete node from back of list

    void TWList::removeFromBack()
    {
        ListNode *tmp,*tmp2;
        tmp = firstPtr;
        tmp2=tmp;
        if(tmp==0)
        {
            return ;
        }

        while(tmp->nextPtr!=0)
        {
            tmp2 = tmp;
            tmp=tmp->nextPtr;
        }

        delete lastPtr;
        if(lastPtr==tmp2)
           {
               lastPtr=0;
               firstPtr=0;
           }
        else{
        lastPtr=tmp2;
        lastPtr->nextPtr = 0;}

    }
