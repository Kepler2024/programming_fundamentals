/* file    : counting4.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/13 */
/* version : 4.0 */
/* Description:
 * lab3_1_fourth attempt
 */

#include <stdio.h>
#include <stdlib.h>

void input(int length, int number[]) {
   // Input function to read length numbers
   for (int i=0;i<length;i++) {
      scanf ("%d",&number[i]);
   }
}

void initialize(int length, int a[]) {
   // initialize the stage array to all 0 (unvisited)
   for (int i=0; i<length; i++) {
      a[i] = 0;
   }
}

int main(int argc, char *argv[]) {
   
   int length;
      scanf("%d",&length);
   int number[length];
   int stage[length];

   initialize(length,stage);
   input(length,number);
   printf("%d\n",countingCycle(length,stage,number));
   
   return 0;
}