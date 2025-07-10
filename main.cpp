#include <bits/stdc++.h>
using namespace std;
int N;
void hanoi(int n, int a, int b, int c) {
    if (n == 0) return;
    hanoi(n-1, a, c, b);
    cout << a << " " << b << endl;
    hanoi(n-1, c, b, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cout << ( (1LL<<N) - 1 ) <<endl;
    hanoi(N, 1, 3, 2);
    return 0;
}
