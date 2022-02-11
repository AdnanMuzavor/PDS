

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct node{
    int val;
    struct node*next;
} node;
int l=0; //For length of DLL
node*front=NULL; //Pointer on first node
node*rear=NULL; //Pointer on last node

int isempty(){
    if(front==NULL ) return 1;
    return 0;
}
int isfull(){
    if(l+1==MAX) return 1;
    return 0;
}
node*enqueue(int val){
    node*temp=(node*)malloc(sizeof(node));
    temp->val=val;
    if(isempty()){
     front=rear=temp;
     front->next=front;
      
        
    }
    else{
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
    }
    return front;
}
node* dequeue(){
    if(isempty()) printf("List is empty\n");
    else{
        node*temp=front;
        if(front==rear){
            front=rear=NULL;
        }
        else{
        rear->next=front->next;
        front=front->next;
        }
        printf("Dequeued %d\n",temp->val);
        free(temp);
    }
    return front;
}
void peek(){
    if(isempty()) printf("List is empty\n");
    else{
        printf("Peek is: %d\n",front->val);
    }
}
void display(){
    if(isempty()) printf("List is empty\n");
    else{
        printf("List elements are: ");
        node*temp=front;
        do{
            printf("%d ",temp->val);
            temp=temp->next;
        }while(temp!=front);
        printf("\n");
    }
}
int main()
{
     int n;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 to enqueue\n2 to dequeue\n3 to get peek\n4 for display\n5 for exit\nYour choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element you want to enqueue: ");
            scanf("%d", &n);
            front=enqueue(n);
            break;
        case 2:
            front=dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}