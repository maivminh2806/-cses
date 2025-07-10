#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e5 + 5;
int n , q , ti;
int c[N] , in[N] , out[N] , st[4 * N];
vector < int > g[N];

void DFS(int u , int par)
{
    in[u] = out[u] = ++ti;
    for(auto v: g[u])
        if(v != par)
        {
            DFS(v , u);
            out[u] = max(out[u] , out[v]);
        }
}

void update(int id , int l , int r , int pos , int val)
{
    if(l > pos || r < pos)
        return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 , l , mid , pos , val);
    update(id * 2 + 1 , mid + 1 , r , pos , val);
    st[id] = (st[id * 2] + st[id * 2 + 1]);
}

int get(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return 0;
    if(l >= u && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    return (get(id * 2 , l , mid , u , v)
         + get(id * 2 + 1 , mid + 1 , r , u , v));
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        cin >> c[i];

    for(int i = 1 ; i <= n - 1 ; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1 , -1);


    for(int i = 1 ; i <= n ; i++)
        update(1 , 1 , n , in[i] , c[i]);

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int u , val;
            cin >> u >> val;
            update(1 , 1 , n , in[u] , val);
        }
        else
        {
            int u;
            cin >> u;
            cout<<get(1,1,n,in[u],out[u])<<endl;
        }
    }



}
