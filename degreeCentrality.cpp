#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

vector <int> seed_points_dc;

extern Graph Node_Properties[MAX_NODES];

void degree_centrality() {
  double dcmin = INF, dcmax = 0;
  for(int i = 0; i < MAX_NODES; ++i) {
    if(dcmin > Node_Properties[i].No_of_Neighbours()) dcmin = Node_Properties[i].No_of_Neighbours();
    if(dcmax < Node_Properties[i].No_of_Neighbours()) dcmax = Node_Properties[i].No_of_Neighbours();
    // cout << i << " " << Node_Properties[i].No_of_Neighbours() << "\n";
  }
  vector <pair <double, int> > tmp;
  for(int i = 0; i < MAX_NODES; ++i) {
    Node_Properties[i].DC_Scaled = Scale(dcmin, dcmax, 0, 100, Node_Properties[i].No_of_Neighbours());
    tmp.push_back(make_pair(Node_Properties[i].DC_Scaled, i));
  }
  sort(tmp.rbegin(), tmp.rend());
  /*for(auto i : tmp) {
    cout << i.second << " " << i.first << "\n";
  } */
  for(int i = 0; i < TOP_K; ++i) {
    seed_points_dc.push_back(tmp[i].second);
  }
}
