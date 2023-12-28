//Manoj Puttaswamy
//Insertion and deletion at the beginning of the Linked list implementation using struct 
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
    temp->next = head;
    head = temp;
}
void Delete(){
    struct Node* temp = head;
    head = temp->next;
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
    return 0;
}