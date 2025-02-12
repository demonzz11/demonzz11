#include <bits/stdc++.h>
using namespace std;
static void f(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      cout << i << endl;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    cout << n << endl;
  }
}
