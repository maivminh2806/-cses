#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
int n;
vector<int>g[N];
int d[N];
void BFS(int u){
    for(int i=1;i<=n;i++)
        d[i]=1e9;
    d[u]=0;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS(1);
    int mx=0,luu=0;
    for(int i=1;i<=n;i++){
        if(mx<d[i]){
            mx=d[i];
            luu=i;
        }
    }
    BFS(luu);
    for(int i=1;i<=n;i++)
        mx=max(mx,d[i]);
    cout<<mx;
    return 0;
}
