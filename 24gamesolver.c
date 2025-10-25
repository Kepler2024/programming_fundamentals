/* file    : 24gamesolver.c */
/* author  : XueJin Cui */
/* date    : 2025/10/24 */
/* version : 2.0 */
/* Description:
 * The program ask for 4 numbers between 1 and 10 from users, and prints the
 * expresssion that equals 24 if possible, otherwise it notifies user that
 * there is no solution.
 * The main idea is to use recursion to try all possible operations between
 * all pairs of numbers until only one number is left, then check if it is 24.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(float numbers[],char expr[][100]) {
   // Input function to read 4 numbers between 1 and 10
   float a;
   printf("Input 4 numbers between 1 and 10 (inclusive):\n");
   for (int i=0;i<4;i++) {
      scanf ("%f",&a);
      //check validity
      if ((a>=1) && (a<=10)) { 
         numbers[i] = a;
      } else {
         printf("Invalid input.\n");
         i--;
      }
   }

   //initialize expressions
   for (int j=0;j<4;j++) {
      snprintf(expr[j],100,"%.0f",numbers[j]);
   }
}

int isEqual(float a,float b) {
   // check equality of two floats
   return (fabsf(a-b)<1e-6);
}

int isPossible(
   int length, float numbers[4],
   char expressions[4][100], char result[100]) {

      float newNumbers[4]; // to hold new numbers
      char newExpressions[4][100]; // to hold new expressions

      // if only one number left, check if it is 24
      if (length == 1) {
         if (isEqual(numbers[0],24)) {
            //set result
            snprintf(result,100,"%s",expressions[0]);
            return 1;
         } else {
            return 0;
         }
      }

      // use double loops to try all pairs
      for (int i=0;i<length;i++) {
         for (int j=i+1;j<length;j++) {

            //store remaining numbers and expressions first
            int index = 0;
            for (int k=0;k<length;k++) {
               if ((k!=i)&&(k!=j)) {
                  newNumbers[index] = numbers[k];
                  snprintf(newExpressions[index],100,"%s",expressions[k]);
                  index++;
               } 
            } 

            //Then we try all operations, for addition and multiplication, we
            //only need to do one order, for subtraction and division, we need 
            //to try both orders

            //addition:
            //calculate the new number and store the new expression
            newNumbers[index] = numbers[i] + numbers[j]; 
            snprintf (
               newExpressions[index],100,
               "(%s + %s)",expressions[i],expressions[j]);

            // use the new number and expression to do recursion
            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            //other operations follow the same pattern
            //multiplication:
            newNumbers[index] = numbers[i] * numbers[j];
            snprintf (
               newExpressions[index],100,
               "(%s * %s)",expressions[i],expressions[j]);
            
            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }
            

            //subtraction (order 1):
            newNumbers[index] = numbers[i] - numbers[j];
            snprintf (
               newExpressions[index],100,
               "(%s - %s)",expressions[i],expressions[j]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            //subtraction (order 2):
            newNumbers[index] = numbers[j] - numbers[i];
            snprintf (
               newExpressions[index],100,
               "(%s - %s)",expressions[j],expressions[i]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            //division (order 1):
            //for division, we need to make sure the denominator is not zero
            if (!isEqual(numbers[i],0)) {
               newNumbers[index] = numbers[j] / numbers[i];
               snprintf (
                  newExpressions[index],100,
                  "(%s / %s)",expressions[j],expressions[i]);
               
               if (isPossible(length-1,newNumbers,newExpressions,result)) {
                  return 1;
               }
            }

            //division (order 2):
            if (!isEqual(numbers[j],0)) {
               newNumbers[index] = numbers[i] / numbers[j];
               snprintf (
                  newExpressions[index],100,
                  "(%s / %s)",expressions[i],expressions[j]);

               if (isPossible(length-1,newNumbers,newExpressions,result)) {
                  return 1;
               }
            }
         }
      }

      return 0;
}

int main(int argc, char *argv[]) {
   float numbers[4];
   char expressions[4][100];
   char result[100];
   input(numbers,expressions);
   if (isPossible(4,numbers,expressions,result)) {
      printf("Solution found: %s = 24\n",result);
   } else {
      printf ("No solution founded.\n");
   }
   return 0;
}
