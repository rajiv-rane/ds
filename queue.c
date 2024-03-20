#include <stdio.h>
#include <conio.h>
#define max_queue_size 4

int front = 0, rear = 0, count = 0, i, item;
char q[4];

void insertq(char item)
{

    rear = (rear + 1) % max_queue_size;
    if (front == rear && count == max_queue_size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q[rear] = item;
        count++;
    }
}

char deleteq()
{
    if (front == rear && count == 0)
        printf("EMPTY QUEUE\t\t\t");
    else
    {
        front = (front + 1) % max_queue_size;
        item = q[front];
        q[front] = 0;
        count--;
    }
    return item;
}

void display()
{
    printf("CIRCULAR QUEUE\t\t");
    printf("\n-------------------------------------------------------------------------");
    printf("\n0\t1\t2\t3\tFRONT\tREAR\tCOUNT");
    printf("\n-------------------------------------------------------------------------\n");
    if (front == rear && count == 0)
        printf("EMPTY QUEUE");
    else
    {
        for (i = 0; i < 4; i++)
            printf("%c\t", q[i]);
    }
    printf("%d\t%d\t%d", front, rear, count);
}

int main()
{
    int choice = 1;
    while (choice)
    {
        printf("\n---------CIRCULAR QUEUE OPERATIONS----------------------------");
        printf("\n1.Insert\t 2.Delete\t 3.Display\t 4.Exit");

        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Insert\t");
            scanf("\n%c", &item);
            insertq(item);
            display();
            break;
        case 2:
            printf("Deleted\t%c\n", deleteq());
            display();
            break;
        case 3:
            display();
            break;
        default:
            return 0;
            break;
        }
    }
    return 0;
}