#include <stdio.h> 
int main (void) {
int numbers[7];

int i = 0; 
while (i < 7) { 
    numbers[i] = 1;
    i++;
}
int firstplusthird = numbers[0] + numbers[2]; 
printf("Adding the first and third element gives: %d \n", firstplusthird); 
return 0; 
}
