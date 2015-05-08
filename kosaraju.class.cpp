#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#define MAXN 100001
#define FIN "ctc.in"
#define FOUT "ctc.out"

using namespace std;

class Kosaraju {

public:
Kosaraju(int N, int M):nodes( N ), 
                       edges( M ), 
                       comp( 0 ), 
                       Graph( 2 * N + 1 ), 
                       Graph_REVERSE( 2 * N + 1 ), 
                       isVisited( 2 * N + 1 ), 
                       Results( 2 * N + 1 ){}
 
void addEdge(int x, int y) {

         Graph[ x ].push_back( y );
         Graph_REVERSE[ y ].push_back( x );
}

//Depth First Search
void DFS(int node) {

     isVisited[ node ] = 1;

     for(vector<int>::iterator it = Graph[ node ].begin(); it != Graph[ node ].end(); ++it) {

         if(!isVisited[ *it ]) {

             DFS( *it );
         } 
     }

     Stack.push( node );

};


//Depth First Search Reverse
void DFS_REVERSE(int node) {

     isVisited[ node ] = 1;

     Results[ comp ].push_back( node );

     for(vector<int>::iterator it = Graph_REVERSE[ node ].begin(); it != Graph_REVERSE[ node ].end(); ++it) {

         if(!isVisited[ *it ]) {

             DFS_REVERSE( *it );
         } 
     }
};

//in action Kosaraju
void solve() {

     int vertex = 0;

         for(int i = 1; i <= nodes; i++)

         if( !isVisited[ i ] ) {

             DFS( i );
         }

         //memset 0 to sizeof of isVisited
         for(int v = 1; v <= nodes + 1; v++) isVisited[ v ] = 0;

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

         for(vector<int>::iterator it = Results[ i ].begin(); it != Results[ i ].end(); ++it) {

            printf("%d ", *it);
         }

         printf("\n");
     }

     fclose( stdout );
};

private:
int nodes, edges, comp;
vector<vector<int> >Graph;
vector<vector<int> >Graph_REVERSE;
vector<vector<int> >Results;
vector<int> isVisited;
stack<int> Stack;

};//end Kosaraju class

int main() {

     int n,//nodes
         m,//edges
         x,//node
         y;//node

     freopen(FIN, "r", stdin);

     scanf("%d %d", &n, &m);
     Kosaraju ob(n,m);

     for(int i = 1; i <= m; i++) {

         scanf("%d %d", &x, &y);
         ob.addEdge(x,y);  
     }

     fclose( stdin );

     ob.solve();
     ob.writeData();

 return(0);
};
