

#ifndef _GEN_GRAPH_H
#define _GEN_GRAPH_H

#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <iostream>
#include "gen_seq.h"

#define CONNECT 1
#define NOT_CONNECT 0
#define NO_SELF_LOOP 0
#define ALLOW_SELF_LOOP 1
#define ALLOW_SAME_EDGE 1
#define NO_SAME_EDGE 0

struct graph {
  std::vector<std::pair<int, int>> E;
  std::set<std::pair<int, int>> S;
  void print() {
    for (int i = 0; i < E.size(); ++i) {
      printf("%d %d\n", E[i].first, E[i].second);
    }
    puts("");
  }
  void printw(int l, int r) { //带边权
    for (int i = 0; i < E.size(); ++i) {
      printf("%d %d %d\n", E[i].first, E[i].second, random(l, r));
    }
    puts("");
  }
  void init() {
    E.clear();
    S.clear();
  }

  void add_edge(std::pair<int, int> p) {
    E.push_back(p);
    if (p.first > p.second)
      std::swap(p.first, p.second);
    S.insert(p);
  }
  void add_edge(int x, int y) { //让加边更方便
    add_edge(std::make_pair(x, y));
  }
  bool check(std::pair<int, int> p) {
    if (p.first > p.second)
      std::swap(p.first, p.second);
    if (S.count(p))
      return false;
    else
      return true;
  }
  void shuffle() { random_shuffle(E.begin(), E.end()); }
};
std::pair<int, int> random_edge(int n, bool has_loop = 0) {
  int u = random(1, n), v = random(1, n);
  if (!has_loop) {
    while (u == v)
      v = random(1, n);
  }
  return std::make_pair(u, v);
}
graph random_tree(int n) {
  graph g;
  for (int i = 2; i <= n; ++i) {
    //		g.E.push_back(std::make_pair(random(1,i-1),i));
    //原来这里没有更新S,会导致重边
    g.add_edge(std::make_pair(random(1, i - 1), i));
  }
  return g;
}
graph chain(int n) {
  graph g;
  for (int i = 2; i <= n; ++i) {
    g.add_edge(std::make_pair(i - 1, i));
  }
  return g;
}
graph jhgraph(int n, int nd) {
  graph g;
  for (int i = 1; i <= n; ++i) {
    if (i != nd)
      g.E.push_back(std::make_pair(i, nd));
  }
  return g;
}
graph random_graph(int n, int m, bool is_connect = 1, bool has_same_edge = 0,
                   bool has_loop = 0) {
  graph g;
  if (is_connect) {
    if (m <= n - 1) {
      std::cerr << "Error." << std::endl;
      return graph();
    }
    g = random_tree(n);
    //		g.print();
    for (int i = 1; i <= m - n + 1; ++i) {
      std::pair<int, int> e = random_edge(n, has_loop);
      if (!has_same_edge) {
        while (!g.check(e))
          e = random_edge(n, has_loop);
      }
      g.add_edge(e);
    }
  } else {
    for (int i = 1; i <= m; i++) {
      std::pair<int, int> e = random_edge(n, has_loop);
      if (!has_same_edge) {
        while (!g.check(e))
          e = random_edge(n, has_loop);
      }
      g.add_edge(e);
    }
  }
  return g;
}
graph random_dag(int n, int m, bool has_same_edge = 0) {
  sequence topo = gen_permutation(n); //生成拓扑序
  if (n == 1 && m > 0) {
    std::cerr << "Error." << std::endl;
    return graph();
  }
  graph g;
  for (int i = 1; i <= m; i++) {
    int x = random(1, n - 1);
    int y = random(x + 1, n);
    std::pair<int, int> e = std::make_pair(topo.S[x - 1], topo.S[y - 1]);
    if (!has_same_edge) {
      while (!g.check(e)) {
        x = random(1, n - 1);
        y = random(x + 1, n);
        e = std::make_pair(topo.S[x - 1], topo.S[y - 1]);
      }
    }
    g.add_edge(e);
  }
  return g;
}
#endif
