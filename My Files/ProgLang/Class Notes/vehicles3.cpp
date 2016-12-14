/*
 * Joe Schmoe
 * vehicles3.cpp
 *
 * Description: Sample program showing C++ inheritance
 *              Final version.
 */

using namespace std;
#include<iostream>

enum environType {LAND, SEA, AIR};

int IDcount = 0;		// automatic ID counter

class vehicle {
protected:
   int id;			// numeric ID for this vehicle
   int numPassengers;		// number of passengers
   int topSpeed;
   environType environment;	// land, sea, or air?

public:
   vehicle ();
   void displayPassengers () {cout << "Passengers : " 
                              << numPassengers << endl;}
};

vehicle :: vehicle () {
   IDcount++; 			// update vehicle ID counter
   id = IDcount; 		// set this vehicle's ID
   cout << "Passengers for vehicle " << id << "? ";
   cin >> numPassengers;
}

/**********************************************/

class motorized : public vehicle {
protected:  
   int bhp;		// brake horsepower
   string fuel;		// type of fuel
   int range;		// range in miles
public:
   motorized ();
   motorized (int b, string f, int r, int t) {
      bhp = b; fuel = f; range = r; topSpeed = t;}
   void display ();
};

motorized :: motorized () {
// Constructor to ...
   cout << "Enter data for vehicle " << id << endl;
   cout << "Horsepower? ";
   cin >> bhp;
   cout << "Fuel type? ";
   cin >> fuel;
   cout << "Top speed? ";
   cin >> topSpeed;
}

void motorized :: display () {
// Display ...
   cout << "Data for vehicle " << id << endl;
   cout << "Horsepower : " << bhp << endl;
   cout << "Fuel type  : " << fuel << endl;
   cout << "Top speed  : " << topSpeed << endl;
   displayPassengers ();
}

/**********************************************/

class wheeled : public motorized {
public:
   wheeled () {environment = LAND;}
   void display ();
};

void wheeled :: display () {
   motorized :: display ();
   cout << "Environtype: " ;
   switch (environment) {
	case AIR  : cout << "air" << endl;
		  break;
	case LAND : cout << "land" << endl;
		  break;
	case SEA  : cout << "sea" << endl;
   };
}

/**********************************************/

class nonmotorized : public vehicle {
protected:
   string howPowered;
public:
   nonmotorized ();
   void display ();
};

nonmotorized :: nonmotorized () {
   cout << "Enter data for vehicle " << id << endl;
   cout << "How powered? ";
   cin >> howPowered;
   cout << "Top speed? ";
   cin >> topSpeed;
}

void nonmotorized :: display () {
   cout << "Data for vehicle " << id << endl;
   cout << "How powered: " << howPowered << endl;
   cout << "Top speed  : " << topSpeed << endl;
   displayPassengers ();
}

/**********************************************/
   
int main () {
   motorized bus (235, "diesel", 500, 81);	// vehicle 1
   nonmotorized sailboat;			// vehicle 2
   wheeled car;					// vehicle 3
   
   cout << endl << "Output:" << endl;
   bus.display ();
   cout << endl;
   sailboat.display ();
   cout << endl;
   car.display ();

   return 0;
}
