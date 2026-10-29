#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int j = 0;
    for (int i = 0; i < n; i++, j++)
    {
        while (j < m && a[i] != b[j])
            j++;
    }
    if (j <= m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}