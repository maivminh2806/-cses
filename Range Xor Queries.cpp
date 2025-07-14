#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> x(n+1), P(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        P[i] = P[i-1] ^ x[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        // XOR of [a..b] = P[b] ^ P[a-1]
        cout << (P[b] ^ P[a-1]) << "\n";
    }

    return 0;
}
