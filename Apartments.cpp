#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+2;
int n,m;
ll k,a[N],b[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    for (int i = 1; i <=n; i++)
        cin >> a[i];
    for (int j = 1; j <=m; j++)
        cin >> b[j];

    sort(a+1, a+n+1);
    sort(b+1,b+m+1);

    int i = 1, j = 1, cnt = 0;
    while (i<=n&&j<=m) {
        if (b[j]<a[i] - k) {
            j++;
        } else if (b[j] > a[i] + k) {
            i++;
        } else {
            cnt++;
            i++;
            j++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
