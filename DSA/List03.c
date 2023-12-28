//Manoj Puttaswamy
//Reversal of the Linked list implementation using Recurcive function. 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        head = temp; return;
    }
    struct Node* temp1 = head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next = temp;
}
void Reverse(struct Node* temp){
    struct Node* prev;
    // exit condition
    if(temp->next == NULL){
        head = temp;
        return;
    }
    Reverse(temp->next);
    prev = temp->next;
    prev->next = temp;
    temp->next = NULL;
}
void Delete(){
    struct Node* prev;
    struct Node* temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void Print(){
    struct Node* temp1 = head;
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}
int main() {
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    Delete();
    Print();
    Reverse(head);
    Print();
    return 0;
}