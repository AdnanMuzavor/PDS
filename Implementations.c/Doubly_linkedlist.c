#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct node{
    int val;
    struct node*prev;
    struct node*next;
} node;
int l=0; //For length of DLL
node*head=NULL; //Pointer on first node
node*rear=NULL; //Pointer on last node

int isempty(){
    if(head==NULL) return 1;
    return 0;
}
int isfull(){
    if(l+1==MAX) return 1;
    return 0;
}

node* InsertInEmpty(int val){
    if(head==NULL){
        node*temp=(node*)malloc(sizeof(node));
        temp->val=val;
        head=rear=temp;
        head->prev=NULL;
        temp->next=NULL;
    }
    else{
        printf("\n List is not empty\n");
    }
    return head;
}
node* InsertAtBeginning(int data){
    if(isempty()) return InsertAtBeginning(data);
    else{
        node*temp=(node*)malloc(sizeof(node));
        temp->val=data;
        head->prev=temp;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
    return head;
}
node*InsertAtEnd(int data){
    if(isempty()) return InsertInEmpty(data);
    else{
        node*temp=(node*)malloc(sizeof(node));
        temp->val=data;
        rear->next=temp;
        temp->prev=rear;
        temp->next=NULL;
        rear=temp;
    }
    return head;
}
node* InsertAfterNode(int nodeval,int data){
    if(isempty()){
    printf("\nList is empty \n");
    return head;
    }
    else{
        node*temp=head;
        while(temp && temp->val!=nodeval){
            temp=temp->next;
        }
        if(temp==NULL) printf("\n %d not found in list\n",nodeval);
        else if(temp==rear) return InsertAtEnd(data);
        else{
            node*newnode=(node*)malloc(sizeof(node));
            newnode->val=data;
            newnode->next=temp->next;
            temp->next->prev=newnode;
            newnode->prev=temp;
            temp->next=newnode;
            printf("\nNode inserted after %d\n",nodeval);
        }
    }
    return head;
}
node* InsertBeforeVal(int nodeval,int data){
    if(isempty()){
        printf("\nList is empty\n");
        return head;
    }
    else{
        if(head->val==nodeval) return InsertAtBeginning(data);
        else{
            node*temp=head;
            while(temp && temp->val!=nodeval){
                temp=temp->next;
            }
            if(temp==NULL) printf("\n %d not found in list\n",nodeval);
            else{
                node*newnode=(node*)malloc(sizeof(node));
                newnode->val=data;
                temp->prev->next=newnode;
                newnode->prev=temp->prev;
                newnode->next=temp;
                temp->prev=newnode;
            }
        }
    }
    return head;
}
void traversal(){
    if(isempty()){
        printf("\n List is empty\n");
        return;
    }
    else{
        printf("\nList elements are: ");
        node*t=head;
        while(t){
            printf("%d ",t->val);
            t=t->next;
        }
        return;
    }
}
node* deletefirstnode(){
    if(isempty()) printf("\nList is empty\n");
    else{
        node*temp=head;
        head=head->next;
        head->prev=NULL;
        printf("Deleted value %d\n",temp->val);
        free(temp);
    }
    return head;
}
node* deletelastnode(){
    if(isempty()) printf("List is empty\n");
    else{
        node*temp=rear;
        rear=rear->prev;
        rear->next=NULL;
        printf("\nDeleted value %d\n",temp->val);
        free(temp);
        
    }
    return head;
}
node* deleteinbetween(int val){
    if(isempty()) printf("\n list is empty\n");
    else{
        node*temp=head;
        while(temp && temp->val!=val){
            temp=temp->next;
        }
        if(temp==NULL) printf("%d not found in list\n",val);
        if(temp==head) return deletefirstnode();
        else if(temp==rear) return deletelastnode();
        else {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            printf("\nDeleted value %d\n",temp->val);
            free(temp);
        }
    }
    return head;
}
node* deleteonlynode(){
    if(isempty()) printf("List is empty\n");
    else{
        if(head->next!=NULL)printf("It's not the only node\n");
        else{
            printf("Deleted node: %d\n",head->val);
            node*temp=head;
            head=rear=NULL;
            free(temp);
        }
    }
    return head;
}
node* reverse(){
    node* curr=head;
    node*prev=NULL;
    node*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=curr->prev;
    }
    head=prev;
    return head;
}
int main()
{
     int n,m;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 to insert in empty\n2 to insert at beginning\n3 to insert at end\n4 to insert after node\n5 to insert before node\n6 for display\n7 to delet first node\n8 to delete last node\n9 to delete in between node\n10 to delete only node\n11 for reverse\n12 to exit\nYour choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element you want to insert: ");
            scanf("%d", &n);
            head=InsertInEmpty(n);
            break;
        case 2:
            printf("Enter element you want to insert: ");
            scanf("%d", &n);
            head=InsertAtBeginning(n);
            break;
        case 3:
            printf("Enter element you want to insert: ");
            scanf("%d", &n);
            head=InsertAtEnd(n);
            break;
        case 4:
            printf("Enter element you want to insert: ");
            scanf("%d", &n);
            printf("Enter node after which you want to insert: ");
            scanf("%d", &m);
            head=InsertAfterNode(m,n);
            break;
        case 5:
            printf("Enter element you want to insert: ");
            scanf("%d", &n);
            printf("Enter node before which you want to insert: ");
            scanf("%d", &m);
            head=InsertBeforeVal(m,n);
            break;  
        case 6:
            traversal();
            break;
        case 7:
        head=deletefirstnode();
        break;
        case 8:
        head=deletelastnode();
        break;
        case 9:
        printf("Enter element you want to insert: ");
        scanf("%d", &n);
        head=deleteinbetween(n);
        break;
        case 10:
        head=deleteonlynode();
        break;
        case 11:
        head=reverse();
        break;
        case 12:
            exit(1);
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}