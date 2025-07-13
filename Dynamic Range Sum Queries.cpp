#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
int n;
long long q,a[N],st[N<<2];
void update(int id,int l,int r,int pos,int val){
    if(pos>r||pos<l)
        return ;
    if(l==r)
    {
        st[id]=val;
        return ;
    }
    int mid=(l+r)>>1;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    st[id]=st[id<<1]+st[id<<1|1];
}
int get(int id,int l,int r,int u,int v){
    if(l>v||r<u)
        return 0;
    if(l>=u&&r<=v)
        return st[id];
    int mid=(l+r)>>1;
    return get(id<<1,l,mid,u,v)+get(id<<1|1,mid+1,r,u,v);
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(1,1,n,i,a[i]);
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int pos,val;
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
        else{
            int u,v;
            cin>>u>>v;
            cout<<get(1,1,n,u,v)<<endl;
        }
    }
    return 0;
}
