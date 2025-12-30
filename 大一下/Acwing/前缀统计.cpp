#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int son[N][26], idx, cnt[N], n,m;
string str;
void insert(string str){
    int p = 0;
    for(auto c:str){
        int u = c - 'a';
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(string str){
    int p = 0,ans=0;
    for(auto c:str){
        int u = c - 'a';
        if(!son[p][u])
            return ans;
        p = son[p][u];
        if(cnt[p])
            ans += cnt[p];
    }
    return ans;
}
signed main(){
    cin >> n>>m;
    for (int i = 1; i <= n;i++){
        cin >> str;
        insert(str);
    }
    while(m--){
        string t;
        cin >> t;
        cout << query(t) << endl;
    }
        return 0;
}