/*
 *  @ Description -> Algorithm fo finding the strongly connected components of a graph.
 *  @ O(N^3) Complexity Time.
 *  @ License MIT
 */
#include <stdio.h>
#include <stdbool.h>
#define FIN "ctc.in"
#define FOUT "ctc.out"
#define MAX 10005

int mat[MAX][MAX];//matrix of adjacency

int  SUCC[MAX], //array of succ
     PREC[MAX]; //array of prec

int num_nodes, num_edges;
int num_components;

void DFS1(int node) {

     int i;

     SUCC[node] = num_components;

     for(i = 1; i <= num_nodes; i++) {

             if(mat[node][i] && !SUCC[ i ]) {

                   SUCC[i] = 1;

                   DFS1(i);  
             }
     }
};

void DFS2(int node) {

     int i;

     PREC[node] = num_components;

     for(i = 1; i <= num_nodes; i++) {

             if(mat[i][node] && !PREC[ i ]) {

                   PREC[i] = 1;

                   DFS2(i);  
             }
     }
};


void RoyWarshall() {

     int i,j,k;

     for(i=1;i<=num_nodes;i++) {

           for(j=1;j<=num_nodes;j++) {

               for(k=1;k<=num_nodes;k++) {  
        
                   if(mat[i][k] && mat[k][j]) mat[i][j] = 1;
               }
           }
     }
};

void read() {

     int i,j;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &num_nodes, &num_edges);

     while(num_edges--) 
     {

           scanf("%d %d", &i, &j);

           mat[ i ][ j ] = 1;
     };

     RoyWarshall();

     fclose( stdin ); 
};

int main() {

    read();

    int i,j;

    for(i=1;i<=num_nodes;i++) 
    {

        SUCC[i] = PREC[i] = 0;  
    } 

    num_components = 1; 

    for(i = 1; i <= num_nodes; i++)  
    {

     if( !SUCC[ i ] ) 
     { 
        DFS1( i );

        DFS2( i );

        for( j = 1; j <= num_nodes; j++) 
        {
            if( SUCC[ j ] != PREC[ j ] ) SUCC[ j ] = PREC[ j ] = 0;         
        }

        num_components++;
     }

    }

    freopen(FOUT, "w", stdout);

    printf("%d\n",num_components-1);

    int num_comp = 1;
 
    for( j = 1; j <= num_components; j++, num_comp)
    {

         for(i = 1; i <= num_nodes; i++)
         {
 
            if(SUCC[i] == j)
            {
              printf("%d ", i);
            }
         } 
         printf("\n");
    }

    fclose( stdout );

   return(0);
};