#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2;
struct mat {
  int a[N][N];
};
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {}

vector<vector<int>> pow(vector<vector<int>> a, int p) {
  int n = a.size();
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++) {
    ans[i][i] = 1;
  }
  for (; p; p >>= 1) {
    if (p & 1)
      mul(a, ans);
    ans = mul(ans, ans);
  }
  return ans;
}
