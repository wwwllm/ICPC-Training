#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <array>
#include <cmath>
#include <iomanip>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto mex = [&](vector<int> &t) -> int
    {
        bool vis[4] = {};
        for (int x : t)
            if (x <= 3)
                vis[x] = true;
        for (int i = 0;; ++i)
            if (!vis[i])
                return i;
    };

    if (k == 1)
    {
    }
    else
    {
        if (k & 1)
        {
            k = 3;
        }
        else
        {
            k = 2;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        vector<int> b;
        for (int j = 0; j < n; j++)
        {
            vector<int> tmp;
            tmp.push_back(a[j]);
            tmp.push_back(a[(j + 1) % n]);
            tmp.push_back(a[(j - 1 + n) % n]);
            b.push_back(mex(tmp));
        }
        a = b;
    }
    for (int item : a)
        cout << item << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}