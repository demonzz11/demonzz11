#include "bits/stdc++.h"
using namespace std;
constexpr int N = 5e6 + 5;
bitset<N> vis;
int pre[N];
int eular(int n) {
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pre[cnt++] = i;
    }
    for (int j = 0; j < cnt; j++) {
      if (i * pre[j] > n)
        break;
      vis[i * pre[j]] = true;
      if (i % pre[j] == 0)
        break;
    }
  }
  return cnt;
}
