//Q.2) Write a program to create an array of n elements using dynamic memory allocation.Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include<stdio.h>
#include<stdlib.h>

//check a number is prime or not
int isPrime(int num){
    if(num <= 1) {
        return 0;
    }

    for(int i = 2; i < num; i++){
        if(num % i == 0) {
            return 0;
        }
    }

    return 1;
}

//calculate sum of all prime number in the array
int sumOfPrimes(int arr[], int n){
    int sum = 0; 

    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            sum += arr[i];
        }
    }

    return sum;
}

int main(){
    int n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    //dynamically memory allocation
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements of the array : ", n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int result = sumOfPrimes(arr, n);
    printf("Sum : %d", result);

    //de-allocate the memory
    free(arr);

    return 0;
}