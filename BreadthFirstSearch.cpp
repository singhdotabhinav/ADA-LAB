#include <iostream>
#include <queue>
 using namespace std;
 const int MAX = 100;
 void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);
 int main(void)
 {
 int graph[MAX][MAX];
 int visited[MAX];
 int numVert, startVert, i,j;
 cout << "Enter the number of vertices : ";
 cin >> numVert;
cout << "Enter the adjacency matrix :\n";
 for (i=0; i<numVert; i++)
 visited[i] = 0;
 for (i=0; i<numVert; i++)
 for (j=0; j<numVert; j++)
 cin >> graph[i][j];
 cout << "Enter the starting vertex : ";
 cin >> startVert;
 fnBreadthFirstSearchReach(startVert-1,graph,visited,numVert);
 cout << "Vertices which can be reached from vertex " << startVert << " are :-"
<< endl;
 for (i=0; i<numVert; i++)
 if (visited[i])
 cout << i+1 << " ";
 cout << endl;
 return 0;
 }
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n)
 {
queue <int> VQueue;
 int frontVertex, i;
 v[vertex] = 1;
 VQueue.push(vertex);
 while (!VQueue.empty())
 {
 frontVertex = VQueue.front();
 VQueue.pop();
 for (i=0; i<n; i++)
 {
 if (g[frontVertex][i] && !v[i])
 {
 v[i] = 1;
 VQueue.push(i);
 }
 }
 }
 }
