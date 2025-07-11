#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n;
long long x,a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    int l = 1, r = n ;
    int ans = 0;
    while (l <= r) {
        if (a[l] + a[r] <= x) {
            l++;
            r--;
        } else {
            r--;
        }
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
