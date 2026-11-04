//Q] Write a C program to implement a circular queue using an array. The program provide a menu-driven interface with the following operations:

//1. Enqueue - Insert an element into the circular queue.
//2. Dequeue - Delete an element from the circular queue.
//3. Display - Display all elements in the circular queue.
//4. Exit - Terminate the program.


#include<stdio.h>
#include<stdlib.h>

int front = 0, rear = -1;
int currSize = 0;

//functions declarations
void Enqueue(int cirQueue[], int capacity);
void Dequeue(int cirQueue[], int capacity);
void Display(int cirQueue[], int capacity);

int main(){
	int capacity;
	printf("Enter the capacity of the circular queue : ");
	scanf("%d", &capacity);
	
	if(capacity <= 0){
	printf("Invalid Capacity!");
	return 0;
	}
	
	int cirQueue[capacity]; //initilized the circular queue
	
	while(1){
	printf("\n<------ Circular Queue Operations --------->\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display Elements\n");
	printf("4.Exit\n");
	
	int choice;
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1 : Enqueue(cirQueue, capacity);
			break;
		case 2 : Dequeue(cirQueue, capacity);
			break;
		case 3 : Display(cirQueue, capacity);
			break;
		case 4 : printf("Program Terminated.\n");
            exit(0);
			break;
		default : printf("Invalid Choice! Please retry.\n");
	}
	}
	
	
	return 0;	
}

//function definations

//insert function
void Enqueue(int cirQueue[], int capacity){
	if(currSize == capacity){
	printf("Circular Queue Overflow! Cannot insert elements.\n");
	return;
	}
	
	int data;
	printf("Enter the element to insert : ");
	scanf("%d", &data);
	
	
	rear = (rear + 1) % capacity;
	cirQueue[rear] = data;
	currSize++;
	
	printf("%d is inserted into the circular queue.\n", cirQueue[rear]);
}

//delete function
void Dequeue(int cirQueue[], int capacity){
	if(currSize == 0){
	printf("Circular Queue Underflow! Queue is empty.\n");
	return;
	}
	
	printf("%d is deleted from the circular Queue.\n", cirQueue[front]);
	front = (front + 1) % capacity;
	currSize--;	
}

//display function
void Display(int cirQueue[], int capacity){
	if(currSize == 0){
	printf("Circular Queue is empty.\n");
	return;
	}
	
	printf("Circular Queue elements are : ");
	
	int index = front;
	
	for(int i = 0; i < currSize; i++){
	printf("%d ", cirQueue[index]);
	index = (index + 1) % capacity;
	}
	
	printf("\n");
}

