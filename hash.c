#include<stdio.h>
#include<stdlib.h>
#define N 10
int f[N],HT[N]={0},L;
int id,salary;
char name[10];

void probe(int k,int key){
    L=k%N;
    if(HT[L]==0){
        HT[L]=key;
    }
    else 
        probe(k+1,key);
}
void display(){
    printf("\nHASH TABLE:");
    for(int i=0;i<N;i++){
        printf("\nHT[%d]=%d",i,HT[i]);
    }
}
int main(){
    int i=0;
    FILE *fp=fopen("emp.txt","r");
    printf("\nFILE Contents: ");
    do{
        fscanf(fp,"%d %s %d",&id,name,&salary);
        printf("\n%d %s %d",id,name,salary);
        f[i++]=id;

    }while(!feof(fp));

    for(i=0;i<N;i++){
        L=f[i]%N;
        if(HT[L]==0)
            HT[L]=f[i];
        else
            probe(f[i]+1,f[i]);
    }
    display();
    return 0;
}