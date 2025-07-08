#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 3;

int n;
vector<pair<int, int>> g[N];
int subSize[N], distSum[N];

void dfs1(int u, int par) {
    subSize[u] = 1;
    for (auto [v, w] : g[u]) {
        if (v == par)
            continue;
        dfs1(v, u);
        subSize[u] += subSize[v];
        distSum[u] += distSum[v] + subSize[v] * w;
    }
}

void dfs2(int u, int par) {
    for (auto [v, w] : g[u]) {
        if (v == par)
            continue;
        distSum[v] = distSum[u] + (n - 2 * subSize[v]) * w;
        dfs2(v, u);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   // int test;
   // cin >> test;
 //   while (test--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            subSize[i] = distSum[i] = 0;
        }

        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v;
            g[u].push_back({v, 1});
            g[v].push_back({u, 1});
        }

        dfs1(1, -1);
        dfs2(1, -1);

        for (int i = 1; i <= n; i++)
            cout << distSum[i] << " ";
  //  }
    return 0;
}
