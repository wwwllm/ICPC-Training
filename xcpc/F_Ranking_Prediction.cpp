#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105945
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int s;
    cin >> s;
    vector<int> pd;
    vector<int> pro(15);
    int time = 0;
    int cnt = 0;
    for (int i = 1; i <= s; i++)
    {
        int t;
        char p;
        string v;
        cin >> t >> p >> v;
        int num = p - 'A';
        if (v == "pd" && pro[num] != -1)
        {
            pd.push_back(pro[num] * 20 + t);
            pro[num] = -1;
        }
        else if (v == "rj" && pro[num] != -1)
        {
            pro[num]++;
        }
        else if (v == "ac" && pro[num] != -1)
        {
            time += t + 20 * pro[num];
            pro[num] = -1;
            cnt++;
        }
    }
    ranges::sort(pd);
    int i = 0;
    for (i = 0; i < pd.size(); i++)
    {
        if (cnt > a || (cnt == a && time < b))
        {
            cout << i << '\n';
            return;
        }
        time += pd[i];
        cnt++;
    }
    if (cnt > a || (cnt == a && time < b))
    {
        cout << pd.size() << '\n';
        return;
    }
    cout << -1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}