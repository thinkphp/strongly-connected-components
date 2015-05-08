#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#define MAXN 100001
#define FIN "ctc.in"
#define FOUT "ctc.out"

using namespace std;

vector<int> Graph[ MAXN ];
vector<int> Graph_REVERSE[ MAXN ];
stack<int> Stack;
bool isVisited[ MAXN ];
vector<int> Results[ MAXN ];

int nodes,//number of nodes
    edges, //number of edges
    comp;//this holds the components strongly connex;

void readData() {

     int x,
         y;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     for(int i = 1; i <= edges; i++) {

         scanf("%d %d", &x, &y);
         Graph[ x ].push_back( y );
         Graph_REVERSE[ y ].push_back( x );
     }

     fclose( stdin );
};

//for debug
void printGraph() {

     for(int i = 1; i <= nodes; i++) {

         printf("%d -> ", i);

         for(vector<int>::iterator it = Graph[ i ].begin(); it != Graph[ i ].end(); ++it) {

            printf("%d ", *it);
         }

         printf("\n");
     }
};

//for debug
void printReverseGraph() {

     for(int i = 1; i <= nodes; i++) {

         printf("%d -> ", i);

         for(vector<int>::iterator it = Graph_REVERSE[ i ].begin(); it != Graph_REVERSE[ i ].end(); ++it) {

            printf("%d ", *it);
         }

         printf("\n");
     }
};

void DFS(int node) {

     isVisited[ node ] = 1;

     for(vector<int>::iterator it = Graph[ node ].begin(); it != Graph[ node ].end(); ++it) {

         if(!isVisited[ *it ]) {

             DFS( *it );
         } 
     }

     Stack.push( node );

};


void DFS_REVERSE(int node) {

     isVisited[ node ] = 1;

     Results[ comp ].push_back( node );

     for(vector<int>::iterator it = Graph_REVERSE[ node ].begin(); it != Graph_REVERSE[ node ].end(); ++it) {

         if(!isVisited[ *it ]) {

             DFS_REVERSE( *it );
         } 
     }
};

//for debug
void printStack() {

 printf("\n");

 while(!Stack.empty()) {
       printf("%d ", Stack.top());
       Stack.pop(); 
 }
};

void Kosaraju() {

     int vertex = 0;

         for(int i = 1; i <= nodes; i++) 

         if( !isVisited[ i ] ) {

             DFS( i );
         }

         memset(isVisited, 0, sizeof(isVisited));

         while( !Stack.empty() ){

                 vertex = Stack.top();

                 Stack.pop();

                 if(!isVisited[ vertex ]) {

                     comp++;

                     DFS_REVERSE( vertex );
                 } 
         }
};

void writeData() {

     freopen(FOUT, "w", stdout);

     printf("%d\n", comp);

     for(int i = 1; i <= comp; i++) {

         //printf("%d -> ", i);

         for(vector<int>::iterator it = Results[ i ].begin(); it != Results[ i ].end(); ++it) {

            printf("%d ", *it);
         }

         printf("\n");
     }

     fclose( stdout );
};

int main() {

 readData();
 Kosaraju();
 writeData();

 return(0);
};
