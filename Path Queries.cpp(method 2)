#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;

int n, q, val[N];
vector<int> g[N];
int parent[N], depth[N], heavy[N], head[N], pos[N], sz[N];
int cur_pos;

struct SegTree {
    int st[4*N];
    void build(int id, int l, int r, int a[]) {
        if (l == r) { st[id] = a[l]; return; }
        int mid = (l+r)/2;
        build(id*2,l,mid,a);
        build(id*2+1,mid+1,r,a);
        st[id] = st[id*2] + st[id*2+1];
    }
    void update(int id, int l, int r, int p, int x) {
        if (l == r) { st[id] = x; return; }
        int mid = (l+r)/2;
        if (p <= mid) update(id*2,l,mid,p,x);
        else update(id*2+1,mid+1,r,p,x);
        st[id] = st[id*2] + st[id*2+1];
    }
    int query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return query(id*2,l,mid,u,v)+query(id*2+1,mid+1,r,u,v);
    }
} seg;

int dfs1(int u, int p) {
    parent[u] = p;
    depth[u] = depth[p]+1;
    sz[u]=1;
    int maxsz=0;
    for (int v:g[u]) if(v!=p){
        int s=dfs1(v,u);
        sz[u]+=s;
        if(s>maxsz) maxsz=s,heavy[u]=v;
    }
    return sz[u];
}

void dfs2(int u, int h){
    head[u]=h;
    pos[u]=++cur_pos;
    if(heavy[u]) dfs2(heavy[u],h);
    for(int v:g[u]) if(v!=parent[u]&&v!=heavy[u]) dfs2(v,v);
}

int path_query(int u){
    int res=0;
    while(u){
        res+=seg.query(1,1,n,pos[head[u]],pos[u]);
        u=parent[head[u]];
    }
    return res;
}

int a[N];
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<=n;i++) a[pos[i]]=val[i];
    seg.build(1,1,n,a);

    while(q--){
        int t;cin>>t;
        if(t==1){
            int s,x;
            cin>>s>>x;
            seg.update(1,1,n,pos[s],x);
        }else{
            int s;cin>>s;
            cout<<path_query(s)<<"\n";
        }
    }
}
