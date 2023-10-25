#include <stdlib.h> /* for malloc */
#include <stdio.h>

int main()
{
   /** say we open array of size 2 row 3 column */
   int row = 2, column = 3, r, j, k = 1;
   int **arrayTwoD = (int **)malloc(row * sizeof(int *));

   /* contiguous array dynamic allocate written by meow */
   int *address = (int *)malloc(row * column * sizeof(int));
   arrayTwoD[0] = address; /** first element point at same first address */

   for (r = 1; r < row; r++)
   {
      /* now each row we fill the suitable address to the first pointer in each column */
      address += column;
      arrayTwoD[r] = address;
   }

   for (r = 0; r < row; r++)
   {
      for (j = 0; j < column; j++)
      {
         arrayTwoD[r][j] = k++;
         printf("%d ", arrayTwoD[r][j]);
      }
      printf("\n%p\n", (void *)arrayTwoD[r]);
   }

   return 0;
}