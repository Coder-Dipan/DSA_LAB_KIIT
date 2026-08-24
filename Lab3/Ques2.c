//Q2] WAP to represent a given sparse matrix in 3-tuple format using 2-D array.

#include<stdio.h>
int main()
{
    int rows, cols;
    printf("Enter size of the sparse matrix (rows, columns) : ");
    scanf("%d %d", &rows, &cols);

    int sparse[rows][cols]; //initialized the sparse matrix

    //input the elements of the sparse matrix
    printf("\nEnter the elements of the sparse matrix : \n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &sparse[i][j]);
        }
    }

    //count the number of non-zero elements in the sparse matrix
    int count = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(sparse[i][j] != 0){
                count++;
            }
        }
    }

    //create a 3-tuple representation of the sparse matrix
    int tuple[count+1][3]; 

    //strore the matrix information in first row of the 3-tuple
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = count;

    //strore non-zero elements in the 3-tuple
    int k = 1;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j <cols; j++){
            if(sparse[i][j] != 0){
                tuple[k][0] = i; //row number
                tuple[k][1] = j; //column number
                tuple[k][2] = sparse[i][j]; //non-zero element

                k++;
            }
        }
    }

    //Display the 3-tuple representation of the sparse matrix
    printf("\n3-Tuple Representation of the Sparse Matrix : \n");
    printf("Row\tColumn\tValue\n");
    
    for(int i = 0; i <= count; i++){
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }


    return 0;
}