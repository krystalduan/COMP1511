#include <stdio.h> 
int main (void) { 
    int year;
    printf("Enter year: "); 
    scanf("%d", &year); 
    int a; 
    int b; 
    int c; 
    int d; 
    int e; 
    int f; 
    int g; 
    int h; 
    int i; 
    int k; 
    int l; 
    int m; 
    int p; 
    int month; 
    int date; 
    a=year%19;
    b=year/100;
    c=year%100;
    d=b/4;
    e=b%4;
    f=(b+8)/25;
    g=(b-f+1)/3;
    h=(19*a+b-d-g+15)%30;
    i=c/4;
    k=c%4;
    l=(32+2*e+2*i-h-k)%7;
    m=(a+11*h+22*l)/451;
    p=(h+l-7*m+114)%31;
    month =(h+l-7*m+114)/31;
    date=p+1;
    if (month == 1) {
    printf("Easter is January %d in %d. \n", date, year);
    }
    else if (month == 2) {
    printf("Easter is February %d in %d. \n", date, year);
    }
    else if (month == 3) {
    printf("Easter is March %d in %d. \n", date, year);
    }
    else if (month == 4) {
    printf("Easter is April %d in %d. \n", date, year);
    }
    else if (month == 5) {
    printf("Easter is May %d in %d. \n", date, year);
    }
    else if (month == 6) {
    printf("Easter is June %d in %d. \n", date, year);
    }
    else if (month == 7) {
    printf("Easter is July %d in %d. \n", date, year);
    }
    else if (month == 8) {
    printf("Easter is August %d in %d. \n", date, year);
    }
    else if (month == 9) {
    printf("Easter is September %d in %d. \n", date, year);
    }
    else if (month == 10) {
    printf("Easter is October %d in %d. \n", date, year);
    }
    else if (month == 11) {
    printf("Easter is November %d in %d. \n", date, year);
    }
    else if (month == 12) {
    printf("Easter is December %d in %d. \n", date, year);
    }
    
    return 0; 
}
