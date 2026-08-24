//Q1.] Write a program to perform the following operations on a given square matrix using functions.  
 //i)Count the number of non-zero elements in the matrix.
 //ii)Display the upper triangular matrix of the given matrix.
 //iii)Display the elements of just above and below the main diagonal.

#include<stdio.h>
#include<stdlib.h>

//functions declaration
int countNonZeros(int n, int mat[n][n]);
void upperTriangular(int n, int mat[n][n]);
void diagonalElements(int n, int mat[n][n]);


int main(){
	int n;
	printf("Enter the size of the matrix : ");
	scanf("%d", &n);
	
	int mat[n][n]; //initialized the matrix
	
    //input the elements of the matrix
	printf("Enter matrix elements : \n");
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	while(1){
		printf("\n<-------MENU------->\n");
		printf("1.View Non Zero Elements\n");
		printf("2.Upper Triangular Matrix\n");
		printf("3.Diagonal Elements\n");
		printf("4.Exit\n");
		
		printf("\n");
		
		int option;
		printf("Enter your choice : ");
		scanf("%d", &option);
	
		switch(option){
	
		case 1 : 
			printf("Total no. of Non-Zero elements : %d\n", countNonZeros(n, mat));
			break;
	
		case 2 : upperTriangular(n, mat);
			break;
		
		case 3 : diagonalElements(n, mat);
			break;
		
		case 4 : printf("Program Exited.\n"); exit(0);
			break;
		
		default : printf("Invalid Option!");
	
		}
	}
	
	
	return 0;
}

//Function to count non zero elements in the matrix
int countNonZeros(int n, int mat[n][n]){
	int count = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j] != 0){
				count++;
			}
		}
	}
	
	return count;
}

//function to display Upper Triangular matrix 
void upperTriangular(int n, int mat[n][n]){
	printf("\nUpper Triangular Matrix : \n");
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i <= j){
				printf("%4d", mat[i][j]);
			} else {
				printf("%4d", 0);
			}
		}
		
		printf("\n");
	}
}

//function to display elements just above and below the main diagonal
void diagonalElements(int n, int mat[n][n]){
	printf("\nDiagonal Elements : \n");
	
	//elements just above the main diagonal
	printf("Elements just above the main diagonal : ");
	
	for(int i=0; i<n-1; i++){
		printf("%d\t", mat[i][i+1]);
	}
	
	printf("\n");
	
	//elements just below the main diagonal
	printf("Elements just below the main diagonal : ");
	
	for(int i=1; i<n; i++){
		printf("%d\t", mat[i][i-1]);
	}
	
	printf("\n");
}


