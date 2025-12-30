#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> PIA;
int n, m;
bool c[1 << 11];
signed main()
{
    cin >> n >> m;
    vector<vector<int>> a(m + 1, vector<int>(n+1));
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    queue<PIA> q;
    q.push({0, {}});
    while (q.size())
    {
        auto [oldx, arr] = q.front();
        if (oldx == (1 << n) - 1)
        {
            int len = arr.size();
            for (int i = 0; i < len;i++){
                if(i==len-1)
                    cout << arr[i];
                else
                    cout << arr[i] << ' ';
            }
            cout << endl;
            break;
        }
        q.pop();
        for (int i = 1; i <= m; i++)
        {
            int x = oldx;
            auto newarr = arr;
            newarr.push_back(i);
            auto b = a[i];
            for (int j = 0; j < n; j++)
            {
                if (b[j] == 1)
                    x = x | (1 << j);
                else if (b[j] == -1)
                    x = (x | (1 << j)) - (1 << j);
            }
            if(c[x])
                continue;
            q.push({x, newarr});
            c[x] = 1;
        }
    }
    return 0;
}