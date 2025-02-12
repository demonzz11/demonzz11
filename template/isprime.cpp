#include "bits/stdc++.h"
bool isprime(int n) {
  if (n <= 1) {
    return false;
  }
  int x = sqrt(static_cast<double>(n));
  for (int i = 2; i <= x; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
