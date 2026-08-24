//Q.4] Write a menu driven program to create a structure to represent complex number and perform the following operation using function.

#include<stdio.h>

//structure to represent complex number
struct Complex {
    int real;
    int imag;
};

//Function for addition (call by value)
struct Complex add(struct Complex c1, struct Complex c2){
    struct Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

//Function for Multiplication (call by address)
void multiply(struct Complex *c1, struct Complex *c2, struct Complex *result){
    result->real = (c1->real * c2->real) - (c1->imag * c2->imag);
    result->imag = (c1->real * c2->imag) + (c1->imag * c2->real);
}

int main(){
    struct Complex c1, c2, result;
    int choice;

    printf("Enter complex number 1 (real imaginary) : ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("Enter complex number 2 (real imaginary) : ");
    scanf("%d %d", &c2.real, &c2.imag);

    do {
        printf("\n--------MENU--------\n");
        printf("1.Addition\n");
        printf("2.Multiplication\n");
        printf("3.Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                result = add(c1, c2);
                printf("Sum : %d + %di\n", result.real, result.imag);
                break;
            case 2:
                multiply(&c1, &c2, &result);
                printf("Product : %d + %di\n", result.real, result.imag);
                break;
            case 3:
                printf("Program Exited.\n");
                break;
            default:
                printf("Invalid Choice!\n");
        } 
    } while(choice != 3);

    return 0;
}