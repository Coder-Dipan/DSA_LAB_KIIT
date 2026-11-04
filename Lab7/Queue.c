//Q] Write a C program to implement a Queue using an array. The program provide a menu-driven interface with the following operations:

//1. Enqueue - Insert an element into the queue.
//2. Dequeue - Delete an element from the queue.
//3. Peek - Display the front element of the queue.
//4. Display - Display all elements in the queue.
//5. Exit - Terminate the program.
//The program should handle queue overflow and underflow conditions appropriately.

#include<stdio.h>
#include<stdlib.h>

int front = 0, rear = -1;

//functions decalrations
void Enqueue(int queue[], int sz);
void Dequeue(int queue[], int sz);
void Peek(int queue[], int sz);
void Display(int queue[], int sz);


int main(){
	int sz;
	printf("Enter the size of the queue : ");
	scanf("%d", &sz);
	
	int queue[sz]; //initialized the queue
	
	while(1){
	printf("\n<------- QUEUE OPERATIONS --------->\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Front Element\n");
	printf("4.Display Queue\n");
	printf("5.Exit\n");
	
	int option;
	printf("\nEnter the option : ");
	scanf("%d", &option);
	
	switch(option){
		case 1 : Enqueue(queue, sz);
			break;
		
		case 2 : Dequeue(queue, sz);
			break;
		
		case 3 : Peek(queue, sz);
			break;
	
		case 4 : Display(queue, sz);
			break;
		
		case 5 : printf("Program Terminated.\n");
			exit(0);
			break;
		
		default : printf("Invalid Choice! Please retry.\n");
	}
	
	}
	
	return 0;
}

//function definations

//Insert function
void Enqueue(int queue[], int sz){
	if(rear == sz - 1){
	printf("Queue Overflow! Cannot insert elements.\n");
	return;
	}
	
	int val;
	printf("Enter the element to insert : ");
	scanf("%d", &val);
	
	rear++;
	queue[rear] = val;
	printf("%d inserted into the queue.\n", val);
}

//Delete function
void Dequeue(int queue[], int sz){
	if(front > rear){
	printf("Queue Underflow! Queue is empty.\n");
	return;
	}
	
	printf("%d deleted from the queue.\n", queue[front]);
	
	front++;
	
	//reset queue when it becomes empty
	if(front > rear){
	front = 0;
	rear = -1;
	}
}


//Front Elemenet
void Peek(int queue[], int sz){
	if(front > rear){
	printf("Queue is empty!\n");
	} else {
	printf("Front element is %d\n", queue[front]);
	}
}

//Display Queue function
void Display(int queue[], int sz){
	if(front > rear){
	printf("Queue is empty!\n");
	return;
	}
	
	printf("Queue elements are : ");
	for(int i = front; i <= rear; i++){
	printf("%d ", queue[i]);
	}
	
	printf("\n");
}







