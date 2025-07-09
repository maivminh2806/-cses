#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 3;
const int M=25;
int n;
vector<int> g[N];
int h[N];
int p[N][M];

void dfs(int u, int par) {
    for(auto v:g[u]){
        if(v!=par){
            h[v]=h[u]+1;
            p[v][0]=u;
            dfs(v,u);
        }
    }
}
void init(){
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}
int LCA(int u,int v){
    if(h[v]>h[u]){
        swap(u,v);
    }
    int x=h[u]-h[v];
    for(int i=log2(x);i>=0;i--){
            if(x>=(1<<i)){
                x-=(1<<i);
                u=p[u][i];
            }
        }
    if(u==v)
        return u;
    for(int i=log2(h[u]);i>=0;i--){
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    dfs(1,-1);
    init();
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    return 0;
}
