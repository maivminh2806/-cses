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
        int x,k;
        cin>>x>>k;
        if(h[x]<k)
            cout<<-1<<endl;
        else{
            for(int i=log2(k);i>=0;i--){
                if(k>=(1<<i)){
                    k-=(1<<i);
                    x=p[x][i];
                }
            }
            cout<<x<<endl;
        }
    }
    return 0;
}
