#include<bits/stdc++.h>
using namespace std;
long long n ;
int main()
{
    cin>>n;
    long long tong=n*(n+1)/2;
    while(n>1){
        n--;
        int x;
        cin>>x;
        tong-=x;
    }
    cout<<tong;
    return 0;
}
