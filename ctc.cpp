#include <stdio.h>
#define MAXN 100005
#define FIN "ctc.in"
#define FOUT "ctc.out"

struct Node {
       int y;
       Node *next;
} *L1[ MAXN ], //first list
  *L2[ MAXN ], //second list
  *Comp[ MAXN ];//this array of pointers holds the strongly connected connex.

int countComp = 0;
int post[ MAXN ];
int visited[ MAXN ];

int nodes,//number of nodes
    edges;//number of edges

void DFS(int node) {

     visited[ node ] = 1;

     for(Node *q = L1[ node ]; q; q = q->next) {

          if(!visited[ q->y ]) {

              DFS( q->y );
          }
     }

     post[ ++post[ 0 ] ] = node;
};

void DFSR(int node) {
    
     visited[ node ] = 0;
 
     Node *q = new Node;
     q->y = node;
     q->next = Comp[ countComp ];
     Comp[ countComp ] = q; 
     

     for(Node *q = L2[ node ]; q; q = q->next) {

          if(visited[ q->y ] == 1) {

              DFSR( q->y );
          }
     }     
};

void printL1() {

     Node *q;

     for(int i = 1; i <= nodes; i++) {

         printf("%d ->", i);

         for(q = L1[ i ]; q; q = q->next) {

            printf("%d ", q->y);
         } 

         printf("\n");
     }

}


void printL2() {

     Node *q;

     for(int i = 1; i <= nodes; i++) {

         printf("%d ->", i);

         for(q = L2[ i ]; q; q = q->next) {

            printf("%d ", q->y);
         } 

         printf("\n");
     }

}

int main() {

    Node *q1, *q2;

    int x,
        y;

    FILE *in = fopen(FIN, "r");

    fscanf(in, "%d %d", &nodes, &edges);

    while(edges--) {
    
         fscanf(in, "%d %d", &x, &y);
         
         q1 = new Node;
         q1->y = y;
         q1->next = L1[ x ];
         L1[ x ] = q1;  

         q2 = new Node;
         q2->y = x;
         q2->next = L2[ y ];
         L2[ y ] = q2;  

    }

    fclose( in ); 

    for(int node = 1; node <= nodes; node++) {

        if( !visited[ node ] ) {

             DFS( node ); 
        }
    }
 
    for(int i = nodes; i >= 1; --i) {

        if(visited[ post[ i ] ] == 1) {

           ++countComp;
            
           DFSR( post[ i ] ); 
        }   
    }

    FILE *out = fopen(FOUT, "w");
   
    fprintf(out, "%d\n", countComp);
   
    for(int i = 1; i <= countComp; ++i, fprintf(out, "\n")) {

        for(Node *R = Comp[ i ]; R; R = R->next) {

            fprintf(out, "%d ", R->y);
        } 
    }
 
    fclose( stdout );
 return(0); 
};