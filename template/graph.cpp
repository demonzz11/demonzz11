#include <bits/stdc++.h>

constexpr int N = 2e5;
int head[N];
int to[N];
int next[N];
int we[N];
int cnt = 1;

void add_edge(int u, int v, int w) {
  to[cnt] = v;
  we[cnt] = w;
  next[cnt] = head[u];
  head[u] = cnt++;
}
