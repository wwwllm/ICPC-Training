#include <bits/stdc++.h>
#define int long long
using namespace std;
using u64 = unsigned long long;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
// 获取一个随机的 64 位整数
int get_random()
{
    return rng();
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> pre1(n + 1);
    vector hash1(n + 1, vector<u64>());
    vector pos(n + 1, vector<int>());
    vector<int> pre2(n + 1);
    vector<u64> hash2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]].push_back(i);
        hash2[i] = get_random();
    }
    for (int i = 1; i <= n; i++)
    {
        pre2[i] = pre2[i - 1] + hash2[a[i]];
    }
    while (k--)
    {
        int b;
        cin >> b;
        int res1 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (pos[i].empty())
                continue;
            hash1[i].clear();
            int sum = 0;
            for (int j = 0; j < pos[i].size(); j++)
            {
                int idx = pos[i][j];
                if (hash1[i].size() < b)
                {
                    if (hash1[i].size() == b - 1)
                    {
                        hash1[i].push_back((u64)sum);
                    }
                    else
                    {
                        hash1[i].push_back(get_random() | 1);
                        sum -= hash1[i].back();
                    }
                    pre1[idx] = hash1[i][j % b];
                }
                pre1[idx] = hash1[i][j % b];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            pre1[i] += pre1[i - 1];
        }
        vector<int> tmp(n + 1);
        map<u64, int> mp1;
        mp1[0]++;
        for (int r = 1, l = 0; r <= n; r++)
        {
            tmp[a[r]]++;
            while (l < r && tmp[a[r]] > b)
            {
                mp1[pre1[l]]--;
                tmp[a[++l]]--;
            }
            res1 += mp1[pre1[r]];
            mp1[pre1[r]]++;
        }
        cout << res1 << ' ';
        int res2 = 0;
        u64 sum = 0;
        vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
        int c1 = 0, c2 = 0;
        unordered_map<u64, int> mp2;
        int pl2 = 0;
        for (int r = 1, l1 = 0, l2 = 0; r <= n; r++)
        {
            cnt1[a[r]]++, cnt2[a[r]]++;
            c1 += cnt1[a[r]] == 1, c2 += cnt2[a[r]] == 1;
            bool f = cnt1[a[r]] == 1;
            if (cnt1[a[r]] == 1)
                sum += (u64)hash2[a[r]];
            while (l1 < r && c1 > b)
            {
                cnt1[a[++l1]]--;
                c1 -= cnt1[a[l1]] == 0;
                if (cnt1[a[l1]] == 0)
                    sum -= (u64)hash2[a[l1]];
            }
            while (l2 < r && c2 > b - 1)
            {
                cnt2[a[++l2]]--;
                c2 -= cnt2[a[l2]] == 0;
            }
            u64 s = (u64)pre2[r] * b - sum * r;
            if (f)
            {
                mp2.clear();
                for (int j = l1; j < l2; j++)
                {
                    u64 tmp = (u64)pre2[j] * b - j * sum;
                    mp2[tmp]++;
                }
                res2 += mp2[s];
            }
            else
            {
                for (int j = pl2; j < l2; j++)
                {
                    u64 tmp = (u64)pre2[j] * b - j * sum;
                    mp2[tmp]++;
                }
                res2 += mp2[s];
            }
            pl2 = l2;
        }
        cout << res2 << '\n';
    }
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