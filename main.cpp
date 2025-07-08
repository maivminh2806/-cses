#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long maxx,tong=0;
    cin>>maxx;
    for(int i=2;i<=n;i++){
        long long x;
        cin>>x;
        if(x<maxx){
            tong+=(maxx-x);
        }
        else{
            maxx=x;
        }
    }
    cout<<tong;
    return 0;
}
