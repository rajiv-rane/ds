#include <stdio.h>
#include <stdlib.h>
typedef struct Node listptr;
typedef struct Node
{
    int data;
    listptr *next;
} listptr;

listptr *start = NULL, *ptr, *preptr, *postptr, *newnode;
// int ele;
void createSLL()
{
    int ele;
    printf("enter element to insert: ");
    scanf("%d", &ele);
    while (ele != 0)
    {
        newnode = (listptr *)malloc(sizeof(listptr));
        newnode->data = ele;
        if (start == NULL)
        {
            start = newnode;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("\ninsert 0 to stop Else insert next Element:");
        scanf("%d", &ele);
    }
}

void insert_beg()
{
    int ele;
    listptr *newnode, *ptr;
    newnode = (listptr *)malloc(sizeof(listptr));
    printf("\nenter element to insert @ beginning:\t");
    scanf("%d", ele);
    newnode->data = ele;
    // check if ll is empty
    if (start == NULL)
    {
        start = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

void insert_end()
{
    int ele;
    newnode = (listptr *)malloc(sizeof(listptr));
    printf("\nenter element to insert at END:\t");
    scanf("%d", &ele);
    newnode->data = ele;
    if (start == NULL)
    {
        start = newnode;
        start->next = NULL;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->next = NULL;
    }
}


void delete_beg(){
    listptr*ptr;
    if(start==NULL){
        printf("\nEMPTY LIST");
        return;
    }
    else{
        ptr=start;
        start=start->next;
        free(ptr);
    }
}

void delete_end(){
    listptr*ptr,*preptr;
    if(start==NULL){
        printf("\nEMPTY LIST");
        return;
    }   
    else{
        ptr=start;
        preptr=NULL;
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
    } 
}


void display(){
    listptr *ptr;
    if(start==NULL){
        printf("\nEMPTY LIST\n");
        return;
    }
    else{
        ptr=start;
        printf("\n");
        while(ptr!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int ch;
    while(1){
        printf("-------------Menu-----------\n");
        printf(" 1.Create SLL\n 2. Insert Beg\n 3. Insert End\n 4. Insert before\n 5. Insert after\n 6. Delete Beg\n 7.Delete end\n 8.Delete after\n 9.Delete Before \n 10. Delete a specific node\n 11.Display \n 12.Exit\n");
        printf("\nEnter your choice\n");
        switch(ch){
            case 1:createSLL();break;
            case 2:insert_beg();break;
            case 3:insert_end();break;
            // case 4:insert_bef();break;
            // case 5:insert_aft();break;
            case 6:delete_beg();break;
            case 7:delete_end();break;
            // case 8:delete_aft();break;
            // case 9:delete_bef();break;
            // case 10:delete_node();break;
            case 11:display();break;
            default:exit(0);
        }
    }
}
// void delete_aft(){
//     listptr *ptr, *postptr;
//     int val;
//     printf("After which node do you want to delete??\n");
//     scanf("%d",&val);
//     ptr=start;
//     postptr=ptr->next;
//     while(ptr->data!=val){
//         ptr =ptr->next;
//         postptr =postptr->next;
//     }
//     ptr->next=postptr->next;
//     free(postptr);
// }
// void delete_bef(){
//     listptr*ptr,*preptr,*postptr,*temp;
//     int val;
//     printf("Before which node do you want to delete??\n");
//     scanf("%d",&val);
//     ptr=start;
//     preptr=NULL;
//     postptr=ptr->next;
//     while(ptr->data!=val){
//         temp=preptr;
//         preptr=ptr;
//         ptr=ptr->next;
//     }
//     temp->next=preptr->next;
//     free(preptr);
// }

// void delete_node(){
//     listptr*ptr,*preptr,*postptr,*temp;
//     int val;
//     printf("which node do you want to delete??\n");
//     scanf("%d",&val);
//     ptr=start;preptr=NULL;
//     while(ptr->data!=val){
//         preptr=ptr;
//         ptr=ptr->next;
//     }
//     preptr->next=ptr->next;
//     free(ptr);
// }

// void insert_bef()
// {
//     int ele, val;
//     listptr *newnode, *ptr, *preptr;
//     newnode = (listptr *)malloc(sizeof(listptr));
//     printf("\nenter element to insert BEFORE a node:\t");
//     scanf("%d", &ele);
//     printf("\nBefore which node do you want to insert??\t");
//     scanf("%d", &val);
//     newnode->data = ele;

//     if (start == NULL)
//     {
//         newnode->next = NULL;
//         start = newnode;
//         return;
//     }

//     ptr = start;
//     preptr = NULL;
//     while (ptr != NULL && ptr->data != val)
//     {
//         preptr = ptr;
//         ptr = ptr->next;
//     }
//     if (ptr == NULL)
//     {
//         printf("\nNode %d not found", val);
//         free(newnode);
//         return;
//     }
//     if (preptr == NULL)
//     { // insert before 1st node
//         newnode->next = start;
//         start = newnode;
//     }
//     else
//     { // insert b/w nodes
//         preptr->next = newnode;
//         newnode->next = ptr;
//     }

//     return;
// }

// void insert_aft()
// {
//     int ele, val;
//     listptr *newnode, *ptr, *postptr;
//     newnode = (listptr *)malloc(sizeof(listptr));
//     printf("\nenter element to insert BEFORE a node:\t");
//     scanf("%d", &ele);
//     printf("\nBefore which node do you want to insert??\t");
//     scanf("%d", &val);
//     if (start == NULL)
//     {
//         newnode->next = NULL;
//         start = newnode;
//         return;
//     }
//     ptr=start;
//     while(ptr!=NULL && ptr->data!=val){
//         ptr=ptr->next;
//         postptr=ptr->next;
//     }
//     ptr->next=newnode;
//     newnode->next=postptr;
// }