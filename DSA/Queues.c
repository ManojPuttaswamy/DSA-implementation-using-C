//Manoj Puttaswamy
//Queue implementation in c using structure 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void Enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next=NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
    }
    rear->next = temp;
    rear = temp;
}
void Dequeue(){
    if (front == NULL) {
        printf("Empty queue");
        return;
    }
    struct Node* temp = front;
    front = temp->next;
    free(temp);
}
void Peek(){
    printf("%d\n",front->data);
}
void Print(){
    struct Node* temp1 = front;
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}
int main() {
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Print();
    Peek();
    Dequeue();
    Print();
    Peek();
    return 0;
}