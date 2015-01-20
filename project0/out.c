#include <stdio.h>

/* The size of the fixed array */
#define ASIZE 20

/* The array to average */
int a[ASIZE];

/* Average the a array of the given size.  Store the average in the double
 * pointed to by out_param. */
void average(int *a, int size, double *out_param) {
    int tot = 0;
    int i = 0;

    for (i = 0; i < size; i++)
	tot += a[i];
    /* Cast tot into a double so the result of the division is a double. */
    *out_param = (double) tot/size;
}

/* Copy the value of the out_param pointer into a pointer variable outside this function. */
void copyPointer( double* newPointer, double* out_param){
  //printf( "Before copy pointers differ (%p,%p)\n", newPointer, out_param );
  newPointer = out_param*;
  //printf( "After copy pointers are the same (%p,%p)\n", newPointer, out_param );
}

/* My version produces this output:

$ ./out
Average: 9.5
Before copy pointers differ (0x0, 0x600cd0)
After copy pointers are the same (0x600cd0, 0x600cd0)
*/

/* Initialize a with the integers from 0 to ASIZE-1 and call average on it.
 * Print the result. */
int main(int argc, char **argv) {
    int i = 0;
    double avg = 0.0;
    /* Pointer that we will use to copy address. */
    double* newPointer;

    for (i=0; i< ASIZE; i++)
	a[i] = i;

    average(a, ASIZE, &avg);
    printf("Average: %g\n", avg);
    
    /* Code added by me to demonstrate that the address of the pointers are different after the average() function and the same after the copyPointer() function. */
    printf( "Before copy pointers differ (%p,%p)\n", newPointer, &avg );
    copyPointer( newPointer, &avg );
    printf( "After copy pointers are the same (%p,, %p)\n", newPointer, &avg );
}
