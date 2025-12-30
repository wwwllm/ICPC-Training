#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m;
int d[maxn],path[maxn],top=0;
vector<int>g[maxn];
queue<int> q;
signed main(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        d[r]++;
    }
    for (int i = 1; i <= n;i++){
        if(!d[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t = q.front();
        path[++top] = t;
        q.pop();
        for(auto son:g[t]){
            d[son]--;
            if(!d[son]){
                q.push(son);
            }
        }
    }
    if(top==n){
        for (int i = 1; i <= n;i++)
            cout << path[i] << ' ';
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}