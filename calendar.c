#include<stdio.h>
#include<stdlib.h>
struct Day{
    int date;
    char* dayName;
    char* activity;
};

void create(struct Day calendar[],int size){
    for(int i=0;i<size;i++){
        calendar[i].dayName=NULL;
        calendar[i].activity=NULL;
    }
}

void read(struct Day calendar[],int size){
    for(int i=0;i<size;i++){
        calendar[i].dayName=(char*)malloc(sizeof(char)*20);
        calendar[i].activity=(char*)malloc(sizeof(char)*20);
        printf("\nenter the details for Day %d",i);
        printf("\nenter Date: ");
        scanf("%d",&calendar[i].date);
        printf("\nenter Dayname: ");
        scanf("%s",calendar[i].dayName);
        printf("\nenter activity: ");
        scanf("%s",calendar[i].activity);
    }
}
void display(struct Day calendar[],int size){
    printf("\nWeek's activity details report:\n");
        for(int i=0;i<size;i++){
            printf("\nDay\tDayName\t\tDate\tactivity");
            printf("\n%d\t%s\t%d\t%s",i+1,calendar[i].dayName,calendar[i].date,calendar[i].activity);
        }
}

int main(){
    int numdays=7;
    struct Day* calendar=(struct Day*)malloc(sizeof(struct Day)*7);
    if(calendar==NULL)
        return 1;
    create(calendar,numdays);
    read(calendar,numdays);
    display(calendar,numdays);
    return 0;
}