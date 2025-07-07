#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int maxx = 1, len = 1;
    for (int i = 1;i <s.size();i++) {
        if (s[i] == s[i - 1]) {
            len++;
        } else {
            len = 1;
        }
        maxx = max(maxx, len);
    }

    cout << maxx ;
    return 0;
}
