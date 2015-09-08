#include <cstdio>
#include <vector>
#define MAXN 100005
#define FIN "ctc.in"
#define FOUT "ctc.out"

using namespace std;

vector<int>  L1[ MAXN ], //First list
             L2[ MAXN ], //Second list
             Comp[ MAXN ]; //components List

int countComp = 0;
int post[ MAXN ];
int visited[ MAXN ];

int nodes,//number of nodes
    edges;//number of edges

void DFS(int node) {

     visited[ node ] = 1;

     for(int i = 0; i < L1[ node ].size(); i++) {

          if(!visited[ L1[node][i] ]) {

              DFS( L1[node][i] );
          }
     }

     post[ ++post[ 0 ] ] = node;
};

void DFSR(int node) {
    
     visited[ node ] = 0;
 
     Comp[ countComp ].push_back( node );     

     for(int i = 0 ; i < L2[ node ].size(); i++) {

          if(visited[ L2[node][i] ] == 1) {

              DFSR( L2[node][i] );
          }
     }
};

void readData() {

    int x,
        y;

    FILE *in = fopen(FIN, "r");

    fscanf(in, "%d %d", &nodes, &edges);

    while(edges--) {
    
         fscanf(in, "%d %d", &x, &y);
              
         L1[ x ].push_back( y );
         L2[ y ].push_back( x );
    }

    fclose( in ); 
}

void Kosaraju() {

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
}

void writeComponents() {

    FILE *out = fopen(FOUT, "w");
   
    fprintf(out, "%d\n", countComp);
   
    for(int i = 1; i <= countComp; ++i, fprintf(out, "\n")) {

        for(int j = 0; j < Comp[ i ].size(); j++ ) {

            fprintf(out, "%d ", Comp[ i ][ j ]);
        } 
    }
 
    fclose( stdout );
}

int main() {

    readData();
    Kosaraju();
    writeComponents();


 return(0); 
};