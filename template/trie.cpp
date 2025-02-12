// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 1e5;
// int tree[N][26], pass[N], en[N], cnt;
//
// void build() { cnt = 1; }
// void insert(string a) {
//   int cur = 1;
//   pass[cur]++;
//   for (int i = 0, path; i < a.length(); i++) {
//     path = a[i] - 'a';
//     if (tree[cur][path] == 0) {
//       tree[cur][path] = ++cnt;
//     }
//     cur = tree[cur][path];
//     pass[cur]++;
//   }
//   en[cur]++;
// }
//
// int search(string a) {
//   int cur = 1;
//   for (int i = 0, path; i < a.size(); i++) {
//     path = a[i] - 'a';
//     if (tree[cur][path] == 0) {
//       return 0;
//     }
//     cur = tree[cur][path];
//   }
//   return en[cur];
// }
//
// int prefixnumber(string a) {
//   int cur = 1;
//   for (int i = 0, path; i < a.size(); i++) {
//     path = a[i] - 'a';
//     if (tree[cur][path] == 0) {
//       return 0;
//     }
//     cur = tree[cur][path];
//   }
//   return pass[cur];
// }
//
// void del(string a) {
//   if (search(a) > 0) {
//     int cur = 1;
//     for (int i = 0, path; i < a.length(); i++) {
//       path = a[i] - 'a';
//       if (--pass[tree[cur][path]] == 0) {
//         tree[cur][path] = 0;
//         return;
//       }
//       cur = tree[cur][path];
//     }
//     en[cur]--;
//   }
// }
//
// void clear() {
//   fill(tree, tree + 26 * N, 0), fill(en + 1, en + N + 1, 0),
//       fill(pass + 1, pass + 1 + N, 0);
// }

// #include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 如果将来增加了数据量，就改大这个值
const int MAXN = 150001;
int tree[MAXN][26];
int terminal[MAXN]; // 将 end 改为 terminal 以避免命名冲突
int pass[MAXN];
int cnt;

// 初始化
void build() { cnt = 1; }

// 插入操作
void insert(string word) {
  int cur = 1;
  pass[cur]++;
  for (char i : word) { // 使用 size_t 作为循环变量
    int path = i - 'a';
    if (tree[cur][path] == 0) {
      tree[cur][path] = ++cnt;
    }
    cur = tree[cur][path];
    pass[cur]++;
  }
  terminal[cur]++;
}

// 搜索操作
int search(string word) {
  int cur = 1;
  for (char i : word) { // 使用 size_t 作为循环变量
    int path = i - 'a';
    if (tree[cur][path] == 0) {
      return 0;
    }
    cur = tree[cur][path];
  }
  return terminal[cur];
}

// 查找前缀的数量
int prefixNumber(string pre) {
  int cur = 1;
  for (char i : pre) { // 使用 size_t 作为循环变量
    int path = i - 'a';
    if (tree[cur][path] == 0) {
      return 0;
    }
    cur = tree[cur][path];
  }
  return pass[cur];
}

// 删除操作
void deleteStr(string word) {
  if (search(word) > 0) {
    int cur = 1;
    vector<int> pathStack;
    for (size_t i = 0; i < word.size(); ++i) { // 使用 size_t 作为循环变量
      int path = word[i] - 'a';
      pathStack.push_back(path);
      pass[tree[cur][path]]--;
      cur = tree[cur][path];
    }
    terminal[cur]--;
    cur = 1;
    for (size_t i = 0; i < pathStack.size(); ++i) { // 使用 size_t 作为循环变量
      int path = pathStack[i];
      if (pass[tree[cur][path]] == 0) {
        tree[cur][path] = 0;
      }
      cur = tree[cur][path];
    }
  }
}

// 清除操作
void clear() {
  for (int i = 1; i <= cnt; ++i) {
    memset(tree[i], 0, sizeof(tree[i]));
    terminal[i] = 0; // 修改为新的数组名
    pass[i] = 0;
  }
}

int m, op;
vector<string> splits;

int main() {
  string line;
  while (getline(cin, line)) {
    build();
    stringstream ss(line);
    ss >> m;
    for (int i = 1; i <= m; ++i) {
      getline(cin, line);
      stringstream ss2(line);
      ss2 >> op;
      string s;
      ss2 >> s;
      if (op == 1) {
        insert(s);
      } else if (op == 2) {
        deleteStr(s);
      } else if (op == 3) {
        if (search(s) > 0) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else if (op == 4) {
        cout << prefixNumber(s) << endl;
      }
    }
    clear();
  }
  return 0;
}
