#include <bits/stdc++.h>
using namespace std;

struct qu
{
    int l, r;
};
const int N = 1e5 + 10;
qu a[N];
bool cmp(qu a, qu b)
{
    return a.l < b.l;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + 1 + n, cmp);
    int ans = 0, ed = -1e9 - 10;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].l <= ed)
        {
            ed = max(ed, a[i].r);
        }
        else
            ans++, ed = a[i].r;
    }
    cout << ans << endl;
    return 0;
}