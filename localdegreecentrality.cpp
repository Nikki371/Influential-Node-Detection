#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

vector <int> seed_points_ldc;

extern Graph Node_Properties[MAX_NODES];

void local_degree_centrality() {
  vector <int> ldc[MAX_NODES];
  for(int i = 0; i < MAX_NODES; ++i) {
    vector <bool> vis(MAX_NODES, false);
    vector <int> tmp;
    for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
      if(vis[Node_Properties[i].Neighbour(j)]) continue;
      vis[Node_Properties[i].Neighbour(j)] = true;
      ldc[i].push_back(Node_Properties[i].Neighbour(j));
      tmp.push_back(Node_Properties[i].Neighbour(j));
    }
    for(int k : tmp) {
      for(int j = 0; j < Node_Properties[k].No_of_Neighbours(); ++j) {
        if(vis[Node_Properties[k].Neighbour(j)]) continue;
        vis[Node_Properties[k].Neighbour(j)] = true;
        ldc[i].push_back(Node_Properties[k].Neighbour(j));
      }
    }
    Node_Properties[i].LDC_Value = ldc[i].size();
  }
  vector <pair <double, int> > tmp;
  for(int i = 0; i < MAX_NODES; ++i) {
    tmp.push_back(make_pair(Node_Properties[i].LDC_Value, i));
  }
  sort(tmp.rbegin(), tmp.rend());
  for(int i = 0; i < TOP_K; ++i) {
    seed_points_ldc.push_back(tmp[i].second);
  }
}
