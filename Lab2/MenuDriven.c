//Write a program to create a 1-D array of n elements and perform the following operations using functions.
 //i)Insert an element at a given position.
 //ii)Delete an element from a given position.
 //iii)Search for an element in the array using linear search.
 //iv)Traverse of the array.

#include<stdio.h>
#include<stdlib.h>

//Insert Function
void insert(int arr[], int *n){
    int val, pos;
    printf("Enter element to insert : ");
    scanf("%d", &val);

    printf("Enter position : ");
    scanf("%d", &pos);

    if(pos < 1 || pos > (*n)+1){
        printf("Invalid Position!\n");
        return;
    }

    for(int i=*n; i>=pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = val;

    (*n)++; //increase the size of the array

    //print the updated array
    printf("Updated Array : ");
    for(int i=0; i<*n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

//Delete function
void Delete(int arr[], int *n){
    int key, index = -1;
    printf("Enter element to Delete : ");
    scanf("%d", &key);

    for(int i=0; i<*n; i++){
        if(arr[i] == key){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Element not found!\n");
        return;
    }

    for(int i=index; i<(*n)-1; i++){
        arr[i] = arr[i+1];
    }

    (*n)--; //decrease the size of the array

    //print the updated array
    printf("Updated Array : ");
    for(int i=0; i<*n; i++){
        printf("%d\t", arr[i]);        
    }
    printf("\n");
}

//Linear Search Function
int LSearch(int arr[], int n){
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);

    for(int i=0; i<n; i++){
        if(key == arr[i]){
            return i;
        }
    }

    return -1;
}

//Traverse Function
void traverse(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter size n : ");
    scanf("%d", &n);

    int arr[n]; //declaration of the array

    printf("Enter elements of the array\n");

    //input the elements of the array
    printf("Enter Array elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    //Show Menu
    while(1){
        printf("<-------MENU------->");
        printf("\n1.Insert\n");
        printf("\n2.Delete\n");
        printf("\n3.Linear Search\n");
        printf("\n4.Traverse\n");
        printf("\n5.Exit\n");

        //Select the option from menu 
        int option;
        printf("Enter option : ");
        scanf("%d", &option);

        switch(option){
            case 1 : insert(arr, &n);
                    printf("\nElement inserted.\n");
                    break;

            case 2 : Delete(arr, &n);
                    printf("\nElement deleted.\n");
                    break;

            case 3 : {
                    int pos = LSearch(arr, n);
                    if(pos == -1){
                        printf("\nElement not found!\n");
                    } else {
                        printf("\nElement found at position %d\n", pos + 1);
                    }
                    break;
                    }

            case 4 : traverse(arr, n);
                    printf("\nTraversed Successfully!\n");
                    break;

            case 5 : printf("\nProgram Exited.\n");
                    exit(0);
                    break;

            default : printf("\nInvalid Option!\n");
        }
    }

    return 0;
}