#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define N 50
char stack[N];
int top=-1;
void push(char item){
    stack[++top]=item;
}
char pop(){
    return stack[top--];
}
int precedence(char symbol){
    switch(symbol){
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':
        case '$':return 4;
        default: return 0;
    }
}

int main(){
    char postfix[20],infix[20];
    printf("enter infix: ");
    scanf("%s",infix);
    int i,j=0;
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')'){
            while(stack[top]!='(')
                postfix[j++]=pop();
            top--;
        }
        else{
            while(precedence(stack[top])>=precedence(infix[i])){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("\npostfix = %s",postfix);
}