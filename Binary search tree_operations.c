#include<stdio.h>
#include<malloc.h>
struct node{
struct node*parent;
int data;
struct node*left;
struct node*right;

}*head=NULL;

void insert(int n){
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->parent=NULL;
temp->data=n;
temp->left=NULL;
temp->right=NULL;
if (head==NULL){
    head=temp;
    temp->parent=NULL;
}
else{
    struct node*temp1=head;
    while(temp1!=NULL){
    if (n<temp1->data ){
        if (temp1->left==NULL ){
        temp1->left=temp;
        temp->parent=temp1;
        temp1=NULL;
        }
        else{
            temp1=temp1->left;
        }

        }
    else{
        if (n>temp1->data){
        if(temp1->right==NULL ){
        temp1->right=temp;
        temp->parent=temp1;
        temp1=NULL;
        }
        else{
            temp1=temp1->right;

            }
        }
        }
}
}
}
struct node*maximum(struct node*temp2){
while(temp2->right!=NULL){
    temp2=temp2->right;
}
return temp2;

}
void transplant(struct node*u,struct node*v){
    if(u->parent==NULL){
        head=v;
    }
    else{
    if(u==u->parent->left){
        u->parent->left=v;
    }
    else{
        u->parent->right=v;
    }
    }
    if (v!=NULL){
        v->parent=u->parent;
    }

}
struct node *minimum(struct node*temp2){
while(temp2->left!=NULL){
    temp2=temp2->left;
}
return temp2;


}

void deletion(int n){
struct node*temp=head;
while(temp!=NULL && temp->data!=n){
    if (n<temp->data )
        {
        temp=temp->left;
        }


    else{
        temp=temp->right;

        }
    }

    if (temp!=NULL){
    if(temp->left==NULL){
        transplant(temp,temp->right);
    }
    else{
        if(temp->right==NULL){
            transplant(temp,temp->left);
        }
        else{
            struct node*y=minimum(temp->right);
            if (y->parent!=temp){
                transplant(y,y->right);
                y->right=temp->right;
                y->right->parent=y;

            }
            transplant(temp,y);
            y->left=temp->left;
            y->left->parent=y;
        }
    }

    }


}


int searching(struct node*temp1){
    int n;
    printf("\n Enter the value to search : \n ");
    scanf("%d",&n);
    while(temp1!=NULL && temp1->data!=n){
    if (n<temp1->data )
        {
        temp1=temp1->left;
        }


    else{
        temp1=temp1->right;

        }
    }
    if (temp1!=NULL){
        return 1;
            }
    else{
        return 0;
    }
}


struct node*successor(){
    int n;
    printf("\n Enter the value To find Successor of it :  \n");
    scanf("%d",&n);
    struct node*temp1=head;
    while(temp1!=NULL && temp1->data!=n){
    if (n<temp1->data )
        {
        temp1=temp1->left;
        }


    else{
        temp1=temp1->right;

        }
    }

    if (temp1!=NULL){
        if (temp1->right!=NULL){
            struct node *x=minimum(temp1->right);
            return x;
        }
        struct node*y=temp1->parent;
        while(y!=NULL && temp1==y->right){
            temp1=y;
            y=y->parent;
        }
        return y;
        }



}

struct node*predeccessor(){
    int n;
    printf("\n Enter the value To find predeccessor of it :  \n");
    scanf("%d",&n);
    struct node*temp1=head;
    while(temp1!=NULL && temp1->data!=n){
    if (n<temp1->data )
        {
        temp1=temp1->left;
        }


    else{
        temp1=temp1->right;

        }
    }

    if (temp1!=NULL){
        if (temp1->left!=NULL){
            struct node *x=maximum(temp1->left);
            return x;
        }
        struct node*y=temp1->parent;
        while(y!=NULL && temp1==y->left){
            temp1=y;
            y=y->parent;
        }
        return y;
        }



}


void display(struct node*temp2){
 if(temp2!=NULL){
display(temp2->left);
printf("\n %d",temp2->data);
display(temp2->right);

}
}
void preorder(struct node*temp2){
if(temp2!=NULL){
printf("\n %d",temp2->data);
preorder(temp2->left);
preorder(temp2->right);
}
}

void postorder(struct node*temp2){
if(temp2!=NULL){
postorder(temp2->left);
postorder(temp2->right);
printf("\n %d",temp2->data);
}
}

int main(){
int c;
int k;
while(1){
int n;
printf("\n 1.Insertion 2.Inorder traversal 3.Preorder traversal 4.Post order 5.Minimum 6.Maximum 7.Searching 8.Successor 9.predecessor 10.Deletion 11.Exit \n ");
scanf("%d",&c);
struct node*k1;
switch(c){
case 1:
    printf("Enter the value for node :");
    scanf("\n %d",&n);
    insert(n);
    break;
case 2:
    printf("\n Inorder traversal of tree is : \n");
    display(head);
    break;
case 3:
    printf("\n Preorder traversal of tree is : \n");
    preorder(head);
    break;
case 4:
    printf("\n Postorder traversal of tree is : \n");
    postorder(head);
    break;
case 5:
    k1=minimum(head);
    printf("\n The minimum value in the tree is  : %d ",k1->data);
    break;
case 6:
    k1=maximum(head);
    printf("\n The maximum value in the tree is  : %d ",k1->data);
    break;
case 7:
    k=searching(head);
    if (k==1){
    printf("\n Element found");
    }
    else{
        printf("\n Element not found");
    }
    break;
case 8:k1=successor();
        if (k1!=NULL){
        printf("\n Successor is : %d",k1->data);
        }
        else{
            if(k1==NULL){
            printf("\n maximum value in the tree");
            }
        }
        break;
case 9:
     k1=predeccessor();
     if (k1!=NULL){
        printf("\n Successor is : %d",k1->data);
        }
        else{
            if(k1==NULL){
            printf("\n minimum value in the tree");
            }
        }
     break;
case 10:
    printf("\n Enter the value to delete :\n");
    scanf("%d",&k);
    deletion(k);
    break;
case 11:
    return 0;

}

}
}
