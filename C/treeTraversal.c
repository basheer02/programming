#include<stdio.h>
#include<malloc.h>
#define count 10

struct Node{

    int data;
    struct Node *left,*right;
};

struct Que{
    struct Node *node;
    struct Que *next;
};
struct Node *newTree = NULL;
//struct Que que = NULL;

struct Que *levelTraverse(struct Node *root){

    //que->front
    struct Que *front = NULL,*rear = NULL,*ptr = NULL;
    struct Node *temp = root;
    while(temp != NULL){
        //printf(" %d ",temp->data);
       // if(temp->left != NULL){
            struct Que *lnode = (struct Que*)malloc(sizeof(struct Que));
            lnode->node = temp->left;
            lnode->next = NULL;
            if(front == NULL)
                front = rear = ptr = lnode;
            else{
                rear->next = lnode;
                rear = lnode;
            }
            struct Que *rnode = (struct Que*)malloc(sizeof(struct Que));
            rnode->node = temp->right;
            rnode->next = NULL;
            if(front == NULL)
                front = rear = ptr = rnode;
            else{
                rear->next = rnode;
                rear = rnode;
            }
           // rear->next = rnode;
           // rear = rnode;
        //}
        temp = front->node;
        front = front->next;
    }
    return ptr;
}

/*struct Node * binaryTree(struct Node *tree,int data){

    int key;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(data == -1)
        return 0;
    temp->data = data;
    printf("\n Enter left child of %d : ",data);
    scanf("%d",&key);
    temp->left = binaryTree(temp->left,key);
    printf("\n Enter right child of %d : ",data);
    scanf("%d",&key);
    temp->right = binaryTree(temp->right,key);
    return temp;
}*/

struct Node * binarySearchTree(struct Node *tree,int data){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(tree == NULL)
        tree = temp;
    else{
        if(data < tree->data)
            tree->left = binarySearchTree(tree->left,data);
        else if(data > tree->data)
            tree->right = binarySearchTree(tree->right,data);
    }

    return tree;
}

void inorder(struct Node *temp,int space){

    if(temp == NULL)
        return;

    space += count;
    inorder(temp->right,space);
    printf("\n");
    for(int i =count; i < space; i++)
        printf(" ");
    printf("%d\n",temp->data);
    inorder(temp->left,space);

}

int main(){


   // struct Node *newTree = NULL;
    struct Node *tree = binarySearchTree(tree,26);
    binarySearchTree(tree,20);
    binarySearchTree(tree,10);
    binarySearchTree(tree,15);
    binarySearchTree(tree,22);
    binarySearchTree(tree,50);
    binarySearchTree(tree,40);
    binarySearchTree(tree,60);
    binarySearchTree(tree,45);
    binarySearchTree(tree,55);
    binarySearchTree(tree,70);
    binarySearchTree(tree,5);
    printf("\n Image of tree\n");
    inorder(tree,0);
    printf(" Level tree : ");
    struct Que *q = levelTraverse(tree);
    while(q != NULL){
        printf(" %d ",q->node->data);
        q = q->next;
    }
    printf("\n");
    /*printf(" Preorder : ");
    postorder(tree);
    treeMirror(tree);
    printf("\n Mirror image of tree\n");
    inorder(newTree,0);*/



   /* printf("\n Enter -1 for null ");
    printf("\n\n Tree 1 ");
    struct Node *tree1 = binaryTree(tree1,1);
   // printf("\n\n Tree 2 ");
   // struct Node *tree2 = binaryTree(tree2,10);*/
}