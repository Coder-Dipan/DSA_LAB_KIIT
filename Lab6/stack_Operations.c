//Q] WAP to implement a stack data structure using an array. The program should provide the following operations through a menu-driven interface:

//1. Insert an element into the stack (Push operation).
//2. Delete an element from the stack (Pop operation).
//3. Display the top element of the stack (Peek operation).
//4. Display all elements in the stack.
//5.Handle stack overflow and underflow conditions appropriately.


#include<stdio.h>
#include<stdlib.h>

int top = -1;

//functions declaration
void push(int stack[], int maxSize);
void pop(int stack[]);
void peek(int stack[]);
void display(int stack[]);

int main(){
    int maxSize;
    printf("Enter the maximum size of the stack : ");
    scanf("%d", &maxSize);

    int stack[maxSize]; //initialize the stack

    while(1){
        printf("\n<-------STACK Operations--------->\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Top element\n");
        printf("4.Display Stack\n");
        printf("5.Exit\n");

        int choice;
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1 : push(stack, maxSize);
                    break;
            case 2 : pop(stack);
                    break;
            case 3 : peek(stack);
                    break;
            case 4 : display(stack);
                    break;
            case 5 : printf("Program Exited.\n");
                    exit(0);
                    break;
            default : printf("Invalid choice! Please try again.\n");
        }
        
    }

    return 0;
}


//function definations

//insert function
void push(int stack[], int maxSize){
    if(top == maxSize - 1){
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    int val;
    printf("Enter the value to push into the stack : ");
    scanf("%d", &val);

    top++;
    stack[top] = val;

    printf("%d pushed into the stack.\n", val);
}

//delete function
void pop(int stack[]){
    if(top == -1){
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("%d popped from the stack.\n", stack[top]);
    top--;
}

//display top function
void peek(int stack[]){
    if(top == -1){
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("Top element of the stack is : %d\n", stack[top]);
}

//display stack function
void display(int stack[]){
    if(top == -1){
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements are : \n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
}
