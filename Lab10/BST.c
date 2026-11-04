//Q] Write a program to create a binary search tree on n data elements using lined list and perform the following menu given operations:
    //1. PreOrder Traversal
    //2. PostOrder Traversal
    //3. InOrder Traversal
    //4. Search an element

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

//creating a node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//inserting the nodes in the binary search tree
struct node *insert(struct node *root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    } else if(data > root->data){
        root->right = insert(root->right, data);
    }

    return root;
}

//functions declarations
void preOrder(struct node *root);
void postOrder(struct node *root);
void inOrder(struct node *root);
void search(struct node *root, int key);

int main(){
    struct node *root = NULL;
    
    int n;
    printf("Enter the number of nodes to insert in BST : ");
    scanf("%d", &n);

    int data;
    printf("Enter the elements to insert in BST : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("BST created successfully!\n");

    while(1){
        printf("\n<------ BST OPERATIONS -------->\n");
        printf("1.PreOrder\n");
        printf("2.PostOrder\n");
        printf("3.InOrder\n");
        printf("4.Search an element\n");
        printf("5.Exit\n");

        int choice;
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1 : printf("PreOrder : ");
                    preOrder(root);
                    printf("\n");
                    break;

            case 2 : printf("PostOrder : ");
                    postOrder(root);
                    printf("\n");
                    break;

            case 3 : printf("InOrder : ");
                    inOrder(root);
                    printf("\n");
                    break;

            case 4 : search(root, data);
                    break;

            case 5 : printf("Program Terminated.\n"); 
                    exit(0);
                    break;

            default: printf("Invalid Choice! Please try again.\n");
        }
    }

    return 0;
}


//functions definations

//pre-Order traversal
void preOrder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//post-Order traversal
void postOrder(struct node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

//in-Order traversal
void inOrder(struct node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

//searching a node in the binary search tree
void search(struct node *root, int key){
    printf("Enter the element to search in BST : ");
    scanf("%d", &key);

    while(root != NULL){
        if(root->data == key){
            printf("%d found in BST.\n", key);
            return;
        } else if(key < root->data){
            root = root->left;
        } else {
            root = root->right;
        }
    }

    printf("%d not found in BST.\n", key);
}

