#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N =2e5+2;
const int M = 22;

int n, m;
vector<int> g[N];
int p[N][M], h[N];
ll cnt[N];

void dfs1(int u, int par){
    p[u][0] = par;
    for(int v : g[u]){
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs1(v, u);
    }
}

void init(){
    for(int j = 1; j <=20; j++){
        for(int i = 1; i <= n; i++){
            p[i][j] = p[ p[i][j-1] ][j-1];
        }
    }
}

int lca(int u, int v){
    if(h[u] <h[v])
        swap(u,v);
    int x = h[u] - h[v];
    for(int j = 0; j <=20; j++){
        if(x&(1<<j)){
            u = p[u][j];
        }
    }
    if(u == v)
        return u;

    for(int j = 20; j >= 0; j--){
        if(p[u][j] != p[v][j]){
            u = p[u][j];
            v = p[v][j];
        }
    }
    return p[u][0];
}

void dfs2(int u, int par){
    for(int v : g[u]){
        if(v == par)
            continue;
        dfs2(v, u);
        cnt[u] += cnt[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    h[1] = 0;
    dfs1(1, 0);
   init();

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        cnt[a] += 1;
        cnt[b] += 1;
        cnt[c] -= 1;
        if (p[c][0] != 0)
            cnt[p[c][0]] -= 1;
    }
    dfs2(1, 0);

    for(int u = 1; u <= n; u++){
        cout << cnt[u] << ' ';
    }
    return 0;
}
