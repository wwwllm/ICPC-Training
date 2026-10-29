#include <bits/stdc++.h>
#define MAXN 100050
using namespace std;

int n;
int t[MAXN], a[MAXN];
void solve(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (t[i] < t[j])
            a[k++] = t[i++];
        else
            a[k++] = t[j++];
    }
    while (i <= mid)
        a[k++] = t[i++];
    while (j <= r)
        a[k++] = t[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        t[i] = a[j];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    solve(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] << ' ';
    }
    return 0;
}
