#include <bits/stdc++.h>
using namespace std;
#define int long long
int input = 0;
constexpr int N = 1e6 + 5;
int father[N];
int n, m;
void build() {
  for (int i = 0; i <= n; i++) {
    father[i] = i;
  }
}

int find(int i) {
  if (i != father[i]) {
    father[i] = find(father[i]);
  }
  return father[i];
}

bool issameset(int x, int y) { return find(x) == find(y); }

void un(int x, int y) { father[find(x)] = find(y); }

void solve() {
  cin >> n >> m;
  build();
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a == 2) {
      un(b, c);
    } else if (a == 1) {
      cout << (issameset(b, c) ? "Yes" : "No") << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // clock_t start, finish;
  // start = clock();

  int t = 1;
  if (input)
    cin >> t;
  while (t--)
    solve();

  // finish = clock();
  // cout <<endl<<"the time cost is:" << double(finish - start) /
  // CLOCKS_PER_SEC<<endl;

  return 0;
}
