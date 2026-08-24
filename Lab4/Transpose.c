//Q.1] WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include<stdio.h>
int main()
{
	int rows, cols, nonZero;
	
	printf("\nEnter sparse matrix in 3-tuple format : \n");
	//input row number, column number, number of non-Zero elements
	scanf("%d %d %d", &rows, &cols, &nonZero);
	
	//create arrays for original and transpose matrix
	int sparse[nonZero + 1][3];
	int transpose[nonZero + 1][3];
	
	//strore first row of sparse matrix
	sparse[0][0] = rows;
	sparse[0][1] = cols;
	sparse[0][2] = nonZero;
	
	//input the sparse matrix
	for(int i = 1; i <= nonZero; i++){
		scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
	}
	
	//first row of transpose
	transpose[0][0] = cols;
	transpose[0][1] = rows;
	transpose[0][2] = nonZero;
	
	int k = 1;
	
	//transpose the sparse matrix
	for(int j = 0; j < cols; j++){
		for(int i = 1; i <= nonZero; i++){
			if(sparse[i][1] == j){
				//column becomes row
				transpose[k][0] = sparse[i][1];
				
				//row becomes column
				transpose[k][1] = sparse[i][0];
				
				//non-Zero Elements are same
				transpose[k][2] = sparse[i][2];
				
				
				k++; //increase k
			}
		}
	}
	
	//display the transpose matrix
	printf("\nTranspose of sparse matrix : \n");
	printf("R\tC\tElement\n");
	
	
	for(int i = 0; i <= nonZero; i++){
		printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
	}
	
	
return 0;
}