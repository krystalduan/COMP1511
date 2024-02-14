#include <stdio.h> 

int main(void) { 
    double fahrenheit; 
    printf("enter a temperature in fahrenheit: "); 
    scanf("%lf", &fahrenheit); 
    double celsius; 
    celsius = (fahrenheit -32)*5/9 ;
    printf("the temperature in celsius is %lf", celsius); 
    return 0;
}
    
