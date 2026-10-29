// brute1.cpp —— 抽奖 的暴力（对拍用）：每个询问 O(len)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, Q;
    if (scanf("%d %d", &n, &Q) != 2)
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<int> ys = a;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = ys.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin();
    vector<int> cnt(m, 0), seen(m, 0);
    for (int qi = 1; qi <= Q; qi++)
    {
        int l, r;
        long long p, q;
        scanf("%d %d %lld %lld", &l, &r, &p, &q);
        long long len = r - l + 1;
        vector<int> touched;
        for (int i = l; i <= r; i++)
        {
            int v = id[i - 1];
            if (seen[v] != qi)
                seen[v] = qi, cnt[v] = 0, touched.push_back(v);
            cnt[v]++;
        }
        int ans = -1;
        for (int v : touched)
            if ((long long)cnt[v] * q > len * p)
            {
                ans = ys[v];
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}
