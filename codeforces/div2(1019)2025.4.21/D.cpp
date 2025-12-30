#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int ans[N];
void solve()
{
    int n;
    cin >> n;
    vector<int> b, a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(i);
    }
    int ma = n, mi = 1;
    for (int k = 1; b.size() > 1; k++)
    {
        int x = 0;
        while (a[b[x]] == k)
            x++;
        for (int i = 0; i < x; i++)
            if (a[b[i]] == k)
                ans[b[i]] = k & 1 ? ma-- : mi++;
        for (int i = b.size() - 1; i > x; i--)
            if (a[b[i]] == k)
                ans[b[i]] = k & 1 ? ma-- : mi++;
        vector<int> temp;
        for(auto it:b)
            if(a[it]!=k)
                temp.push_back(it);
        b = temp;
    }
    ans[b[0]]=mi;
    for (int i = 0; i < n;i++)
        cout << ans[i] <<' ';
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}