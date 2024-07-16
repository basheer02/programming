#include<stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node *root = NULL;

struct Node *createNode(int data){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;

    return temp;
}

struct Node *insert(struct Node *node,int key){

    if(node == NULL)
        return createNode(key);
    else if(key < node->data)
        node->left = insert(node->left,key);
    else    
        node->right = insert(node->right,key);

    return node;
}

void inorder(struct Node *node){

    if(node != NULL){
        inorder(node->left);
        printf(" %d ",node->data);
        inorder(node->right);
    }
}

void postorder(struct Node *node){

    if(node != NULL){
        inorder(node->left);
        inorder(node->right);
        printf(" %d ",node->data);
    }
}

void preorder(struct Node *node){

    if(node != NULL){
        printf(" %d ",node->data);
        inorder(node->left);
        inorder(node->right);
    }
}
int main(){

    root = insert(root,27);
    insert(root,14);
    insert(root,35);
    insert(root,10);
    insert(root,19);
    insert(root,31);
    insert(root,42);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

}