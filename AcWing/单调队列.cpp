#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int q[maxn], a[maxn], hh, tt, ans[maxn];
void init()
{
    hh = 0, tt = 1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    for (int i = 1; i <= n; i++)
    { // 单调增
        while (hh < tt && q[hh] + k <= i)
            hh++;
        while (hh < tt && a[i] < a[q[tt - 1]])
            tt--;
        q[tt++] = i;
        if (i >= k)
            ans[i] = a[q[hh]];
    }
    for (int i = k; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    init();
    for (int i = 1; i <= n; i++)
    { // 单调减
        while (hh < tt && q[hh] + k <= i)
            hh++;
        while (hh < tt && a[i] > a[q[tt - 1]])
            tt--;
        q[tt++] = i;
        if (i >= k)
            ans[i] = a[q[hh]];
    }
    for (int i = k; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}