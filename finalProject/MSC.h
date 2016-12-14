#include <stdio.h>

using namespace std;

int	asInt(string input);
void parse(string fileName, vector<point>* point_list);
void displayPoints(vector<point>& point_list);
double findDistance(int x1, int y1, int x2, int y2);
double findSlope(point* point1, point* point2);
double perp_slope(point* point1, point* point2);
