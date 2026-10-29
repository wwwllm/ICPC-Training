#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], d[N];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    while (q--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        d[r + 1] -= c;
        d[l] += c;
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + d[i], cout << a[i] << ' ';
    return 0;
}