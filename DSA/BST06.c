//Manoj Puttaswamy
// Check if Binary tree is a Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left,* right;
};
struct Node* root = NULL;
int flag;
struct Node* GetNewNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
}
void Search(int data){
    struct Node* temp = root;
    while(temp->left != NULL && temp->right != NULL){
        if(temp->data <= data) {
            temp=temp->right;
        }
        else {
            temp=temp->left;
        }
    }
    if(temp->data == data) printf("%d",data);
    else printf("Data not Found");
}
void Insert(int data){
    struct Node* temp = GetNewNode(data);
    if(root == NULL){
        root = temp;
        return;
    }
    struct Node* temp1 = root;
    while(temp1->left != NULL && temp1->right != NULL){
        if(temp->data <= temp1->data) {
            temp1=temp1->left;
        }
        else {
            temp1=temp1->right;
        }
    }
    if(temp->data <= temp1->data) temp1->left = temp;
    else temp1->right = temp;   
}
void FindMin(){
    struct Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    printf("Min=%d",temp->data);
}
void FindMax(){
    struct Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    printf("Min=%d",temp->data);
}
int isBST(struct Node* temp){
    if(temp->left ==NULL && temp->right == NULL) return flag;
    if (temp->left->data <= temp->data && temp->right->data > temp->data) flag = 1;
    else flag = 0;
    isBST(temp->left);
    isBST(temp->right);
    
}
int main() {
    Insert(15);
    Insert(10);
    Insert(20);
    Insert(12);
    Insert(8);
    Insert(16);
    Insert(25);
    isBST(root);
    if(flag == 1) printf("Binary Search Tree");
    else printf("Not a Binary Search Tree");
    return 0;
}