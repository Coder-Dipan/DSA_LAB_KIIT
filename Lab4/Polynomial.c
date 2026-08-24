//Q.2] WAP to perform the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.

#include<stdio.h>
int main(){
	int degree;
	printf("Enter maximum degree of x : ");
	scanf("%d", &degree);
	
	//declaration of 1-D arrays
	int poly1[degree + 1];
	int poly2[degree + 1];
	int result[degree + 1];
	
	//input polynomial 1
	printf("\nEnter polynomial-1 from lowest degree to highest degree : ");
	for(int i = 0; i <= degree; i++){
		scanf("%d", &poly1[i]);
	}
	
	//input polynomial 2
	printf("\nEnter polynomial-2 : ");
	for(int i = 0; i <= degree; i++){
		scanf("%d", &poly2[i]);
	}
	
	//Addition of ploynomial-1 and polynomial-2
	for(int i = 0; i <= degree; i++){
		result[i] = poly1[i] + poly2[i];
	}
	
	//Display the resultant polynomial from higest degree to lowest degree
	printf("\nResultant Polynomial : ");
	for(int i = degree; i >=0; i--){
		printf("%dx^%d", result[i], i);
		
		if(i != 0){
			printf(" + ");
		}
	}
	
	printf("\n");
	return 0;
}
