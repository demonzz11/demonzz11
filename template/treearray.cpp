#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int input = 0;

constexpr int N = 5e5 + 7;

int c[N];

int n, m;

int lowbit(int x) { return x & -x; }

int getsum(int x) {
  int ans = 0;
  while (x) {
    ans += c[x];
    x = x - lowbit(x);
  }
  return ans;
}

void add(int x, int k) {
  while (x <= n) {
    c[x] += k;
    x = x + lowbit(x);
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    add(i, a);
  }
  for (int i = 1; i <= m; i++) {
    int b, c, d;
    cin >> b >> c >> d;
    if (b == 1) {
      add(c, d);
    } else {
      cout << getsum(d) - getsum(c - 1) << endl;
    }
  }
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
