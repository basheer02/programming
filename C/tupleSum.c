#include<stdio.h>
#include<math.h>

void displayTuple(int tup[][3]){
    printf("\n");
    for(int i = 0;i <= tup[0][2];i++)
        printf(" %2d  %2d  %2d\n",tup[i][0],tup[i][1],tup[i][2]);
}

void tupleForm( int matrix[10][10], int row, int col,int trow,int tuple[10][3],int n){

    int x = 1;
    tuple[0][0] = row;
    tuple[0][1] = col;
    tuple[0][2] = trow - 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] != 0){
                tuple[x][0] = i;
                tuple[x][1] = j;
                tuple[x][2] = matrix[i][j];
                x++;
            }
        }
    }
    printf(" tuple form of Matrix %d : \n",n);
    displayTuple(tuple);

}
int readMatrix(int matrix[10][10],int row, int col,int n){

    int num = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf(" Enter element of matrix of %d(%d,%d) : ",n,i,j);
            scanf("%d",&matrix[i][j]);
            if( matrix[i][j] != 0)
                num++;
        }    
    }
    return num;
}
int compare(int a,int b,int p,int q){
    if(a == b){
        if(p == q)
            return 0;
        else if(p < q)
            return 1;
        else
            return 2;
    }
    else if(a < b)
        return 1;
    else    
        return 2;
}

void tupleSum(int tuple1[][3], int tuple2[][3], int tuplesum[][3]){

    int p1 = 1,p2 = 1,p3 = 1;
    tuplesum[0][0] = tuple1[0][0];
    tuplesum[0][1] = tuple1[0][1];
    
    while(p1 <= tuple1[0][2] && p2 <= tuple2[0][2]){
        switch(compare(tuple1[p1][0],tuple2[p2][0],tuple1[p1][1],tuple2[p2][1])){

            case 0:
                if(tuple1[p1][2] + tuple2[p2][2] != 0){
                    tuplesum[p3][2] = tuple1[p1][2] + tuple2[p2][2];
                    tuplesum[p3][1] = tuple1[p1][1];
                    tuplesum[p3][0] = tuple1[p1][0];
                    p3++;
                }
                p1++;
                p2++;
                break;
            case 1:
                tuplesum[p3][2] = tuple1[p1][2];
                tuplesum[p3][1] = tuple1[p1][1];
                tuplesum[p3][0] = tuple1[p1][0];
                p3++;
                p1++;
                break;
            case 2:
                tuplesum[p3][2] = tuple2[p2][2];
                tuplesum[p3][1] = tuple2[p2][1];
                tuplesum[p3][0] = tuple2[p2][0];
                p3++;
                p2++;
                break;
        }
    }
    while(p1 <= tuple1[0][2]){
        tuplesum[p3][2] = tuple1[p1][2];
        tuplesum[p3][1] = tuple1[p1][1];
        tuplesum[p3][0] = tuple1[p1][0];
        p3++;
        p1++;
    }
    while(p2 <= tuple2[0][2]){
        tuplesum[p3][2] = tuple2[p2][2];
        tuplesum[p3][1] = tuple2[p2][1];
        tuplesum[p3][0] = tuple2[p2][0];
        p3++;
        p2++;
    }

    tuplesum[0][2] = p3 - 1;

    printf(" Sum of tuples : \n");
    displayTuple(tuplesum);
}

void tupleTransporse(int p[][3],int n){

    int tup[10][3];
    tup[0][0] = p[0][1];
    tup[0][1] = p[0][0];
    tup[0][2] = p[0][2];

    int pos = 1;
    for(int i = 0;i <= p[0][1]; i++){
        for(int j = 1;j <= p[0][2]; j++){
            if(p[j][1] == i){
                tup[pos][0]=p[j][1];
                tup[pos][1]=p[j][0];
                tup[pos][2]=p[j][2];
                pos++;
            }
        }
    }

    printf(" Transporse of tuple %d : \n",n);
    displayTuple(tup);
}

int main(){

    int col1,row1,col2,row2;
    int matrix1[10][10],matrix2[10][10];
    int tuple1[10][3], tuple2[10][3];
    int ch;
    do{

        printf("\n\n *****************\n\n");
        printf(" Options  \n\n 1. Read matrixes \n 2. Tuple form \n 3. Transporse \n 4. Sum \n 0. Exit \n");
        printf("\n Enter your option : ");
        scanf("%d",&ch);

        switch(ch){
            case 0:
                return 0;
            case 1:
                printf(" *****************\n\n");
                printf(" Enter no.of rows in matrix 1: ");
                scanf("%d",&row1);
                printf(" Enter no.of colums in matrix 1: ");
                scanf("%d",&col1);
                printf("\n *****************\n\n");

                int trow1 = readMatrix(matrix1,row1,col1,1);

                printf("\n *****************\n\n");
                printf(" Enter no.of rows in matrix 2: ");
                scanf("%d",&row2);
                printf(" Enter no.of colums in matrix 2: ");
                scanf("%d",&col2);
                printf("\n *****************\n\n");

                int trow2 = readMatrix(matrix2,row2,col2,2);
                break;
            case 2:
                printf("\n\n *****************\n\n");
                tupleForm(matrix1,row1,col1,trow1,tuple1,1);
                printf("\n\n *****************\n\n");
                tupleForm(matrix2,row2,col2,trow2,tuple2,2);
                break;
            case 3:
                printf("\n\n *****************\n\n");
                tupleTransporse(tuple1,1);
                printf("\n\n *****************\n\n");
                tupleTransporse(tuple2,2);
                break;
            case 4:
                printf("\n\n *****************\n\n");
                if ( row1 == row2 && col1 == col2){
                    int tuplesum[10][3];
                    tupleSum(tuple1,tuple2,tuplesum);
                }
                else{
                    printf(" Addition not occur ");
                    printf("\n\n *****************\n\n");
                }
                break;
        }

    }while(ch >= 0 && ch < 5);

    return 0;
}