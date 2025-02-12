#include <gmpxx.h>
/*加减乘除模 https://www.luogu.com.cn/problem/P1932
- https://www.luogu.com.cn/record/153957114 e
https://codeforces.com/problemset/problem/1181/B 1500
https://codeforces.com/problemset/problem/1244/C 2000
https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/
可以用来优化 0-1 背包
*/
class Int {
public:
  mpz_class value;
  Int() : value(0) {}
  Int(int64_t x) : value(x) {}
  Int(const mpz_class &x) : value(x) {}

  Int adds(const Int &b) {
    value += b.value;
    return *this;
  }
  Int subs(const Int &b) {
    value -= b.value;
    return *this;
  }
  Int muls(const Int &b) {
    value *= b.value;
    return *this;
  }
  Int divs(const Int &b) {
    value /= b.value;
    return *this;
  }
  Int mods(const Int &b) {
    value %= b.value;
    return *this;
  }
  Int negs() {
    value = -value;
    return *this;
  }

  Int set(const Int &b) {
    value = b.value;
    return *this;
  }
  int cmp(const Int &b) const {
    return mpz_cmp(value.get_mpz_t(), b.value.get_mpz_t());
  }
  Int add(const Int &b) const { return Int(value + b.value); }
  Int sub(const Int &b) const { return Int(value - b.value); }
  Int mul(const Int &b) const { return Int(value * b.value); }
  Int div(const Int &b) const { return Int(value / b.value); }
  Int mod(const Int &b) const { return Int(value % b.value); }
  Int neg() const { return Int(-value); }

  int onesCount() const { return mpz_popcount(value.get_mpz_t()); }
};

class Rat {
public:
  mpq_class value;

  Rat() : value(0) {}
  Rat(int64_t a, int64_t b) : value(a, b) {}
  Rat(const mpq_class &x) : value(x) {}

  Rat adds(const Rat &b) {
    value += b.value;
    return *this;
  }
  Rat subs(const Rat &b) {
    value -= b.value;
    return *this;
  }
  Rat muls(const Rat &b) {
    value *= b.value;
    return *this;
  }
  Rat divs(const Rat &b) {
    value /= b.value;
    return *this;
  }
  Rat negs() {
    value = -value;
    return *this;
  }

  Rat set(const Rat &b) {
    value = b.value;
    return *this;
  }
  int cmp(const Rat &b) const {
    return mpq_cmp(value.get_mpq_t(), b.value.get_mpq_t());
  }
  Rat add(const Rat &b) const { return Rat(value + b.value); }
  Rat sub(const Rat &b) const { return Rat(value - b.value); }
  Rat mul(const Rat &b) const { return Rat(value * b.value); }
  Rat div(const Rat &b) const { return Rat(value / b.value); }
  Rat neg() const { return Rat(-value); }
};
