//Manoj Puttaswamy
//stack implementation using struct 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Pop(){
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
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Print();
    Pop();
    Print();
    return 0;
}