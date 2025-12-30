#include <bits/stdc++.h>

using namespace std;

string s[110];
int g[20][20];
unordered_map<int, int> mp;
signed main()
{
    int n, m;
    cin >> n >> m;
    getline(cin, s[0]);
    for (int i = 1; i <= n; i++)
        getline(cin, s[i]);
    for (int i = 1; i <= m; i++)
    {
        int v;
        cin >> v;
        mp[v] = i;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= 10; j++)
            cin >> g[i][j];
    int k;
    cin >> k;
    while (k--)
    {
        int pos;
        cin >> pos;
        int x = pos % 10, y = pos / 10;
        if (mp.find(y) == mp.end()){
            if(k==0)
                cout << "?";
            else
                cout << "?" << endl;
        }
        int j = mp[y];
        if (k == 0)
        {
            if (g[j][x + 1] == -1)
                cout << "?";
            else
                cout << s[g[j][x + 1]];
        }
        else
        {
            if (g[j][x + 1] == -1)
                cout << "?" << endl;
            else
                cout << s[g[j][x + 1]] << endl;
        }
    }
    return 0;
}