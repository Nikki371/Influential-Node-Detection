#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

extern Graph Node_Properties[MAX_NODES];

vector <int> ngraph[MAX_NODES];
bool vis[MAX_NODES];

void dfst(int src, int par = -1) {
    if(vis[src]) return;
    vis[src] = true;
    for(auto i : ngraph[src]) {
      if(i == par) continue;
      dfst(i, src);
    }
}

int new_components(vector<int> ifnodes) {
  for(int i = 0; i < MAX_NODES; ++i) ngraph[i].clear();
  set <int> nig;
  memset(vis, false, sizeof(vis));
  for(int i = 0; i < MAX_NODES; ++i) {
    auto it = find(ifnodes.begin(), ifnodes.end(), i);
    if(it != ifnodes.end()) continue;
    for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
      it = find(ifnodes.begin(), ifnodes.end(), Node_Properties[i].Neighbour(j));
      if(it != ifnodes.end()) continue;
      nig.insert(Node_Properties[i].Neighbour(j));
      ngraph[i].push_back(Node_Properties[i].Neighbour(j));
    }
  }
  int ncts = 0;
  for(int i = 0; i < MAX_NODES; ++i) {
    auto it = nig.lower_bound(i);
    if(it != nig.end() && *it == i && !vis[i]) {
      ncts++;
      dfst(i);
    }
  }
  return ncts;
}

