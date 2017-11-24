#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

vector <int> seed_points_bc;

extern Graph Node_Properties[MAX_NODES];

void Floyd_Warshall() {
  for(int k = 0; k < MAX_NODES; ++k) {
    for(int i = 0; i < MAX_NODES; ++i) {
      for(int j = 0; j < MAX_NODES; ++j) {
        int tmp = matrix[i][k] + matrix[k][j];
        if(tmp <= matrix[i][j]) {
          matrix[i][j] = tmp;
          Node_Properties[k].Betweenness_Value++;
        }
      }
    }
  }
}
void betweenness_centrality() {
  Floyd_Warshall();
  double bcmin = INF, bcmax = 0;
  for(int i = 0; i < MAX_NODES; ++i) {
    if(bcmin > Node_Properties[i].Betweenness_Value) bcmin = Node_Properties[i].Betweenness_Value;
    if(bcmax < Node_Properties[i].Betweenness_Value) bcmax = Node_Properties[i].Betweenness_Value;
  }
  vector <pair <double, int> > tmp;
  for(int i = 0; i < MAX_NODES; ++i) {
    Node_Properties[i].BC_Scaled = Scale(bcmin, bcmax, 0, 100, Node_Properties[i].Betweenness_Value);
    tmp.push_back(make_pair(Node_Properties[i].BC_Scaled, i));
  }
  sort(tmp.rbegin(), tmp.rend());
  for(int i = 0; i < TOP_K; ++i) {
    seed_points_bc.push_back(tmp[i].second);
  }
}
