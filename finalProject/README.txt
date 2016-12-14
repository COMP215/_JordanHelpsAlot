Project: Minimum Spanning Circle Problem
Author: Jordan Hamilton

Concept: 
	For this project, I decided to investigate the process of determining the smallest circle which can encompass a given set of points on the XY plane. This process has applications in a variety of fields, such as placing emergency/rescue helicopter stations in locations which may need to be within range of a number of facilities at any given time. I also believe this problem is a significant challenge for algorithmic thinking because a specific process has to be determined for calculating the correct output for a huge range of possible inputs.

Algorithm: 
	My algorithm works by first determining the longest two line segments sharing a point which can be drawn from the input data. Due to parsing issues, my implementation only works for positive integer coordinates. Once the two lines (featuring 3 points) have been determined, the algorithm analyzes the triangle formed by their vertices to find a circumcenter. The circumcenter is the origin point for the MSC of the data set. To determine the radius of the circle, the algorithm then determines the distance from this origin to any of the three vertices in the triangle (all will fall on the perimeter of the circle). 

Compile Instructions:
-In project directory, "inputFile.txt" contains the comma separated values used as input for the program. These may be changed to whatever you like.
-Open terminal and change directory to that of the project
-Input: "g++ main.cpp -o 'choose_output_name'"
-Run: "./'chosen_output_name'"
-The displayed solution will show the radius and origin point of the minimum spanning circle for the data points represented in "inputFile.txt"