void cascade_DC() {
  freopen("Cascading_DC.out","w",stdout);
  vector <int> affected[300];
  extern vector <int> seed_points_dc;
  vector <bool> visited(MAX_NODES, false);
  affected[0] = seed_points_dc;
  for(int i : seed_points_dc) visited[i] = true;
  int lvl = 0;
  while(!affected[lvl].empty()) {
    for(int i : affected[lvl]) {
      for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
        if(visited[Node_Properties[i].Neighbour(j)]) continue;
        visited[Node_Properties[i].Neighbour(j)] = true;
        affected[lvl + 1].push_back(Node_Properties[i].Neighbour(j));
      }
    }
    lvl++;
  }
  int sum = 0;
  for(int i = 0; i < lvl; ++i) {
    sum += affected[i].size();
    cout << "Nodes affected in level " << i << " (" << affected[i].size() << ") : ";
    for(int j : affected[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "Total number of affected nodes : " << sum << "\n\n";
  cout << "=============================================================================\n\n";
  cout << "Number of components in the graph initially : " << No_of_Components << "\n";
  cout << "Number of components in the graph after removal of the top 10 influential nodes : ";
  cout << new_components(seed_points_dc) << "\n";
}

void cascade_LDC() {
  freopen("Cascading_LDC.out","w",stdout);
  vector <int> affected[300];
  extern vector <int> seed_points_ldc;
  vector <bool> visited(MAX_NODES, false);
  affected[0] = seed_points_ldc;
  for(int i : seed_points_ldc) visited[i] = true;
  int lvl = 0;
  while(!affected[lvl].empty()) {
    for(int i : affected[lvl]) {
      for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
        if(visited[Node_Properties[i].Neighbour(j)]) continue;
        visited[Node_Properties[i].Neighbour(j)] = true;
        affected[lvl + 1].push_back(Node_Properties[i].Neighbour(j));
      }
    }
    lvl++;
  }
  int sum = 0;
  for(int i = 0; i < lvl; ++i) {
    sum += affected[i].size();
    cout << "Nodes affected in level " << i << " (" << affected[i].size() << ") : ";
    for(int j : affected[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "Total number of affected nodes : " << sum << "\n\n";
  cout << "=============================================================================\n\n";
  cout << "Number of components in the graph initially : " << No_of_Components << "\n";
  cout << "Number of components in the graph after removal of the top 10 influential nodes : ";
  cout << new_components(seed_points_ldc) << "\n";
}

void cascade_BC() {
  freopen("Cascading_BC.out","w",stdout);
  vector <int> affected[300];
  extern vector <int> seed_points_bc;
  vector <bool> visited(MAX_NODES, false);
  affected[0] = seed_points_bc;
  for(int i : seed_points_bc) visited[i] = true;
  int lvl = 0;
  while(!affected[lvl].empty()) {
    for(int i : affected[lvl]) {
      for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
        if(visited[Node_Properties[i].Neighbour(j)]) continue;
        visited[Node_Properties[i].Neighbour(j)] = true;
        affected[lvl + 1].push_back(Node_Properties[i].Neighbour(j));
      }
    }
    lvl++;
  }
  int sum = 0;
  for(int i = 0; i < lvl; ++i) {
    sum += affected[i].size();
    cout << "Nodes affected in level " << i << " (" << affected[i].size() << ") : ";
    for(int j : affected[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "Total number of affected nodes : " << sum << "\n\n";
  cout << "=============================================================================\n\n";
  cout << "Number of components in the graph initially : " << No_of_Components << "\n";
  cout << "Number of components in the graph after removal of the top 10 influential nodes : ";
  cout << new_components(seed_points_bc) << "\n";
}

void cascade_CC() {
  freopen("Cascading_CC.out","w",stdout);
  vector <int> affected[300];
  extern vector <int> seed_points_cc;
  vector <bool> visited(MAX_NODES, false);
  affected[0] = seed_points_cc;
  for(int i : seed_points_cc) visited[i] = true;
  int lvl = 0;
  while(!affected[lvl].empty()) {
    for(int i : affected[lvl]) {
      for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
        if(visited[Node_Properties[i].Neighbour(j)]) continue;
        visited[Node_Properties[i].Neighbour(j)] = true;
        affected[lvl + 1].push_back(Node_Properties[i].Neighbour(j));
      }
    }
    lvl++;
  }
  int sum = 0;
  for(int i = 0; i < lvl; ++i) {
    sum += affected[i].size();
    cout << "Nodes affected in level " << i << " (" << affected[i].size() << ") : ";
    for(int j : affected[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "Total number of affected nodes : " << sum << "\n\n";
  cout << "=============================================================================\n\n";
  cout << "Number of components in the graph initially : " << No_of_Components << "\n";
  cout << "Number of components in the graph after removal of the top 10 influential nodes : ";
  cout << new_components(seed_points_cc) << "\n";
}

void cascade_PR() {
  freopen("Cascading_PR.out","w",stdout);
  vector <int> affected[300];
  extern vector <int> seed_points_pr;
  vector <bool> visited(MAX_NODES, false);
  affected[0] = seed_points_pr;
  for(int i : seed_points_pr) visited[i] = true;
  int lvl = 0;
  while(!affected[lvl].empty()) {
    for(int i : affected[lvl]) {
      for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
        if(visited[Node_Properties[i].Neighbour(j)]) continue;
        visited[Node_Properties[i].Neighbour(j)] = true;
        affected[lvl + 1].push_back(Node_Properties[i].Neighbour(j));
      }
    }
    lvl++;
  }
  int sum = 0;
  for(int i = 0; i < lvl; ++i) {
    sum += affected[i].size();
    cout << "Nodes affected in level " << i << " (" << affected[i].size() << ") : ";
    for(int j : affected[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "Total number of affected nodes : " << sum << "\n\n";
  cout << "=============================================================================\n\n";
  cout << "Number of components in the graph initially : " << No_of_Components << "\n";
  cout << "Number of components in the graph after removal of the top 10 influential nodes : ";
  cout << new_components(seed_points_pr) << "\n";
}

void cascade_KS() {
  freopen("Cascading_KS.out","w",stdout);
  vector <int> affected[300];
  extern vector <int> seed_points_ks;
  vector <bool> visited(MAX_NODES, false);
  affected[0] = seed_points_ks;
  for(int i : seed_points_ks) visited[i] = true;
  int lvl = 0;
  while(!affected[lvl].empty()) {
    for(int i : affected[lvl]) {
      for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
        if(visited[Node_Properties[i].Neighbour(j)]) continue;
        visited[Node_Properties[i].Neighbour(j)] = true;
        affected[lvl + 1].push_back(Node_Properties[i].Neighbour(j));
      }
    }
    lvl++;
  }
  int sum = 0;
  for(int i = 0; i < lvl; ++i) {
    sum += affected[i].size();
    cout << "Nodes affected in level " << i << " (" << affected[i].size() << ") : ";
    for(int j : affected[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "Total number of affected nodes : " << sum << "\n\n";
  cout << "=============================================================================\n\n";
  cout << "Number of components in the graph initially : " << No_of_Components << "\n";
  cout << "Number of components in the graph after removal of the top 10 influential nodes : ";
  cout << new_components(seed_points_ks) << "\n";
}
