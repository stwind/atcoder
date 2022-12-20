#include <bits/stdc++.h>
using namespace std;
#define VI vector<int>
#define VVI vector<VI>

int main()
{
  int N, K;
  cin >> N >> K;
  int R = K / 2;

  VI U(N - 1), V(N - 1);
  VVI graph(N + 1, VI(N + 1, 0));
  for (int i = 0; i < N - 1; i++)
  {
    cin >> U[i] >> V[i];
    graph[U[i]][V[i]] = graph[V[i]][U[i]] = 1;
  }

  if (K % 2 == 0)
  {
    int ret = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
      queue<int> q;
      q.push(i);
      unordered_set<int> seen;
      seen.insert(i);
      int r = 0, k = 0;
      while (!q.empty())
      {
        int n = q.size();
        while (n--)
        {
          int u = q.front();
          q.pop();
          for (int v = 1; v <= N; v++)
          {
            if (graph[u][v] && !seen.count(v))
            {
              seen.insert(v);
              q.push(v);
            }
          }
        }
        if (++r > R)
          k += q.size();
      }

      ret = min(ret, k);
    }
    cout << ret << endl;
  }
  else
  {
    int ret = INT_MAX;
    for (int i = 0; i < N - 1; i++)
    {
      queue<int> q;
      q.push(U[i]);
      q.push(V[i]);
      unordered_set<int> seen;
      seen.insert(U[i]);
      seen.insert(V[i]);
      int r = 0, k = 0;
      while (!q.empty())
      {
        int n = q.size();
        while (n--)
        {
          int u = q.front();
          q.pop();
          for (int v = 1; v <= N; v++)
          {
            if (graph[u][v] && !seen.count(v))
            {
              // cout << "v:" << v << endl;
              seen.insert(v);
              q.push(v);
            }
          }
        }
        if (++r > R)
          k += q.size();
      }
      ret = min(ret, k);
    }
    cout << ret << endl;
  }

  return 0;
}
