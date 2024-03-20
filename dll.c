#include<stdio.h>
#include<stdlib.h>
typedef struct node listptr;
typedef struct node{
    char ssn[10],name[10],dept[10],desg[10],ph[10],sal[10];
    listptr *prev,*next;
}listptr;

listptr *start,*ptr,*newnode,*preptr,*temp;
int count=0;
void createNode(){
    newnode=(listptr*)malloc(sizeof(listptr));
    printf("\nenter [ssn,name,dept,desg,ph,sal]:\t");
    scanf("%s%s%s%s%s%s",newnode->ssn,newnode->name,newnode->dept,newnode->desg,newnode->ph,newnode->sal);
    count++;
}
void createList(){
    createNode();
    start=newnode;
    start->next=NULL;
    start->prev=NULL;
}
void insertFront(){
    createNode();
    ptr=start;
    newnode->next=ptr;
    newnode->prev=NULL;
    start->prev=newnode;
    start=newnode;
}
void deleteFront(){
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    count--;
    printf("\nNode deleted...");
}
void insertLast(){
    createNode();
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=NULL;
}
void deleteLast(){
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    count--;
    printf("\nNode deleted...");

}
void display(){
    ptr=start;
    printf("\nHEAD<=>");
    while(ptr!=NULL){
        printf("[%s %s %s %s %s %s]<=>",ptr->ssn,ptr->name,ptr->dept,ptr->desg,ptr->ph,ptr->sal);
        ptr=ptr->next;
    }
    printf("\tCOUNT:%d\n",count);
}

int main(){
    printf("\t\t-------------------DLL demo-------------------");
    printf("\ncreate a Doubly Linked list node with a single element: ");
    createList();
    int choice=1;
    while(choice){
        printf("\n-------------------DLL demo-------------------");
        printf("\n1.InsertFront\t2.Delete front\t3.InsertLast\t4.DeleteLast\t5.display\t6.Exit");
        printf("\n-------------------------------------------------------------------------------------");
        printf("enter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:insertFront();break;
            case 2:deleteFront();break;
            case 3: insertLast();break;
            case 4:deleteLast();break;
            case 5:display();break;
            default:exit(0);break;
            
        }
    }
    return 0;
}
    