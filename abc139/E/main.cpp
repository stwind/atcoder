#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 61)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

string make_node(int a, int b) {
  string s = to_string(a), t = to_string(b);
  return a < b ? s + ":" + t : t + ":" + s;
}

int main() {
  int N;
  cin >> N;

  int a;
  unordered_map<string, vector<string>> G;
  unordered_map<string, int> D;
  forn(i, 0, N) {
    string prev, cur;
    forn(j, 0, N - 1) {
      cin >> a;
      cur = make_node(i + 1, a);
      if (!D.count(cur))
        D[cur] = 0;
      if (j) {
        G[prev].push_back(cur);
        D[cur]++;
      }
      prev = cur;
    }
  }

  queue<string> q;
  for (auto &x : D) {
    if (x.second == 0)
      q.push(x.first);
  }

  int d = 0, tot = q.size();
  while (!q.empty()) {
    d++;
    int n = q.size();
    for (int i = 0; i < n; i++) {
      string u = q.front();
      q.pop();
      for (auto v : G[u]) {
        D[v]--;
        if (D[v] == 0) {
          q.push(v);
          tot++;
        }
      }
    }
  }
  cout << (tot == N * (N - 1) / 2 ? d : -1) << endl;

  return 0;
}