#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXB=30,N=2e5+2;
long long a[N],basis[MAXB];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];


    for (ll x : a) {
        for (int b =MAXB;b>=0;b--) {
            if (!(x & (1LL<< b))) continue;
            if (!basis[b]) {
                basis[b] = x;
                break;
            }
            x ^= basis[b];
        }
    }

    ll res = 0;
    for (int b = MAXB; b>=0;b--) {
        res = max(res, res^basis[b]);
    }

    cout << res << "\n";
    return 0;
}
