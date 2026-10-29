#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
string s[N];
int ans1, ans2;
int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool dfs(int x, int y)
{
    bool flag = 0;
    char &c = s[x][y];
    if(c!='1')
        flag = 1;
    c = '0';
    for (auto [dx, dy] : walk)
    {
        int xx = x + dx, yy = dy + y;
        if (xx >= 0 && xx < n && yy < m && yy >= 0)
        {
            if (s[xx][yy] != '0')
                flag |= dfs(xx, yy);
        }
    }
    return flag;
}
signed main()
{
    cin >> n >> m;
    string x;
    getline(cin, x);
    for (int i = 0; i < n; i++)
        getline(cin, s[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] != '0')
            {
                if (dfs(i, j))
                    ans2++;
                ans1++;
            }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}