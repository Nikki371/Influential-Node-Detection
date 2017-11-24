#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

int matrix[MAX_NODES][MAX_NODES];
int No_of_Components;

Graph Node_Properties[MAX_NODES];

bool visited[MAX_NODES];

set <int> nodes_in_graph;

void dfs(int src) {
  if(visited[src]) return;
  visited[src] = true;
  Node_Properties[src].Component_Number = No_of_Components;
  for(int i = 0; i < Node_Properties[src].No_of_Neighbours(); ++i) {
    dfs(Node_Properties[src].Neighbour(i));
  }
}

void scangraph() {
  // freopen("datasets/fb/facebook_combined-small.in","r",stdin);
  freopen("datasets/Random/dataset3.txt","r",stdin);
  // freopen("Results.out","w",stdout);
  int N1, N2;
  for(int i = 0; i < MAX_NODES; ++i) {
    for(int j = 0; j < MAX_NODES; ++j) {
      if(i == j) matrix[i][j] = 0;
      else matrix[i][j] = INF;
    }
  }
  No_of_Components = 0;
  while(scanf("%d", &N1) != EOF) {
    scanf("%d", &N2);
    Node_Properties[N1].Add_Neighbours(N2);
    Node_Properties[N2].Add_Neighbours(N1);
    matrix[N1][N2] = 1;
    matrix[N2][N1] = 1;
    nodes_in_graph.insert(N1);
    nodes_in_graph.insert(N2);
  }
  memset(visited, false, sizeof(visited));
  for(int i = 0; i < MAX_NODES; ++i) {
    auto it = nodes_in_graph.lower_bound(i);
    if(it != nodes_in_graph.end() && *it == i && Node_Properties[i].Component_Number == -1) {
      dfs(i);
      No_of_Components++;
    }
  }
}
