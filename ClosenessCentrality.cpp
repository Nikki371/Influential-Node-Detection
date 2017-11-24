#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

vector <int> seed_points_cc;

extern Graph Node_Properties[MAX_NODES];

void CC_Values() {
  for(int i = 0; i < MAX_NODES; ++i) {
    int Sum_of_Closeness = 0;
    for(int j = 0; j < MAX_NODES; ++j) {
      if(matrix[i][j] != INF) {
        Sum_of_Closeness += matrix[i][j];
      }
    }
    Node_Properties[i].Closeness_Value = Sum_of_Closeness;
  }
}

void closeness_centrality() {
  CC_Values();
  double ccmin = INF, ccmax = 0;
  for(int i = 0; i < MAX_NODES; ++i) {
    if(ccmin > Node_Properties[i].Closeness_Value) ccmin = Node_Properties[i].Closeness_Value;
    if(ccmax < Node_Properties[i].Closeness_Value) ccmax = Node_Properties[i].Closeness_Value;
  }
  vector <pair <double, int> > tmp;
  for(int i = 0; i < MAX_NODES; ++i) {
    Node_Properties[i].CC_Scaled = Scale(ccmin, ccmax, 0, 100, Node_Properties[i].Closeness_Value);
    tmp.push_back(make_pair(Node_Properties[i].CC_Scaled, i));
  }
  sort(tmp.begin(), tmp.end());
  for(int i = 0; i < TOP_K; ++i) {
    seed_points_cc.push_back(tmp[i].second);
  }
}
