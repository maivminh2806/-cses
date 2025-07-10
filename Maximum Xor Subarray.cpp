#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
string s;
int n , m,pre[N];
struct trie
{
    int tp;
    trie *child[2];
    trie()
    {
       tp = 0;
       for(int i = 0 ; i < 2 ; i++)
            child[i] = NULL;
    }
};

trie *root;

void insert(string s , int val)
{
    trie *p = root;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(p -> child[s[i] - '0'] == NULL)
            p -> child[s[i] - '0'] = new trie();
        p = p -> child[s[i] - '0'];
    }
    p -> tp =val;
}

int add(string s)
{
    trie *p = root;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '0')
        {
            if(p -> child[1] != NULL)
                p = p -> child[1];
            else
                p = p -> child[0];
        }
        else
        {
            if(p -> child[0] != NULL)
                p = p -> child[0];
            else
                p = p -> child[1];
        }
    }
    return p -> tp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    root = new trie();

    cin >> n;
    int res=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pre[i]=pre[i-1]^x;
    }
    string np="";
    for(int i=0;i<=30;i++){
        np+='0';
    }
    insert(np,0);
    for(int i=1;i<=n;i++){
        np="";
        for(int j = 30 ; j >= 0 ; j--)
            np += (char)(((pre[i] >> j) & 1) + '0');
        int kk=add(np);
        res=max(res,kk^pre[i]);
        insert(np,pre[i]);
    }
    cout<<res;
}
