#include<stdio.h>

void DFS(int);
int G[10][10],visited[10],n;
int q[20],i,j,f=0,r=-1;

void reset(){
    for(int i = 0; i < n; i++)
        visited[i] = 0;
}

void DFS(int i){
    printf("\n %d",i);
    visited[i] = 1;
    for(int j = 0; j < n; j++){
        if(!visited[j] && G[i][j] == 1)
            DFS(j);
    }
}

void BFS(int v){
    printf("\n%d",v);
    for(i = 0; i < n; i++){
        if(G[v][i] && !visited[i]){
            q[++r] = i;
            visited[i] = 1;
        }
    }
    if(f <= r){
        //visited[q[f]] = 1;
        BFS(q[f++]);
    }
}

void main(){

    int ch,v;
    printf("\n Enter the number of vertices : ");
    scanf("%d",&n);
    reset();
    printf(" Enter graph data in matrix form : ");
    for(i = 0;i < n; i++){
        for(j = 0;j < n; j++)
            scanf("%d",&G[i][j]);
    }

    do{
        printf("\n\n Options \n\n 1: DFS\n 2: BFS\n 0: Exit\n");
        printf("\n Enter your option : ");
        scanf("%d",&ch);

        switch(ch){
            case 1: 
                reset();
                printf("\n Enter the starting node :");
                scanf("%d",&v);
                DFS(v);
                break;
            case 2: 
                reset();
                printf("\n Enter the starting node :");
                scanf("%d",&v);
                visited[v] = 1;
                BFS(v);
                break;
            case 0: 
                printf("\n Exit...");
                return;
            default: 
                printf("\n Invalid option");
                break;
        }
    }while(ch >= 0);
}