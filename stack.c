#include <stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top = -1, count = 0;
int item;
// push pop display palindrome

void push(int item)
{
    if (top == N - 1)
    {
        printf("\nstack overflow");
        return;
    }

    else
    {
        stack[++top] = item;
        count++;
    }
}
int pop()
{
    int ret = 0;
    if (top == -1)
    {
        printf("\nstack underflow");
        return 0;
    }
    else
    {
        ret = stack[top--];
        count--;
    }
    return ret;
}

void display()
{
    if (top == -1)
        printf("\nempty stack!");
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n-----\n");
            printf("| %d |", stack[i]);
        }
    }
}


void palindrome(){
    for(int i=0;i<=(top+1)/2;i++){
        if(stack[i]!=stack[(top+1)-i-1]){
            printf("\nNOT palindrome");
            return;
        }
    }
    printf("\nIt IS A PALINDROMe");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n");
        printf("--------STACK  IMPLEMENTATION----------");
        printf("\n1.PUSH 2.POP 3.PALINDROME CHECKING 4.Exit");
        printf("\n-----------------------------------------");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a single digit element to be pushed: ");
            scanf("%d", &item);
            push(item);
            display();
            break;
        case 2:
            item = pop();
            if (item != 0)
                display();
            break;
        case 3:
            palindrome();
            break;
        case 4:
            printf("You Exited the program\n\n");
            exit(0);
            break;
        default:
            return 0;
        }
    }
    return 0;
}