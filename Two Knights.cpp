#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll sum = k * k * (k * k - 1) / 2;
        ll attacks = 0;
        if (k >= 3) {
            attacks = 4 * (k - 1) * (k - 2);
        }
        cout << (sum-attacks) << "\n";
    }

    return 0;
}
