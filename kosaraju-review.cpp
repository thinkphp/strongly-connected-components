/*
Nu se foloseste la WebSITES !Nu React, Nu Angular, Nu Vue

In productie probleme serioase de Algoritmica
Algoritmul lui Kosaraju:

Step 1: DFS lista de descendenti Graph normal, adaugi intr-o stiva nodurile asa cum apar in sortarea topologica
Step 2: reset isVisited , false
Step 3: Scot din stiva, fac atribuirea vertex = nodul scos, pop la nod si DFS_REVERSE(vertex)

*/
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stack>
#define MAXN 100001
#define FIN "graph.in"
#define FOUT "graph.out"

using namespace std;

int nodes,
    edges,
    comp;

vector<int> Graph[MAXN];
vector<int> Graph_REVERSE[MAXN];
bool isVisited[MAXN];
stack<int> Stack;
vector<int> Results[ MAXN ];

void readData() {
     int x,
         y;

    freopen(FIN, "r", stdin);

    scanf("%d %d", &nodes, &edges);
    //cin>>nodes>>edges;

    for(int i = 1; i <= edges; ++i) {

        scanf("%d %d", &x, &y);
        Graph[ x ].push_back( y );
        Graph_REVERSE[ y ].push_back( x );
    }
}

void DFS(int node) {

     isVisited[ node ] = 1;

     for(vector<int>::iterator it = Graph[ node ].begin( ); it != Graph[node].end(); ++it) {

           if(!isVisited[ *it ]) {

               DFS( *it );
           }
     }

     Stack.push( node );
}


void DFS_REVERSE(int node) {

     isVisited[ node ] = 1;

     Results[ comp ].push_back( node );

     for(vector<int>::iterator it = Graph_REVERSE[ node ].begin( ); it != Graph_REVERSE[node].end(); ++it) {

           if(!isVisited[ *it ]) {

               DFS_REVERSE( *it );
           }
     }

}


void Kosaraju() {

     int vertex = 0;

     for(int i = 1; i <= nodes; ++i) {

          if(!isVisited[ i ]) {

              DFS( i );
          }
     }

     //reset
     memset(isVisited, 0, sizeof(isVisited));

     while(!Stack.empty()) {

             vertex = Stack.top();

             Stack.pop();

             if(!isVisited[ vertex ]) {

                comp++;

                DFS_REVERSE( vertex );
             }
     }
}

void writeData() {

     printf("%d\n", comp);

     for(int i = 1; i <= comp; ++i) {

        for(vector<int>::iterator it = Results[i].begin(); it != Results[i].end(); ++it) {

            printf("%d ", *it);
        }
        printf("\n");
     }
}

int main(int argc, char const *argv[]) {

  readData();
  Kosaraju();
  writeData();

  return 0;
}
