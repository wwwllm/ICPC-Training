#include <bits/stdc++.h>
#define int long long
using namespace std;

// 将1的hd与2的atk排序
const int N = 2e5 + 10;
vector<array<int, 3>> arr;
vector<int> q;
int tr[N], n, m, ans[N];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int cnt)
{
    for (int i = x; i <N; i += lowbit(i))
        tr[i] += cnt;
}
int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}
bool cmp(array<int, 3> a, array<int,3> b)
{
    return a[0] == b[0] ? a[2] < b[2] : a[0] < b[0];
}
int find(int x)
{
    int l = -1, r = q.size(), mid;
    while (l + 1 != r)
    {
        mid = (l + r) >> 1;
        if (q[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int h, a;
        cin >> a >> h;
        arr.push_back({h, a, 0});
        q.push_back(h);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int h, a;
        cin >> a >> h;
        arr.push_back({a, h, i});
        q.push_back(h);
    }
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end()); // 按血量从小到大排序,去重
    sort(arr.begin(), arr.end(), cmp);            // 排序后的arr在2玩家前面的1的数量就是2玩家可以杀掉的，还要求1：atk小于2：hd;
    for (auto ele : arr)
    {
        int pos = find(ele[1])+1;
        if (ele[2] != 0)
        { // 如果是2号则寻找树状数组中小于hd的数量
            ans[ele[2]] = query(pos);
        }
        else
        { // 1号则将atk的在血量数组中的位置插入树状数组
            add(pos, 1);
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}