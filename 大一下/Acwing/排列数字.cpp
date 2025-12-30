#include <bits/stdc++.h>
using namespace std;

int n,path[10];
bool b[10];
void dfs(int u){
    if(u==n+1){
        for (int i = 1; i <= n;i++)
            cout << path[i]<<' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n;i++){
        if(!b[i]){
            b[i] = 1;
            path[u] = i;
            dfs(u + 1);
            b[i] = 0;
        }
    }
}
signed main()
{
    cin >> n;
    dfs(1);
    return 0;
}