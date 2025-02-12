#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int input = 0;
constexpr int N = 3e5;
int cnt;
int fa[N];
struct edge {
  int u, v, w;
} g[N];

int m, n;

void init(int n) {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int x, int y) { fa[y] = find(x); }

void add(int u, int v, int w) {
  cnt++;
  g[cnt].u = u;
  g[cnt].v = v;
  g[cnt].w = w;
}
void kus() {
  int tot = 0;
  int ans = 0;
  for (int i = 1; i <= cnt; i++) {
    int xr = find(g[i].u);
    int yr = find(g[i].v);
    if (xr != yr) {
      merge(xr, yr);
      tot++;
      ans += g[i].w;
    }
    if (tot >= n - 1) {
      cout << ans << endl;
      return;
    }
  }
  cout << "orz" << endl;
}

void solve() {
  cnt = 0;
  cin >> n >> m;
  init(n);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
  }
  ranges::sort(g + 1, g + 1 + m, [](edge x, edge y) { return x.w < y.w; });
  kus();
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  if (input)
    cin >> t;
  while (t--)
    solve();

  return 0;
}
