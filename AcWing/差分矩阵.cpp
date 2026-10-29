#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N], d[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = a[i][j] + a[i - 1][j - 1] - a[i][j - 1] - a[i - 1][j];
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        d[x1][y1] += c, d[x2 + 1][y2 + 1] += c;
        d[x1][y2 + 1] -= c, d[x2 + 1][y1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j], cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}