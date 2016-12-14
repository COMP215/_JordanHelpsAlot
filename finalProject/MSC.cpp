#ifndef MSC_h
#define MSC_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

class point{
public:
	double x_val;
	double y_val;
public:
	point();
	point(double x, double y);
};

class line{
public:
	point* pointA;
	point* pointB;
	point* mid;
	double length;
	double pYint; //perpendicular Y-intercept

public:
	line();
};

point::point(){

}

point::point(double x, double y){
	this->x_val = x;
	this->y_val = y;
}

line::line(){

}

int	asInt(string input){
	int outputInt = 0;
	istringstream convert_string_to_int(input);
	convert_string_to_int >> outputInt;
	return outputInt;
}

void parse(string fileName, vector<point>* point_list){
	ifstream myfile;
	char decider = 'a';
	string token;
	point* newPoint;

	myfile.open ("inputFile.txt");
	if (myfile.is_open()) {
		while ( getline (myfile,token, ',') ){
			
			if (decider == 'a') {
				newPoint = new point();
				newPoint->x_val = asInt(token);
				decider = 'b';
			}
			else if (decider == 'b'){
				newPoint->y_val = asInt(token);
				point_list->push_back(*newPoint);
				decider = 'a';
			}
			else{
				cout << "\nParsing Error Occurred..." << endl;			
			}
		}
		cout << "finished reading in from file..." << endl;
	}
	else{
		cout << "Could not read from file..." << endl;
	}
	myfile.close();
}

void displayPoints(vector<point>& point_list){
	int size = point_list.size();

	for (short i=0; i<size; i++){
		cout << "P[" << i << "]: " << point_list[i].x_val << ", " << point_list[i].y_val << endl;
	}

}

void displayTriangle(line &lineA, line &lineB, line &lineC){
	cout << "Three values:" << endl;
	cout << "(Largest Internal Triangle...)" << endl;
	cout << "   A: (" << lineA.pointA->x_val << ", " << lineA.pointA->y_val << ")"<< endl;
	cout << "   B: (" << lineB.pointA->x_val << ", " << lineB.pointA->y_val << ")"<< endl;
	cout << "   C: (" << lineC.pointA->x_val << ", " << lineC.pointA->y_val << ")"<< endl;
	
	cout << "   AB:" << endl;
	cout << "\t   mid: (" << lineA.mid->x_val << ", " << lineA.mid->y_val << ")"<< endl;
	cout << "\tlength: " << lineA.length << endl;
	
	cout << "   BC:" << endl;
	cout << "\t   mid: (" << lineB.mid->x_val << ", " << lineB.mid->y_val << ")"<< endl;
	cout << "\tlength: " << lineB.length << endl;
	
	cout << "   CA:" << endl;
	cout << "\t   mid: (" << lineC.mid->x_val << ", " << lineC.mid->y_val << ")"<< endl;
	cout << "\tlength: " << lineC.length << endl;
}

double findDistance(point* point1, point* point2){
	double x1 = point1->x_val;
	double y1 = point1->y_val;
	double x2 = point2->x_val;
	double y2 = point2->y_val;
	
	double term1 = double(x2) - double(x1);
	term1 = pow(term1, 2.0);
	double term2 = double(y2) - double(y1);
	term2 = pow(term2, 2.0);
	double distance = sqrt(term1+term2);
	return distance;
}

point* findMid(point* point1, point* point2){
	double x1 = point1->x_val;
	double y1 = point1->y_val;
	double x2 = point2->x_val;
	double y2 = point2->y_val;

	double midX = (x1+x2)/2;
	double midY = (y1+y2)/2;
	point* outPoint = new point(midX,midY);
	return outPoint;
}

double findYint(point* myPoint, double slope){
	double yInt = 0;
	yInt = myPoint->y_val - (slope * myPoint->x_val);
	return yInt;

}

double findSlope(point* point1, point* point2){
	double x1 = point1->x_val;
	double y1 = point1->y_val;
	double x2 = point2->x_val;
	double y2 = point2->y_val;
	
	double slope;
	slope = (y2-y1)/(x2-x1);

	return slope;
}

double perp_slope(point* point1, point* point2){
	double slope_check = findSlope(point1, point2);
	double perp = -1/slope_check;
	return perp;

}

point* findOrigin(line &lineA, line &lineB){

	double x_intersect = 0;
	double y_intersect = 0;
	
	point* mid_A = findMid(lineA.pointA, lineA.pointB);
	double slope_A = perp_slope(lineA.pointA, lineA.pointB);
	double cA = findYint(mid_A, slope_A);
	
	point* mid_B = findMid(lineB.pointA, lineB.pointB);
	double slope_B = perp_slope(lineB.pointA, lineB.pointB);
	double cB = findYint(mid_B, slope_B);
	
	x_intersect = (cB-cA)/(slope_A-slope_B);
	y_intersect = (slope_A*x_intersect) + cA;

	point* solution = new point(x_intersect, y_intersect);
	return solution;
	
}

#endif
