#include "bits/stdc++.h"
using namespace std;

#define MAX_NODES 300
#define TOP_K 10
#define INF 1000000000

extern int matrix[MAX_NODES][MAX_NODES];
extern int No_of_Components;

extern vector <int> seed_points_dc;
extern vector <int> seed_points_ldc;
extern vector <int> seed_points_bc;
extern vector <int> seed_points_cc;
extern vector <int> seed_points_pr;
extern vector <int> seed_points_ks;

extern set <int> nodes_in_graph;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
  vector<int> Adj_List;
public:
  int Component_Number = -1; // Unassigned State
  int Betweenness_Value = 0;
  int LDC_Value = 0;
  double Closeness_Value;
  double DC_Scaled;
  double BC_Scaled;
  double CC_Scaled;
  int No_of_Neighbours() {
    return (int)Adj_List.size();
  }
  void Add_Neighbours(int i) {
    Adj_List.push_back(i);
  }
  int Neighbour(int i) {
    return Adj_List[i];
  }
};

#endif

extern Graph Node_Properties[MAX_NODES];

inline double Scale(double A, double B, double C, double D, double x) {
  try {
    if(B - A < 1e-10) throw "ERROR LOG : Divide by ZERO!!!";
  } catch(const char *msg) {
    cerr << msg << "\n";
  }
  double ans = D * (x - A) - C * (x - B);
  ans /= B - A;
  return ans;
}

void scangraph();
void degree_centrality();
void local_degree_centrality();
void betweenness_centrality();
void closeness_centrality();
void pagerank_centrality();
void kshell_centrality();
void cascade_DC();
void cascade_LDC();
void cascade_BC();
void cascade_CC();
void cascade_PR();
void cascade_KS();
