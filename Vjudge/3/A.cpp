#include <bits/stdc++.h>
using namespace std;

char p[4][4];
void solve()
{
    for (int i = 1; i <= 3;i++){
        for (int j = 1; j <= 3;j++){
            cin >> p[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        if(p[i][1]==p[i][2]&&p[i][2]==p[i][3]){
            if (p[i][1] != '.'){
                cout << p[i][1] << endl;
                return;
            }
        }
    }
    for(int i=1;i<=3;i++){
        if(p[1][i]==p[2][i]&&p[2][i]==p[3][i]){
            if(p[1][i]!='.'){
                cout << p[1][i] << endl;
                return;
            }
        }
    }
    if(p[1][1]==p[2][2]&&p[3][3]==p[2][2]){
        if (p[1][1] != '.')
        {
            cout << p[1][1] << endl;
            return;
        }
    }
    if(p[1][3]==p[2][2]&&p[3][1]==p[2][2]){
        if (p[1][3] != '.')
        {
            cout << p[1][3] << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
