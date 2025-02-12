#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
bitset<N> vis;
int enrich(int n) {
  for (int i = 2; i <= n / i; i++) {
    if (!vis[i]) {
      for (int j = i * i; j <= n; j += i) {
        vis[j] = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      cnt++;
    }
  }
  return cnt;
}

// just for cnt
int enrich2(int n) {
  if (n <= 1) {
    return 0;
  }
  vis.reset(); // key;
  int cnt = (n + 1) / 2;
  for (int i = 3; i <= n / i; i += 2) {
    if (!vis[i]) {
      for (int j = i * i; j <= n; j += i * 2) {
        if (!vis[j]) {
          vis[j] = true;
          cnt--;
        }
      }
    }
  }
  return cnt;
}
