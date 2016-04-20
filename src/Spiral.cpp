/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiral_row( int **input_array, int k, int spc, int epc, int spr, int epr, int* resultset){
	int i;
	if (spc <= epc && spr <= epr){
		for (i = spc; i <= epc; i++){
			resultset[k] = input_array[spr][i];
			k++;
		}
		for (i = spr + 1; i <= epr; i++){
			resultset[k] = input_array[i][epc];
			k++;
		}
		for (i = epc - 1; i >= spc; i--){
			resultset[k] = input_array[epr][i];
			k++;
		}
		for (i = epr - 1; i > spr && epc != 0; i--){
			resultset[k] = input_array[i][spc];
			k++;
		}
		spiral_row(input_array, k, spc + 1, epc - 1, spr + 1, epr - 1, resultset);
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	int starting_point_columns = 0;
	int ending_point_columns = columns - 1;
	int starting_point_row = 0;
	int ending_point_row = rows - 1;
	int k = 0;
	int *result = (int*)malloc((rows * columns) * sizeof(int));
	if (rows <= 0 || columns <= 0 || input_array == NULL) 
		return NULL;
	spiral_row(input_array,k, starting_point_columns,ending_point_columns, starting_point_row,ending_point_row,result);
	return result;
}
