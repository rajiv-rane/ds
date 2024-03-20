#include<stdio.h>
#include<stdlib.h>
typedef struct Tree treeptr;
typedef struct Tree{
   int data;
   treeptr*left,*right; 
} treeptr;
treeptr *root=NULL;

treeptr*insert(int val){
    treeptr*temp,*newnode,*prev;
    newnode=(treeptr*)malloc(sizeof(treeptr));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
        return root;
    }
    temp=root;

    while(temp!=NULL){
        if(val>temp->data){
            prev=temp;
            temp=temp->right;
        }
        else if(val<temp->data){
            prev=temp;
            temp=temp->left;
        }
        else{
            printf("\nDUPLICATES NOT ALLOWED");
            return root;
        }
    }
    if(val>prev->data)
        prev->right=newnode;
    else
        prev->left=newnode;
    return root;
}

void search(treeptr *root,int val){
    treeptr*temp=root;
    if(temp==NULL){
        return;
        printf("\nElement not found");
    }
    else if(val>temp->data)
        search(temp->right,val);
    else if(val<temp->data)
        search(temp->left,val);
    else if(val==temp->data)
        printf("\nELEMENT FOUND !");
}

void preorder(treeptr*root){
    treeptr*temp=root;
    if(temp==NULL)
        return;
    printf("%d\t",temp->data);
    preorder(temp->left);
    preorder(temp->right);

}
void inorder(treeptr*root){
    treeptr*temp=root;
    if(temp==NULL)
        return;
    
    inorder(temp->left);
    printf("%d\t",temp->data);
    inorder(temp->right);

}
void postorder(treeptr*root){
    treeptr*temp=root;
    if(temp==NULL)
        return;
    
    postorder(temp->left);
    postorder(temp->right);
    printf("%d\t",temp->data);
}


int main(){
    int ch=1,val,key;
    do{
        printf("\n-------------BST MENU---------------");
        printf("\n1.Insert\t2.preorder\t3.Inorder\t4.postorder\t5.search\t6.exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\ninsert element: ");
                    scanf("%d",&val);
                    root=insert(val);
                    break;
            case 2:preorder(root);break;
            case 3: inorder(root);break;
            case 4: postorder(root);break;
            case 5:printf("\nenter element to search: ");
                    scanf("%d",&key);
                    search(root,key);break;
            case 6:exit(0);
            
        }
    }while(ch>0);
}