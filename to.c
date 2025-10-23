/* file     : to_other_side.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/15 */
/* version  : 1.0 */
/* Description:
 * Dynamic programming solution to find the cheapest path
 * from the first column to the last in an R x C grid,
 * moving only east, northeast, or southeast.
 */

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int min3(int a, int b, int c) {
   if (a > b) {
      a = b;
   }
   if (a > c) {
      a = c;
   }
   return a;
}

int main(void) {
   int r;
   int c;
   scanf("%d %d", &r, &c);

   int **grid = (int **)malloc(r * sizeof(int *));
   for (int i = 0; i < r; i++) {
      grid[i] = (int *)malloc(c * sizeof(int));
      for (int j = 0; j < c; j++) {
         scanf("%d", &grid[i][j]);
      }
   }

   int **dp = (int **)malloc(r * sizeof(int *));
   for (int i = 0; i < r; i++) {
      dp[i] = (int *)malloc(c * sizeof(int));
   }

   for (int i = 0; i < r; i++) {
      dp[i][c-1] = grid[i][c-1];
   }

   for (int j = c - 2; j >= 0; j--) {
      for (int i = 0; i < r; i++) {
         int up = INF;
         if (i > 0) {
            up = dp[i-1][j+1];
         }

         int mid = dp[i][j+1];

         int down = INF;
         if (i < r-1) {
            down = dp[i+1][j+1];
         }

         dp[i][j] = grid[i][j] + min3(up, mid, down);
      }
   }

   int ans = INF;
   for (int i = 0; i < r; i++) {
      if (dp[i][0] < ans) {
         ans = dp[i][0];
      }
   }

   printf("%d\n", ans);

   for (int i = 0; i < r; i++) {
      free(grid[i]);
   }
   for (int i = 0; i < r; i++) {
      free(dp[i]);
   }
   free(grid);
   free(dp);

   return 0;
}