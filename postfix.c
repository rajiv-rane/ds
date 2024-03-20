#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
float compute(char s,float op1,float op2){
    switch(s){
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        // case '%':return op1 %op2;
        case '^':return pow(op1,op2);
        default: return 0;
    }
}
int main(){
    char postfix[20];
    printf("\nenter postfix expression:");
    scanf("%s",postfix);
    float res; float stack[10];int top=-1;int i;
    char symbol; float op1,op2;
    for(int i=0;i<strlen(postfix);i++){
        symbol=postfix[i];
        if(isdigit(symbol))
            stack[++top]=symbol-'0';
        else{
            op2=stack[top--];
            op1=stack[top--];
            res=compute(symbol,op1,op2);
            stack[++top]=res;
        }
    }
    res=stack[top--];
    printf("\nans=%f",res);
}