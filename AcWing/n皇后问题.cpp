#include<bits/stdc++.h>
using namespace std;

int col[20], dg[20], udg[20];
int path[10], n;
void dfs(int u){
    if(u==n+1){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                if(path[i]==j)
                    cout << 'Q';
                else
                    cout << '.';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n;i++){
        if(!col[i]&&!dg[u+i]&&!udg[n-u+i]){
            col[i] = 1;
            dg[u + i] = 1;
            udg[n - u + i] = 1;
            path[u] = i;
            dfs(u + 1);
            col[i] = 0;
            dg[u + i] = 0;
            udg[n - u + i] = 0;
        }
    }
}
signed main(){
    cin >> n;
    dfs(1);
    return 0;
}