#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
int n;
long long q,a[N],st[N<<2],lazy[N<<2];
void lazzy(int id){
    if(lazy[id]>0){
        int x=lazy[id];
        lazy[id]=0;
        lazy[id<<1]+=x;
        lazy[id<<1|1]+=x;
        st[id<<1]+=x;
        st[id<<1|1]+=x;
    }
}
void update(int id,int l,int r,int u,int v,int val){
    if(u>r||v<l)
        return ;
    if(l>=u&&r<=v)
    {
        st[id]+=val;
        lazy[id]+=val;
        return ;
    }
    int mid=(l+r)>>1;
    lazzy(id);
    update(id<<1,l,mid,u,v,val);
    update(id<<1|1,mid+1,r,u,v,val);
    st[id]=min(st[id<<1],st[id<<1|1]);
}
int get(int id,int l,int r,int u,int v){
    if(l>v||r<u)
        return 1e18;
    if(l>=u&&r<=v)
        return st[id];
    int mid=(l+r)>>1;
    lazzy(id);
    return min(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(1,1,n,i,i,a[i]);
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int u,v,val;
            cin>>u>>v>>val;
            update(1,1,n,u,v,val);
        }
        else{
            int u;
            cin>>u;
            cout<<get(1,1,n,u,u)<<endl;
        }
    }
    return 0;
}
