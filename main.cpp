#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

extern Graph Node_Properties[MAX_NODES];

int main() {
  //freopen("datasets/fb/facebook_combined-small.in","r",stdin);
  // freopen("Results.out","w",stdout);
  scangraph();
  degree_centrality();
  local_degree_centrality();
  betweenness_centrality();
  closeness_centrality();
  pagerank_centrality();
  kshell_centrality();
  cascade_DC();
  cascade_LDC();
  cascade_BC();
  cascade_CC();
  cascade_PR();
  cascade_KS();
  return 0;
}
