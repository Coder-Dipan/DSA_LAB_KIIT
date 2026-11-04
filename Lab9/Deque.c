// Q] Write a program to implement a Deque using an array of fixed size.

// Your program should provide the following menu-driven operations:

// 1.Insert an element at the Front

// 2.Insert an element at the Rear

// 3.Delete an element from the Front

// 4.Delete an element from the Rear

// 5.Display all elements of the Deque

// 7.Exit

// The program should also handle the following conditions:

// Deque Overflow – when no more elements can be inserted.

// Deque Underflow – when deletion is attempted on an empty deque.




#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1;

//function declarations
void insertFront(int deque[], int size);
void insertRear(int deque[], int size);
void deleteFront(int deque[], int size);
void deleteRear(int deque[], int size);
void Display(int deque[], int size);

int main(){
	int size;
	printf("Enter the size of the deque : ");
	scanf("%d", &size);
	
	int deque[size]; //initialized the deque
	
	while(1){
	printf("\n<------ DEQUE OPERATIONS -------->\n");
	printf("1.Insert at Front\n");
	printf("2.Insert at Rear\n");
	printf("3.Delete from Front\n");
	printf("4.Delete from Rear\n");
	printf("5.Display the deque\n");
	printf("6.Exit\n");
	
	int choice;
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1 : insertFront(deque, size);
			break;
		case 2 : insertRear(deque, size);
			break;
		case 3 : deleteFront(deque, size);
			break;
		case 4 : deleteRear(deque, size);
			break;
		case 5 : Display(deque, size);
			break;
		case 6 : printf("Program Terminated.\n"); 
			 exit(0);
			break;
		default: printf("Invalid Choice! Please try again.\n");
	}
	}
	
	return 0;
}


//function definations

//insert at front
void insertFront(int deque[], int size){
	if(front == 0){
	printf("Deque Overflow at front!\n");
	return;
	}
	
	int val;
	printf("Enter the element to insert at front : ");
	scanf("%d", &val);
	
	if(front == -1){
	front = rear = 0;
	} else {
	front--;
	}
	
	deque[front] = val;
	
	printf("%d inserted at front.\n", deque[front]);
}

//insert at rear
void insertRear(int deque[], int size){
	if(rear == size - 1){
	printf("Deque Overflow at rear!\n");
	return;
	}
	
	int val;
	printf("Enter the element to insert at rear : ");
	scanf("%d", &val);
	
	if(front == -1){
	front = rear = 0;
	} else {
	rear++;
	}
	
	deque[rear] = val;
	
	printf("%d inserted at rear.\n", deque[rear]);
}

//delete from front 
void deleteFront(int deque[], int size){
	if(front == -1){
	printf("Deque Underflow!\n");
	return;
	}
	
	printf("Deleted element from front : %d\n", deque[front]);
	
	if(front == rear){
	front = rear = -1;
	} else {
	front++;
	}
}

//delete from rear
void deleteRear(int deque[], int size){
	if(rear == -1){
	printf("Deque Underflow!\n");
	return;
	}
	
	printf("Deleted element from rear : %d\n", deque[rear]);
	
	if(front == rear){
	front = rear = -1;
	} else {
	rear--;
	}
}

//display the deque elements
void Display(int deque[], int size){
	if(front == -1){
	printf("Deque is empty!\n");
	return;
	}
	
	printf("Deque : ");
	
	for(int i = front; i <= rear; i++){
	printf("%d ", deque[i]);
	}
	
	printf("\n");
}



