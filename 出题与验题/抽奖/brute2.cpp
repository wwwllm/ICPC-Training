// brute2.cpp —— 第二题的暴力（穷举所有操作顺序，多重集记忆化搜索）
// 输入格式与 std2.cpp 相同，只适用于 n <= 12（再大状态数会爆）。
#include <bits/stdc++.h>
using namespace std;

struct H
{
    size_t operator()(const vector<int> &v) const
    {
        size_t h = 1469598103934665603ULL;
        for (int x : v)
        {
            h ^= (size_t)x + 0x9e3779b97f4a7c15ULL;
            h *= 1099511628211ULL;
        }
        return h;
    }
};
static unordered_map<vector<int>, set<int>, H> memo;

static const set<int> &go(const vector<int> &v)
{
    vector<int> key = v;
    sort(key.begin(), key.end());
    auto it = memo.find(key);
    if (it != memo.end())
        return it->second;
    set<int> res;
    if (key.size() == 1)
        res.insert(key[0]);
    else
        for (size_t i = 0; i < key.size(); i++)
            for (size_t j = i + 1; j < key.size(); j++)
            {
                vector<int> w;
                w.reserve(key.size() - 1);
                for (size_t t = 0; t < key.size(); t++)
                    if (t != i && t != j)
                        w.push_back(key[t]);
                w.push_back(abs(key[i] - key[j]));
                const set<int> &r = go(w);
                res.insert(r.begin(), r.end());
            }
    return memo[key] = res;
}

int main()
{
    int t;
    if (scanf("%d", &t) != 1)
        return 0;
    while (t--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        vector<int> v;
        long long nn = min(n, 12LL);
        if (n > 12)
        {
            printf("n too large\n");
            continue;
        }
        for (int i = 1; i <= nn; i++)
            v.push_back(i);
        const set<int> &r = go(v);
        printf("%s\n", r.count((int)k) ? "Yes" : "No");
    }
    return 0;
}
