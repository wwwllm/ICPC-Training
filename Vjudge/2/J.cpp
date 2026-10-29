#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 将所有f(x)中有p这个因素的全部筛掉，且可以全部胜利
// min:在第i个人中x在比完i-1场后要可以赢第i个人。所有x>a[i]-i+1
// max:当x=a[i+p]-i时，在选择i个人比赛后x=a[i+p],x可以选择1--i+p中任意的人一共有p种选择。f(x)%p==0
//       所以x<a[i+p]-i;
const int maxn = 2005;
int a[maxn];
int n, p;
void solve()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int maxx = a[p], minx = a[n] - n + 1;
    for (int i = n ; i >= 1; i--)
    {
        minx = max(minx, a[i] - i + 1);
        if (i >= p)
        {
            maxx = min(maxx, a[i] - i + p);
        }
    }
    if (minx >= maxx)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << maxx - minx << endl;
        for (int i = minx; i < maxx; i++)
            cout << i << ' ';
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}