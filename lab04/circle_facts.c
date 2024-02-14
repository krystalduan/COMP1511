// COMP1511 Week 4 Lab: Circle Facts
//
// This program was written by KRYSTAL DUAN (z5361475)
// on 27-06-2021
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    double result_area;
    result_area = radius * radius * M_PI;
    return result_area;
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    double result_circum;
    result_circum = 2 * M_PI * radius;
    return result_circum; 
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    double result_diameter;
    result_diameter = 2 * radius; 
    return result_diameter; 
}
