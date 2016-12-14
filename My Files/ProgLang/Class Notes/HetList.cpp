/*
 * hlist.cpp
 *
 * Program to show:
 *    1.  base and derived classes
 *    2.  heterogeneous linked list (store different objects in one l.l.)
 *    3.  use of virtual functions
 *
 * The program creates a list of vehicles of different types.  A virtual
 * "display" function will display the information of a particular object
 * in a list, depending on what object the pointer is pointing to.
 */

#include<iostream>
using namespace std;

// base class
class vehicles {
protected: 
   vehicles* next;
public:
   vehicles () {next = NULL;}
   void set_next (vehicles* nxt) {next = nxt;}
   virtual void display()=0;   // pure virtual function - only placeholder
                               // for "real" functions in derived classes
   vehicles* get_next() {return next;}
};

// derived class
class cars : public vehicles {
   string name;
   int hp;
public:
   cars(string n, int h) {name = n; hp = h;}
   void display();
};

// another derived class
class bikes : public vehicles {
   string name;
   int gears;
public:
   bikes(string n, int g) {name = n; gears = g;}
   void display();
};


// ***********************************************************//


void cars :: display ()
{
   cout << "CAR\n";
   cout << "Name: " << name << endl;
   cout << "Hp:   " << hp << endl;
   cout << endl;
}

void bikes :: display()
{
   cout << "BIKE\n";
   cout << "Name: " << name << endl;
   cout << "Gears: " << gears << endl;
   cout << endl;
}


// ***********************************************************//


int main()
{
   vehicles* list;             // create a linked list
   vehicles* ptr;              // pointer for later use
   cars mine ("Mini", 180);    // set up two cars
   cars hers ("Ferrari", 420); // (remember that base constructor is
                               //  also called)
   bikes jen ("Trek", 21);     // set up a bike

   list = &mine;               // start a linked list
   mine.set_next (&hers);      // add a car to it
   hers.set_next (&jen);       // add a bike to it

   ptr = list;
   while (ptr){                // go through the linked list
      ptr->display();          // use virtual function to display
                               // appropriate object
      ptr=ptr->get_next();     // go to next item on list
   }
   
   return 0;
}