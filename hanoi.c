#include<stdio.h>
#include<math.h>
void tower(int n,char BEG,char AUX,char END){
    if(n==0)
        return;
    tower(n-1,BEG,END,AUX);
    printf("\ndisc %d moves from %c to %c",n,BEG,END);
    tower(n-1,AUX,BEG,END);
}
int main(){
    printf("enter the number of discs: ");
    int n;scanf("%d",&n);
    tower(n,'A','B','C');
    int res=(int)(pow(2,n)-1);
    printf("\nTotal number of moves = %d",res);
}