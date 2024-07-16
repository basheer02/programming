#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
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

/*void levelTraverse(struct Node *root){

    //que->front
    struct Que *front = NULL,*rear = NULL;
    struct Node *temp = root;
    while(temp != NULL){
        printf(" %d ",temp->data);

       // if(temp->left != NULL){
            struct Que *lnode = (struct Que *)malloc(sizeof(struct Que));
            lnode->node = temp->left;
            lnode->next = NULL;
            if(front == NULL){
                front = lnode;
                rear = lnode;}
            else{
                rear->next = lnode;
                rear = lnode;
            }
       // }  
       // if(temp->right != NULL){
            struct Que *rnode = (struct Que *)malloc(sizeof(struct Que));
            rnode->node = temp->right;
            rnode->next = NULL;
            rear->next = rnode;
            rear = rnode;
       // } 
        temp = front->node;
        front = front->next;
    }
}*/

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

struct Node *createTreeMirror(struct Node *newTree,int data){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(newTree == NULL)
        newTree = temp;
    else{
        if(data < newTree->data)
            newTree->right = createTreeMirror(newTree->right,data);
        else if(data > newTree->data)
            newTree->left = createTreeMirror(newTree->left,data);
    }

    return newTree;
}

void treeMirror(struct Node *tree){

   // struct Node *ptr = tree;
    if(tree == NULL)
        return;
    newTree = createTreeMirror(newTree,tree->data);
    treeMirror(tree->left);
    treeMirror(tree->right);
}

/*bool areIdentical(struct Node *root1, struct Node *root2)
{
    /* base cases 
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 == NULL || root2 == NULL)
        return false;
 
    /* Check if the data of both roots is same and data of left and right
       subtrees are also same 
    return (root1->data == root2->data   &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}

bool isSubtree(struct Node *T, struct Node *S)
{
    /* base cases 
    if (S == NULL)
        return true;
 
    if (T == NULL)
        return false;
 
    /* Check the tree with root as current node 
    if (areIdentical(T, S))
        return true;
 
    /* If the tree with root as current node doesn't match then
       try left and right subtrees one by one 
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}*/

void inorder(struct Node *temp,int space){

    if(temp == NULL)
        return;

    space += 10;
    inorder(temp->right,space);
    printf("\n");
    for(int i =count; i < space; i++)
        printf(" ");
    printf("%d\n",temp->data);
    inorder(temp->left,space);

}

void postorder(struct Node *temp){

    if(temp == NULL)
        return;
    printf(" %d ",temp->data);
    postorder(temp->left);
    postorder(temp->right);

}

/*void mirrorImage(struct Node *temp,int space){

    if(temp == NULL)
        return;

    space += count;
    inorder(temp->left,space);
    printf("\n");
    for(int i =count; i < space; i++)
        printf(" ");
    printf("%d\n",temp->data);
    inorder(temp->right,space);

}

int degree(struct Node *root){

    if(root == NULL)
        return -1;
    int l = degree(root->left);
    int r = degree(root->right);
    return (l > r) ? l+1 : r+1;
}

void levelSum(struct Node *root,int level,int arr[]){

    if(root == NULL)
        return;
    arr[level] += root->data;
    levelSum(root->left,level+1,arr);
    levelSum(root->right,level+1,arr);
}*/

//struct Node *ptr = NULL;
int h = 0;

int Height(struct Node *root){
    if(root == NULL)
        return -1;
    int r = Height(root->left);
    int l = Height(root->right);
    h = (l > r) ? l+1 : r+1;
}

void findHeight(struct Node *root,int key){
    if(root == NULL)
        return;
    int dis = -1;
    if(root->data == key){
        Height(root);
    }
    findHeight(root->left,key);
    findHeight(root->right,key);
}
int findDepth(struct Node *root,int key){
    if(root == NULL)
        return -1;
    int dis = -1;
    if((root->data == key) || (dis = findDepth(root->left,key)) >= 0 || 
           (dis = findDepth(root->right,key)) >= 0 ) {
        return dis + 1;
    }
    return dis;

   // }
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
    printf("\n Image of tree\n");
    inorder(tree,0);
    //printf(" Level tree : ");
    //levelTraverse(tree);
    int depth = findDepth(tree,10);
    printf(" Depth of 10 : %d ",depth);
    findHeight(tree,10);
    printf("\n Height of 10 : %d ",h);
    /*printf(" Preorder : ");
    postorder(tree);
    treeMirror(tree);
    printf("\n Mirror image of tree\n");
    inorder(newTree,0);*/



   /* printf("\n Enter -1 for null ");
    printf("\n\n Tree 1 ");
    struct Node *tree1 = binaryTree(tree1,1);
   // printf("\n\n Tree 2 ");
   // struct Node *tree2 = binaryTree(tree2,10);


    printf(" tree 1 : "); 
    inorder(tree1,0);
    //printf("\n\n = %d\t  = %d\t  = %d",r1,r2,r3);
    int level = degree(tree1);
    printf("\n levels : %d\n",level);
    int sumArr[level+1] = {0};
    levelSum(tree1,0,sumArr);
    for(int i = 0; i < level+1; i++)
        printf("\n sum of level %d : %d",i,sumArr[i]);
    /*printf("\n tree 2 : "); 
    inorder(tree2);*/
    printf("\n");

    /*if(isSubtree(tree1,tree2))
        printf("\n tree2 is sub tree of tree1 \n");
    else
        printf("\n tree2 is not a sub tree of tree1 \n");*/
}