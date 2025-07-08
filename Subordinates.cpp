#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
vector<int>g[N];
int d[N];
bool kt[N];
void DFS(int u){
    d[u]=1;
    for(auto v:g[u]){
        DFS(v);
        d[u]+=d[v];
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
   for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].push_back(i);
   }
    DFS(1);
   for(int i=1;i<=n;i++){
    cout<<d[i]-1<<" ";
   }
    return 0;
}
