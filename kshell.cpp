#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

vector <int> seed_points_ks;

extern Graph Node_Properties[MAX_NODES];

int Adj_matrix[MAX_NODES][MAX_NODES];

vector <int> shell[MAX_NODES];
vector <bool> incl(MAX_NODES, false);

int ithshell(int x) {
  int i;
  for(i = 0; i < MAX_NODES; ++i) {
    bool ok = false;
    for(int j = 0; j < MAX_NODES; ++j) {
      int cnt = 0;
      for(int k = 0; k < MAX_NODES; ++k) cnt += Adj_matrix[j][k];
      if(cnt <= x) {
        if(incl[j]) continue;
        incl[j] = true;
        shell[x].push_back(j);
        for(int k = 0; k < MAX_NODES; ++k) {
          if(Adj_matrix[j][k]) {
            ok = true;
            Adj_matrix[j][k] = Adj_matrix[k][j] = 0;
          }
        }
      }
    }
    if(!ok) break;
  }
}

void kshell_centrality() {
  for(int i = 0; i < MAX_NODES; ++i){
    for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
      Adj_matrix[i][Node_Properties[i].Neighbour(j)] = 1;
      Adj_matrix[Node_Properties[i].Neighbour(j)][i] = 1;
    }
  }
  int last_shell = 0;
  for(last_shell; last_shell < MAX_NODES; ++last_shell) {
    if(ithshell(last_shell) == -1) break;
  }
  last_shell--;
  int k = TOP_K;
  for(int i = last_shell; i >= 0 && k; --i) {
    for(int j : shell[i]) {
      if(k-- <= 0) break;
      seed_points_ks.push_back(j);
    }
  }
}
