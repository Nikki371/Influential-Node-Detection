#include "bits/stdc++.h"
#include "socialnetwork.h"
using namespace std;

vector <int> seed_points_pr;

extern Graph Node_Properties[MAX_NODES];

double stochastic_matrix[MAX_NODES][MAX_NODES];

const double damp_factor = 0.85;
const double epsilon = 0.0005;

vector <double> mat_multiply(vector <double> x) {
  vector <double> ans(MAX_NODES, 0);
  for(int i = 0; i < MAX_NODES; ++i) {
    for(int j = 0; j < MAX_NODES; ++j) {
      ans[i] += stochastic_matrix[i][j] * x[j];
    }
  }
  return ans;
}

vector <double> power_iteration() {
  vector <double> prev(MAX_NODES, 1);
  vector <double> cm(MAX_NODES, 0.15);
  vector <double> curr(MAX_NODES), tmp;
  double nlp = 1, clp;
  while(1) {
    tmp = mat_multiply(prev);
    for(int i = 0; i < MAX_NODES; ++i) {
      curr[i] = cm[i] + tmp[i];
    }
    clp = -1.0;
    for(int i = 0; i < MAX_NODES; ++i) {
      if(curr[i] > clp) clp = curr[i];
    }
    for(int i = 0; i < MAX_NODES; ++i) {
      curr[i] /= clp;
    }
    if(abs(nlp - clp) < epsilon) break;
    prev = curr;
    nlp = clp;
  }
  return curr;
}

void pagerank_centrality() {
  memset(stochastic_matrix, 0, sizeof(stochastic_matrix));
  for(int i = 0; i < MAX_NODES; ++i){
    for(int j = 0; j < Node_Properties[i].No_of_Neighbours(); ++j) {
      stochastic_matrix[i][Node_Properties[i].Neighbour(j)] = 1;
      stochastic_matrix[Node_Properties[i].Neighbour(j)][i] = 1;
    }
  }
  for(int i = 0; i < MAX_NODES; ++i) {
    for(int j = 0; j < MAX_NODES; ++j) {
      if(stochastic_matrix[i][j] > 0.5) stochastic_matrix[i][j] = 1.0 / Node_Properties[i].No_of_Neighbours();
    }
  }
  // Transpose
  for(int i = 0; i < MAX_NODES; ++i) {
    for(int j = i + 1; j < MAX_NODES; ++j) {
      swap(stochastic_matrix[i][j], stochastic_matrix[j][i]);
    }
  }
  // Multiply with damping factor
  for(int i = 0; i < MAX_NODES; ++i) {
    for(int j = 0; j < MAX_NODES; ++j) {
      stochastic_matrix[i][j] *= damp_factor;
    }
  }
  vector <double> pagerank = power_iteration();
  priority_queue <pair<double, int> > pq;
  for(int i = 0; i < MAX_NODES; ++i) {
    pq.push(make_pair(pagerank[i], i));
  }
  int k = TOP_K;
  while(k--) {
    seed_points_pr.push_back(pq.top().second);
    pq.pop();
  }
}
