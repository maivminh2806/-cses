#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
int n;
vector<int>g[N];
int dp[N][2];

void dfs(int u, int p) {
    long long base = 0;
    // trước tiên chạy DFS qua con 0 là chưa đc nối , 1 là đã đc nối với con của nó
    for(int v: g[u])
        if(v!=p){
            dfs(v, u);
            base += max(dp[v][0], dp[v][1]);
        }
    dp[u][0] = base;
    long long bestGain = 0;
    for(int v: g[u])
        if(v!=p) {
            long long gain = 1 + dp[v][0] - max(dp[v][0], dp[v][1]);
            bestGain = max(bestGain, gain);
        }
    dp[u][1]=base+bestGain;
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}
