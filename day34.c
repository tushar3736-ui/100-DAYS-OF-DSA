// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void push(int x){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}

int pop(){
    if(top==NULL)
        return -1;

    int val=top->data;
    struct Node* temp=top;
    top=top->next;
    free(temp);
    return val;
}

int main(){

    char exp[]="231*+9-";
    int i=0;

    while(exp[i]!='\0'){

        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            int b=pop();
            int a=pop();
            int res;

            switch(exp[i]){
                case '+': res=a+b; break;
                case '-': res=a-b; break;
                case '*': res=a*b; break;
                case '/': res=a/b; break;
            }

            push(res);
        }

        i++;
    }

    printf("%d",pop());

    return 0;
}