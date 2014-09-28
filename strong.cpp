#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#define FIN "ctc.in"
#define FOUT "ctc.out"
#define MAX 100005

using namespace std;

int num_nodes, 
    num_arcs;

int num_comp = 1;

vector<int> List1[ MAX ];
vector<int> List2[ MAX ];

int SUCC[MAX];
int PREC[MAX];

//function prototypes
void read();
void DFS1(int node);
void DFS2(int node);
void solve();
void displayList();
void write();

int main() {

    read();
    solve();
    write();
   
   return(0);
};

void read() {

     int x,y;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &num_nodes, &num_arcs);
 
     for(; num_arcs;num_arcs--) {
 
           scanf("%d %d", &x, &y);
           List1[ x ].push_back( y );
           List2[ y ].push_back( x );
     }
    
     fclose( stdin );  
};

void DFS1(int node) {

     SUCC[ node ] = num_comp; 

     for(int i = 0; i < List1[ node ].size(); i++) {

             if( !SUCC[ List1[ node ][ i ] ]) {

                    DFS1( List1[ node ][ i ]);
             }
     }
};

void DFS2(int node) {

     PREC[ node ] = num_comp; 

     for(int j = 0; j < List2[ node ].size(); j++) {

             if( !PREC[ List2[ node ][ j ] ]) {

                    DFS2( List2[ node ][ j ] );
             }
     }
};

void write() {

   freopen(FOUT, "w", stdout); 

   printf("%d\n", num_comp - 1); 

   for(int k = 1; k <= num_comp - 1; k++) {

         for(int p = 1; p <= num_nodes; p++) { 

           if(SUCC[p] == k) {

              printf("%d ", p);
           }    

         }

           printf("\n");
   } 

   fclose( stdin );
};

void solve() {

    memset(SUCC, 0, sizeof(SUCC));

    memset(PREC, 0, sizeof(PREC));

    for(int i = 1; i <= num_nodes; i++) {

        if(!SUCC[i]) {

            DFS1(i); 

            DFS2(i);

            for(int j = 1; j <= num_nodes; j++) {            
  
                    if(SUCC[j] != PREC[j]) SUCC[j] = PREC[j] = 0;
            }

            num_comp++;
        }
    }
}

void displayList() {

     for(int i = 1; i<=num_nodes; i++) {

         printf("%d -> ", i);  

         for(int j = 0; j < List2[i].size(); j++) {

                  printf("%d ", List2[i][j]);
         } 
                  printf("\n");
     }

}