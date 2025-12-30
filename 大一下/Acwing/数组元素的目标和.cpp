#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
signed main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0, j = m-1; i < n; i++)
    {
        while (a[i] + b[j] > x)
            j--;
        if (b[j] + a[i] == x)
        {
            cout << i << ' ' << j << endl;
            break;
        }
    }
    return 0;
}