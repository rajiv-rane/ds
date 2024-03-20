#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100],pat[50],rep[50],ans[100];
int i,m,c,j,k,flag=0;
void stringMatcher(){
    i=c=m=j=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            m++;i++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++)
                    ans[j]=rep[k];
                c=m;
                i=0;
            }
        }
        else{
            ans[j++]=str[c++];
            m=c;
            i=0;
        }
    }
    ans[j]='\0';
}
int main(){
    printf("\nenter string: ");
    gets(str);
    printf("\nEnter pattern: ");
    gets(pat);
    printf("\nenter replace : ");
    gets(rep);
    stringMatcher();
    if(flag==1)
        printf("\n%s",ans);
    else    
        printf("\npattern not FOUND!");
    return 0;
}