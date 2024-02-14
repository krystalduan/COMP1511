#include <stdio.h> 

int *create_array(void);
int main(void) { 
    int *p = create_array(); 
    printf("%d\n", p[4]);
    free(p);
    return 0;
}

int *create_array(void) {
    int *primes_ptr = malloc(5 * sizeof (int));
    primes_ptr[0] = 2;
    primes_ptr[4] = 11;
    return primes_ptr;
}