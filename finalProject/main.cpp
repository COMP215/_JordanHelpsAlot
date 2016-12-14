#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"MSC.cpp"
#include"MSC.h"
using namespace std;

int main(){
	double distance = 0;
	double longest_distance = 0;
	double circle_radius = 0;
	line lineA, lineB, lineC;
	vector<point> point_list;
	parse("inputFile.txt", &point_list);
	int point_count = point_list.size();
	displayPoints(point_list);
	point* ignore_point;
	point* circle_origin;
	point* start = &point_list[0];
	point* furthest_point = start;
	
	//1rst Distance Search - finds furthest point from random start position
	for (short i=0; i<point_count; i++){
		point* current = &point_list[i];
		distance = findDistance(start, current);
		if (distance > longest_distance){
			furthest_point = current;
			longest_distance = distance;
		}
	}
	
	//Assign point A because we know it already
	lineA.pointA = furthest_point;
	
	//2nd search - finds longest connection between two points in set
	start = furthest_point;
	longest_distance = 0;
	for (short i=0; i<point_count; i++){
		point* current = &point_list[i];

		distance = findDistance(start, current);
		if (distance > longest_distance){
			furthest_point = current;
			longest_distance = distance;
		}
	}
	
	//Assign point B for longest line within set
	lineA.pointB = furthest_point;
	
	//Assign point A for second longest line (LineB)
	lineB.pointA = furthest_point;
	
	//3rd search
	ignore_point = start;
	start = furthest_point;
	longest_distance = 0;
	for (short i=0; i<point_count; i++){
		point* current = &point_list[i];
		distance = findDistance(start, current);
		if (current == ignore_point){continue;}
		if (distance > longest_distance){
			furthest_point = current;
			longest_distance = distance;
		}
	}
	
	//Assign point B for second longest line (LineB)
	lineB.pointB = furthest_point;
	
	//Assign points in C based on end of B and start of A
	lineC.pointA = lineB.pointB;
	lineC.pointB = lineA.pointA;
	
	//Determine length attribute for each line (formality)
	lineA.length = findDistance(lineA.pointA, lineA.pointB);
	lineB.length = findDistance(lineB.pointA, lineB.pointB);
	lineC.length = findDistance(lineC.pointA, lineC.pointB);
	
	//Determine midpoint values
	lineA.mid = findMid(lineA.pointA, lineA.pointB);
	lineB.mid = findMid(lineB.pointA, lineB.pointB);
	lineC.mid = findMid(lineC.pointA, lineC.pointB);
	/*
	cout << "LD in set: " << findDistance(lineA.pointA, lineA.pointB) << endl;
	cout << "2NDLD in set: " << findDistance(lineB.pointA, lineB.pointB) << endl;
	*/
	displayTriangle(lineA,lineB,lineC);
	
	circle_origin = findOrigin(lineA, lineB);
	circle_radius = findDistance(lineA.pointA, circle_origin);
	
	cout << "Solution:" << endl;
	cout << "\tRadius: " << circle_radius << endl;
	cout << "\tOrigin: (" << circle_origin->x_val << ", " << circle_origin->y_val << ")" << endl;

	return 0;
	
}











	
