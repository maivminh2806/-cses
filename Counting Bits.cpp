#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int ans = 0;
    for (int i = 0; (1LL << i) <= n; ++i) {
        int len = 1LL << (i + 1);
        int full = n / len;
        ans += full * (1LL << i);

        int rem = n % len;
        int extra = rem - (1LL << i) + 1;
        if (extra > 0)
            ans += extra;
    }

    cout << ans;
    return 0;
}
