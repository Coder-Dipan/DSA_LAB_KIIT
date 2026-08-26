//Q.1] WAP to create and manipulate a singly Linked list. The program should implement the following operations :

//1. Insertion of a Node
//i)Insert a node at the begining of the linked list.
//ii)Insert a node at the end of the linked list.
//iii)Insert a node at a specific position in the linked list.

//2.Deletion of a Node
//i)Delete a node from the begining of the linked list.
//ii)Delete a node from the end of the linked list.
//iii)Delete a node from a specific position of the linked list.


#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

//creating a node
struct Node* createNode(int val){
	struct Node* newNode = malloc(sizeof(struct Node));
	
	newNode->data = val;
	newNode->next = NULL;
	
	return newNode;
}

//create a Linked list
struct Node* createList(int n){
	struct Node* head = NULL;
	struct Node* temp = NULL;
	struct Node* newNode = NULL;
	
	int val;
	printf("Enter elements : ");
	for(int i = 1; i <= n; i++){
		scanf("%d", &val);
		
		newNode = createNode(val);
	
		//First Node
		if(head == NULL){
			head = newNode;
			temp = newNode;
		} else {
			temp->next = newNode;
			temp = newNode;
		}
	}
	
	return head;
}

//display Linked list
void display(struct Node* head){
	struct Node* temp = head;
	
	printf("\nLinked List : ");
	
	while(temp != NULL){
		printf("%d->", temp->data);
		temp = temp->next;
	}
	
	printf("NULL\n");
}

//functions declaration
struct Node* push_front(struct Node* head, int data);
struct Node* push_back(struct Node* head, int data);
struct Node* insert(struct Node* head, int val, int pos);
struct Node* pop_front(struct Node* head);
struct Node* pop_back(struct Node* head);
struct Node* Delete(struct Node* head, int val);

int main(){
	struct Node* head;
	
	int n;
	printf("Enter number of nodes : ");
	scanf("%d", &n);
	
	//create the LL
	head = createList(n);
	
	//display the original LL
	display(head);
	
	
	while(1){
		printf("\n<------MENU----->\n");
		printf("1.Insert at the begining\n");
		printf("2.Insert at the end\n");
		printf("3.Insert at a specific position\n");
		printf("4.Delete from the begining\n");
		printf("5.Delete from the end\n");
		printf("6.Delete from a specific position\n");
		printf("7.Exit\n");
		
		int option;
		printf("\nEnter your choice : ");
		scanf("%d", &option);
		
		switch(option){
			case 1 :{
				int data;
				printf("Enter the value of the node : ");
				scanf("%d", &data);
				
				head = push_front(head, data);
				
				//display after push front
				printf("\nAfter push front : ");
				display(head);
				
				break;
				}
				
			case 2 :{
				int data;
				printf("Enter the value of the node : ");
				scanf("%d", &data);
				
				head = push_back(head, data);
				
				//display after push front
				printf("\nAfter push back : ");
				display(head);
				
				break;
				}
				
			case 3 :{
				int val, pos;
				
				printf("Enter the value of the node : ");
				scanf("%d", &val);
				
				printf("Enter the position : ");
				scanf("%d", &pos);
				
				head = insert(head, val, pos);
				
				//display after inserting 
				printf("\nAfter insertion : ");
				display(head);
				
				break;
				}
				
			case 4 :{
				head = pop_front(head);
				
				//display after pop front 
				printf("\nAfter pop front : ");
				display(head);
				
				break;
				}
				
			case 5 :{
				head = pop_back(head);
				
				//display after pop back
				printf("\nAfter pop back : ");
				display(head);
				
				break;
				}
				
			case 6 :{
				int val;
				printf("Enter the node : ");
				scanf("%d", &val);
				
				head = Delete(head, val);
				
				//display after deletion
				printf("\nAfter deletion : ");
				display(head);
				
				break;
				}
				
			case 7 : printf("Program Exited.\n"); 
					exit(0);
					break;
			
			default : printf("Invalid Choice!\n");
			
		}
	}
	
	
	return 0;
}

//function definations

//insert at the begining
struct Node* push_front(struct Node* head, int data){
	struct Node* newNode = malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	
	return head;
}

//insert at the end
struct Node* push_back(struct Node* head, int data){
	struct Node* newNode = malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	//if list is empty
	if(head == NULL){
		return newNode;	
	}
	
	struct Node* temp = head;
	
	//Go to the last node
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
	
	
	return head;
	
}

//insert at a specific position
struct Node* insert(struct Node* head, int val, int pos){
	if(pos <= 0){
		printf("Invalid position!\n");	
		return head;
	}
	
	//insert at begining
	if(pos == 1){
		return push_front(head, val);
	}
	
	struct Node* temp = head;
	
	for(int i = 1; i < pos-1; i++){
		if(temp == NULL){
			printf("Invalid Position!\n");
			return head;
		}
		
		temp = temp->next;
	}
	
	if(temp == NULL){
	printf("Invalid Position!\n");
	return head;
	}
	
	struct Node* newNode = createNode(val);
	
	newNode->next = temp->next;
	temp->next = newNode;
	
	return head;
}

//Delete from the begining
struct Node* pop_front(struct Node* head){
	//empty list
	if(head == NULL){
	return NULL;
	}
	
	struct Node* temp = head;
	
	head = head->next;
	
	free(temp);
	
	return head;
}

//Delete from the end
struct Node* pop_back(struct Node* head){
	//empty list
	if(head == NULL){
	return NULL;
	}
	
	//Only one node
	if(head->next == NULL){
	free(head);
	return NULL;
	}
	
	struct Node* temp = head;
	
	//Go to the second last node
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	
	struct Node* deleteNode = temp->next;
	
	//delete the last node
	temp->next = NULL;
	free(deleteNode);
	
	return head;
}

//Delete from a specific position
struct Node* Delete(struct Node* head, int val){
	//empty list
	if(head == NULL){
	printf("List is empty!\n");
	return head;
	}
	
	
	//Delete first node
	if(head->data == val){
	return pop_front(head);
	}
	
	struct Node* temp = head;
	
	while(temp->next != NULL && temp->next->data != val){
	temp = temp->next;
	}
	
	//value not found
	if(temp->next == NULL){
	printf("Value Not found!\n");
	return head;
	}
	
	//create the node to delete
	struct Node* deleteNode = temp->next;
	
	//Remove the node
	temp->next = temp->next->next;
	
	free(deleteNode);
	
	return head;
}
