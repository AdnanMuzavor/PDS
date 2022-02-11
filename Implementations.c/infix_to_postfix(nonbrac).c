

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int stack[MAX] = {0};
int top = -1;
int isempty()
{
    if (top == -1)
        return 1;
    return 0;
}
int isfull()
{
    if (top + 1 == MAX)
        return 1;
    return 0;
}
void push(int x)
{
    if (!isfull())
    {
        top++;
        stack[top] = x;
    }
    else
        printf("Stack is full\n");
}
int pop()
{
    if (!isempty())
    {
        char x = stack[top];
        top--;
        return x;
    }
    printf("Stack is pop empty\n");
    return -1;
}
int peek()
{
    if (!isempty())
        return stack[top];
    else
        printf("Stack is empty\n");
    return -1;
}
void display()
{
    int i = top;
    printf("Elements of stack are: ");
    while (i >= 0)
    {
        printf("%c ", stack[i]);
        i--;
    }
    printf("\n");
}
int precedence(char a){
    if(a=='+' || a=='-') return 1;
    if(a=='*' || a=='/') return 2;
    if(a=='^' || a=='$') return 3;
    if(a=='(') return 0;
}
int isoperator(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'||a=='$'){
        return 1;
    }
    return 0;
}
void evaluate(char *post){
    int i=0;
    while(post[i]!='\0'){
        if(isoperator(post[i])){
            printf("\n");
            int b=pop();
            int a=pop();
            printf("a: %d, b: %d\n",a,b);
            int temp=0;
            switch(post[i]){
                case '+':
                temp=a+b;
                break;
                case '-':
                temp=a-b;
                break;
                case '*':
                temp=a*b;
                break;
                case '/':
                temp=a/b;
                break;
                case '$':
               
                case '^':
                temp=pow(a,b);
                break;
                default:
                temp=0;
            }
            printf("temp is: %d\n",temp);
            push(temp);
        }
        else{
            printf("pushing %d \n",post[i]-'0');
            push(post[i]-'0');
        }
        i++;
    }
    printf("\n final result is: %d\n",peek());
}
void postfix(char*infix){
    printf("\n");
    char post[20];
    int i=0,j=0;
    char popped;
    while(infix[i]!='\0'){
        if(infix[i]-'0'>=0 && infix[i]-'0'<=9){
           
          //If number push into postfix expression
            post[j]=infix[i];
            j++;
        }
        else{
          // printf("operand %c\n",infix[i]);
          //If operator
          if(isempty() || infix[i]=='('){
              push(infix[i]);
              display();
          }
          else if(infix[i]==')'){
              while( !isempty() && (popped=pop())!='('){
                  
                  post[j++]=popped;
                 
              }
            
          }
          else{
              if(precedence(infix[i])>precedence(peek())){
                  push(infix[i]);
              }
              else{
                  while(!isempty() && precedence(infix[i])<=precedence(peek())){
                      post[j++]=peek();
                      pop();
                  }
                  push(infix[i]);
              }
          }
            
        }
        i++;
    }
    while(!isempty()){
        post[j++]=peek();
        pop();
    }
    post[j]='\0';
    printf("\n");
    for(int i=0;i<j;i++){
        printf("%c",post[i]);
    }
    evaluate(post);
}
int main()
{
    int n;
    char exps[20];
    printf("Enter the expression\n");
    scanf("%s",exps);
    printf("expression is: %s",exps);
    postfix(exps);
    return 0;
}