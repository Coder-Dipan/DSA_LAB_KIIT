//Q.1) Write a program to read two numbers and compare the numbers using function call by address.
#include<stdio.h>
void compare_Numbers(int *num1, int *num2){
    if(*num1 > *num2){
        printf("%d is greater than %d", *num1, *num2);
    } else if(*num1 < *num2){
        printf("%d is smaller than %d", *num1, *num2);
    } else {
        printf("%d and %d are equal", *num1, *num2);
    }
}

int main(){
    int num1, num2;

    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    compare_Numbers(&num1, &num2);
    return 0;
}