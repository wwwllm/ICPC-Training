# Ubuntu ICPCOS

创建run.sh

```shell
#!/bin/bash 或者 #!/bin/sh
target=$1
src="${target}.cpp"
g++ -std=gnu++20 -O2 -Wall -Wextra "$src" -o "$target" && \
./"$target" 2>&1 | tee "${target}.txt"
```

随后chmod +x ./run.sh

./run.sh A
# 位运算

```c
popcount()//1的个数
countl_zero()//前导零
countr_zero()//后缀零
countl_one()//前导1
countr_one()//后缀1
has_single_bit()//是否只有一个1
bit_floor()	//向下取整到最近的2的幂
bit_ceil()	//向上取整到最近的2的幂
    
__builtin_popcount();//1的个数
__builtin_popcountll();
__builtin_clz();//前导零
__builtin_clzll();//ull
__builtin_ctz()//后缀零
__builtin_ctzll();//ull
```
# 向上向下取整

```c
int Ceil(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and !((n1 < 0)^(n2 < 0))) x++;
    return x;
}

int Floor(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and ((n1 < 0)^(n2 < 0))) x--;
    return x;
}
```
# 随机数

```c
int randINT(int l, int r) {
    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}
```
# 三分查找

```c
	//查找区间最大值,要求f是严格单峰
	auto f=[&](int x) {
		
	};

	int lo,hi,res; 
    while (hi-lo > 3) {
        int m1=lo+(hi-lo)/3;
        int m2=hi-(hi-lo)/3;
        if (f(m1) < f(m2)) lo=m1+1;
        else hi=m2-1;
    }
    res=f(lo);
    for (int i=lo+1;i<=hi;i++){
        res=max(res,f(i));
    }
```
# int128

### 代码

```cpp
using i128 = __int128;
 
std::ostream &operator<<(std::ostream &os, i128 n)
{
    if (n == 0)
    {
        return os << 0;
    }
    bool sign = 0;
    if (n < 0)
    {
        sign = 1;
        n = -n;
    }
    std::string s;
    while (n > 0)
    {
        s += char('0' + n % 10);
        n /= 10;
    }
    if (sign)
        s = s + '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}
std::istream &operator>>(std::istream &is, i128 &n)
{
    string s;
    if (is >> s)
    {
        n = 0;
        bool sign = s[0] == '-';
        for (int i = sign; i < s.size(); i++)
        {
            n = n * 10 + (s[i] - '0');
        }
        if (sign)
            n = -n;
    }
    return is;
}
i128 toi128(const std::string &s)
{
    i128 n = 0;
    bool sign = s[0] == '-';
    for (auto c : s)
    {
        if (c == '-')
            continue;
        n = n * 10 + (c - '0');
    }
    return sign ? -n : n;
}

i128 sqrti128(i128 n)
{
    i128 l = 0, r = 2e18;
    while (l + 1 != r)
    {
        i128 mid = l + (r - l + 1) / 2;
        if (mid <= n / mid)
            l = mid;
        else
            r = mid;
    }
    return l;
}

i128 gcd(i128 a, i128 b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
```

# 并查集

## 定义

### 实现
 
#### 代码

```cpp
struct DSU
{
    vector<int> f, siz;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
    }

    int count()
    {
        return cnt;
    }
};
```
# 可撤销并查集

## 定义

可撤销并查集支持在传统的合并（Union）和查询（Find）操作之上，撤销最近执行的合并操作，回退到之前的历史状态。由于路径压缩会破坏树的原始形态并带来大量状态变更，可撤销并查集**严禁使用路径压缩**，必须采用启发式合并（按大小 `sz` 或深度 `dep` 合并）以保证单次操作的时间复杂度稳定在 $O(\log n)$。

### 实现

使用 `vector<pair<int, int>>` 作为操作栈，记录每次成功合并的父子节点对 `(x, y)`。撤销时按先进后出的顺序恢复 `p` 数组和 `sz` 数组。

#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> f, siz;
    int cnt;
    vector<pair<int, int>> st; // 记录历史操作的栈

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        st.clear();
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        
        // 启发式合并：小树合入大树，保证树高 O(log n)
        if (siz[x] < siz[y]) swap(x, y);
        
        st.push_back({x, y}); // 记录谁成为了谁的父亲
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x) {
        return siz[find(x)];
    }

    int count() {
        return cnt;
    }
    
    // 获取当前时间戳
    int time() {
        return st.size();
    }
    
    // 回滚至指定时间戳 t
    void roll_back(int t) {
        while (st.size() > t) {
            auto [x, y] = st.back();
            st.pop_back();
            f[y] = y;         // 恢复父节点指向自己
            siz[x] -= siz[y]; // 恢复连通块大小
            cnt++;            // 恢复连通块数量
        }
    }
};
```
# 莫队

## 形式

假设 $n=m(m为询问次数)$，对于序列上的区间询问问题，如果从 $[l,r]$ 从 $O(1)$扩展到 $[l-1,r]，[l+1,r],[l,r-1],[l,r+1]$。那么 $O(n\sqrt{n})$的时间复杂度求出所有询问。
## 实现

 离线后排序，顺序处理每个询问，暴力从上一个区间的答案转移到下一个区间答案（一步一步移动即可）．

**排序方法：**
	对于区间 $[l,r]$ 以 $l$ 所在的块为第一关键字， $r$为第二关键字排序。
 
### 代码

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6;
int len;
struct Q
{
    int l,r,idx,bl;
    bool operator <(const Q &q)const{
		if (bl != q.bl) return bl < q.bl;
        return (bl&1) ? (r < q.r) : (r > q.r);
	}
};
vector<int>cnt(N+1);
int res=0;
void solve(){
    int n;
    cin>>n;
    len=max(1LL,(int)(n/sqrt(n)));
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    vector<Q>qu(q);
    int p=0;
    for(auto &[l,r,id,bl]:qu){
        cin>>l>>r;
        id=p++;
        bl=l/len;
    }
    auto add=[&](int x){
        if(cnt[a[x]]==0)res++;
        cnt[a[x]]++;
    };
    auto del=[&](int x){
        if( cnt[a[x]]==1)res--;
        cnt[a[x]]--;
    };
    sort(qu.begin(),qu.end());
    int l=1,r=0;
    vector<int>ans(q);
    for(auto &[L,R,idx,_]:qu){
        while(l>L)add(--l);
        while(l<L)del(l++);
        while(r>R)del(r--);
        while(r<R)add(++r);
        ans[idx]=res;
    }
    for(auto x:ans)cout<<x<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
```

# 线段树

带懒标记
## 代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int sum, max, min;
    int size;
    Info() : sum(), max(-inf), min(inf), size(0) {};
    Info(int value) : sum(value), max(value), min(value), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.max = std::max(max, other.max);
        res.min = std::min(min, other.min);
        res.size = size + other.size;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, int v)
    {
        tag[p] += v;
        info[p].sum += v * info[p].size;
        info[p].max += v;
        info[p].min += v;
    }
    void push(int p) // 懒标记下放
    {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        push(p);
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 区间修改[x,y)
    void rangeAdd(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return add(p, v);
        }
        int mid = l + r >> 1;
        push(p);
        rangeAdd(p << 1, l, mid, x, y, v);
        rangeAdd(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeAdd(int x, int y, int v)
    {
        rangeAdd(1, 0, n, x, y, v);
    }
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        push(p);
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    SegTree T(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        T.modify(i, x);
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            T.rangeAdd(x - 1, y, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            Info v = T.query(x - 1, y);
            cout << v.sum << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```

## 代码
不带懒标记
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int sum, max, min;
    int size;
    Info() : sum(), max(-inf), min(inf), size(0) {};
    Info(int value) : sum(value), max(value), min(value), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.max = std::max(max, other.max);
        res.min = std::min(min, other.min);
        res.size = size + other.size;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    SegTree T(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        T.modify(i, x);
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            T.rangeAdd(x - 1, y, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            Info v = T.query(x - 1, y);
            cout << v.sum << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```
# 线段树分治

## 定义

线段树分治是一种基于时间轴的离线算法。当题目中元素或操作具有“生存时间区间”时，将时间轴作为线段树的区间，将每个元素的存活期转化为线段树上的区间覆盖。随后通过 DFS 遍历线段树，配合**可撤销**的数据结构（如可撤销并查集）维护状态。当遍历至叶子节点时处理该特定时刻的询问，回溯时严格撤销状态变化。

### 实现

线段树分治 + 可撤销并查集（最基础且最常见的搭配）。
区间按 `[l, r)` 左闭右开规范处理。

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> f, siz;
    int cnt;
    vector<pair<int, int>> st; // 记录历史操作的栈

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        st.clear();
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;

        // 启发式合并：小树合入大树，保证树高 O(log n)
        if (siz[x] < siz[y])
            swap(x, y);

        st.push_back({x, y}); // 记录谁成为了谁的父亲
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
    }

    int count()
    {
        return cnt;
    }

    // 获取当前时间戳
    int time()
    {
        return st.size();
    }

    // 回滚至指定时间戳 t
    void roll_back(int t)
    {
        while (st.size() > t)
        {
            auto [x, y] = st.back();
            st.pop_back();
            f[y] = y;         // 恢复父节点指向自己
            siz[x] -= siz[y]; // 恢复连通块大小
            cnt++;            // 恢复连通块数量
        }
    }
};
struct Info
{
    array<int, 2> e;
    Info() {};
    Info(int u, int v) { e = {u, v}; };
    Info(array<int, 2> e) : e(e) {};
};
struct SegTree
{
    int n;
    vector<vector<Info>> info;

    SegTree(int n) : n(n), info(4 * n) {};
    void modify(int p, int l, int r, int ql, int qr, Info e)
    {
        if (ql <= l && r <= qr)
        {
            info[p].push_back(e);
            return;
        }
        if (ql >= r || qr <= l)
            return;
        int mid = l + r >> 1;
        if (ql < mid)
            modify(p << 1, l, mid, ql, qr, e);
        if (qr > mid)
            modify(p << 1 | 1, mid, r, ql, qr, e);
    }
    void modify(int l, int r, array<int, 2> e)
    {
        modify(1, 0, n, l, r, e);
    }
};
void solve()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    SegTree T(k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        T.modify(l, r, {u, v});
    }
    DSU dsu(2 * n + 1);

    auto dfs = [&](auto &&self, int p, int l, int r, bool ok) -> void
    {
        int cur = dsu.time();
        if (ok)
        {
            for (auto e : T.info[p])
            {
                auto [u, v] = e.e;
                if (dsu.find(u) == dsu.find(v))
                {
                    ok = 0;
                    break;
                }
                dsu.merge(u, v + n);
                dsu.merge(v, u + n);
            }
        }
        if (r - l == 1)
        {
            cout << (ok ? "Yes\n" : "No\n");
        }
        else
        {
            int mid = l + r >> 1;
            self(self, p << 1, l, mid, ok);
            self(self, p << 1 | 1, mid, r, ok);
        }
        dsu.roll_back(cur);
    };
    dfs(dfs, 1, 0, k, 1);
}
signed main()
{
    solve();
    return 0;
}
```

# 线段树合并与分裂 (Segment Tree Merge & Split)

## 定义
线段树合并用于将两棵动态开点线段树的信息整合到一起。线段树分裂则是合并的逆过程，将一棵线段树中指定范围的结点拆分出来形成一棵新树。

### 复杂度
* **合并**: 均摊时间复杂度为 $O(\log n)$，其中 $n$ 为值域范围。总复杂度通常取决于插入的总结点数。
* **分裂**: 每次分裂的时间复杂度为 $O(\log n)$。
* **空间**: 动态开点通常需要 $O(m \log n)$ 的空间，$m$ 为操作次数。

## 实现

### 代码
```cpp
struct SegTree
{
    struct Node
    {
        int l;
        int r;
        int cnt;
    };
    vector<int> root;
    int tot;
    int n; // 值域
    vector<Node> info;
    SegTree(int n, int nodes, int ver) : n(n), tot(0)
    {
        info.assign(nodes, {0, 0, 0});
        root.assign(ver + 1, 0);
    }
    void pull(int p)
    {
        int l = info[p].l, r = info[p].r;
        info[p].cnt = info[l].cnt + info[r].cnt;
    }

    void modify(int &p, int pre, int l, int r, int x, int v)
    {
        p = ++tot;
        info[p] = info[pre];

        if (r - l == 1)
        {
            info[p].cnt += v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(info[p].l, info[p].l, l, mid, x, v);
        }
        else
        {
            modify(info[p].r, info[p].r, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int ver, int pre_ver, int x, int v = 1)
    {
        modify(root[ver], root[pre_ver], 0, n, x, v);
    }

    int merge(int p, int q, int l, int r)
    {
        if (!p || !q)
            return p | q;

        int rt = ++tot;

        if (r - l == 1)
        {
            info[rt].cnt = info[p].cnt + info[q].cnt;
            return rt;
        }
        int mid = l + r >> 1;
        info[rt].l = merge(info[p].l, info[q].l, l, mid);
        info[rt].r = merge(info[p].r, info[q].r, mid, r);
        pull(rt);
        return rt;
    }
    void merge_ver(int new_ver, int u, int v)
    {
        root[new_ver] = merge(root[u], root[v], 0, n);
    }
    //将p的前k个移动给q
    void Split(int &p, int &q, int k)
    {
        if (!p)
            return;
        if (k >= info[p].cnt)
        {
            q = p;
            p = 0;
            return;
        }
        q = ++tot;
        int v = info[info[p].l].cnt;
        if (k > v)
        {
            info[q].l = info[p].l;
            info[p].l = 0;
            Split(info[p].r, info[q].r, k - v);
        }
        else if (k == v)
        {
            info[q].l = info[p].l;
            info[p].l = 0;
        }
        else
        {
            Split(info[p].l, info[q].l, k);
        }
        pull(p);
        pull(q);
    }
    void split(int new_ver, int u, int k)
    {
        root[new_ver] = 0;
        Split(root[u], root[new_ver], k);
    }
};
```

# 主席树
## 定义

主席树全称是**可持久化权值线段树**。它的核心任务是：每插入一个数，都要保留一个节点的线段树版本。
可以实现区间第k小查询。

### 实现

- **暴力想法**：每插入一个数就新开一棵动态开点线段树。$N$ 个数就是 $N \times (N \log V)$，内存瞬间爆炸。
- **复用节点**： 当你修改一个节点时，从根到叶子只有 $\log V$ 个节点会变。**剩下的子树和前一个版本一模一样！** 我们只需要新建这 $\log V$ 个节点，让新节点的左右指针指向**前一个版本**中没变过的儿子节点即可。
 
#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    struct Node
    {
        int l;
        int r;
        int cnt;
    };
    vector<int> root;
    int tot;
    int n; // 值域
    vector<Node> info;
    SegTree(int n, int nodes, int ver) : n(n), tot(0)
    {
        info.assign(nodes, {0, 0, 0});
        root.assign(ver + 1, 0);
    }
    void pull(int p)
    {
        int l = info[p].l, r = info[p].r;
        info[p].cnt = info[l].cnt + info[r].cnt;
    }

    void modify(int &p, int pre, int l, int r, int x, int v)
    {
        p = ++tot;
        info[p] = info[pre];

        if (r - l == 1)
        {
            info[p].cnt += v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(info[p].l, info[p].l, l, mid, x, v);
        }
        else
        {
            modify(info[p].r, info[p].r, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int ver, int pre_ver, int x, int v = 1)
    {
        modify(root[ver], root[pre_ver], 0, n, x, v);
    }

    int query_cnt(int L, int R, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return 0;
        if (x <= l && r <= y)
            return info[R].cnt - info[L].cnt;
        int mid = l + r >> 1;
        return query_cnt(info[L].l, info[R].l, l, mid, x, y) + query_cnt(info[L].r, info[R].r, mid, r, x, y);
    }
    int query_cnt(int L, int R, int l, int r)
    {
        return query_cnt(root[L], root[R], 0, n, l, r);
    }
    int query_rank(int L, int R, int x)
    {
        return query_cnt(root[L], root[R], 0, n, 0, x) + 1;
    }
    int kth(int L, int R, int l, int r, int k)
    {
        if (r - l == 1)
            return l;
        int mid = l + r >> 1;

        int cntl = info[info[R].l].cnt - info[info[L].l].cnt;

        if (k <= cntl)
        {
            return kth(info[L].l, info[R].l, l, mid, k);
        }
        else
        {
            return kth(info[L].r, info[R].r, mid, r, k - cntl);
        }
    }
    int kth(int L, int R, int k)
    {
        return kth(root[L], root[R], 0, n, k);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegTree T(1e9, n * 40, n);
    for (int i = 1; i <= n; i++)
    {
        T.modify(i, i - 1, a[i]);
    }
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << T.kth(l - 1, r, k) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
```

# 二项式反演

## 定义

二项式反演本质上是一种**容斥原理**的代数形式。它主要用于解决“**恰好有 $k$ 个**”难以直接求解，但“**至多/至少有 $k$ 个**”容易求解的问题。

- **$g(k)$**：通常表示“恰好”满足 $k$ 个限制条件的方案数（直接求很难）。
- **$f(k)$**：通常表示“至少”或“从 $n$ 个中选 $k$ 个，剩下随意”的方案数（直接求容易）。

常见形式如下：
1. $f_n = \sum_{i=0}^n \binom{n}{i} g_i \iff g_n = \sum_{i=0}^n (-1)^{n-i} \binom{n}{i} f_i$
2. $f_k = \sum_{i=k}^n \binom{i}{k} g_i \iff g_k = \sum_{i=k}^n (-1)^{i-k} \binom{i}{k} f_i$ (常用：$f_k$ 表示“至少 $k$ 个”，$g_k$ 表示“恰好 $k$ 个”)

## 实现

### 代码

```cpp
#include <vector>

using i64 = long long;

template<class T>
struct Binom {
    int n;
    std::vector<T> fac, inv;
    Binom(int n) : n(n), fac(n + 1), inv(n + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
        inv[n] = fac[n].inv(); // 假设 T 是模数类 mint，需实现 inv()
        for (int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i;
    }
    T C(int n, int m) {
        if (m < 0 || m > n) return 0;
        return fac[n] * inv[m] * inv[n - m];
    }
    // 形式 2：由至少 f 数组求恰好 g 数组
    std::vector<T> solve(const std::vector<T>& f) {
        int m = f.size() - 1;
        std::vector<T> g(m + 1);
        for (int k = 0; k <= m; k++) {
            for (int i = k; i <= m; i++) {
                T res = C(i, k) * f[i];
                if ((i - k) & 1) g[k] -= res;
                else g[k] += res;
            }
        }
        return g;
    }
};
```

# 矩阵快速幂

## 结构体实现
使用 `std::vector` 动态维护矩阵，通过结构体封装重载乘法运算符，代码简洁且通用性强。

### 代码

```cpp
const int mod = 1e9 + 7;
struct Mat
{
    int n;
    vector<vector<int>> M;
    Mat(int r) : n(r), M(r, vector<int>(r)) {};
    Mat unit()
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 1;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] += M[i][k] * b.M[k][j] % mod;
                    res.M[i][j] %= mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << " \n"[j == n - 1];
            }
        }
    }
};
Mat exp(Mat a, int b)
{
    Mat ans(a.n);
    ans = ans.unit();
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
```
# 普通生成函数 (OGF) 与序列构造

## 定义

普通生成函数（Ordinary Generating Functions）主要用于解决**无标号计数**问题。将序列 $a_0, a_1, a_2, \dots$ 映射为一个形式幂级数：

$$A(x) = \sum_{n=0}^{\infty} a_n x^n$$

其中 $x^n$ 的指数代表物品的“大小”或“长度”，系数 $a_n$ 代表方案数。

**核心算子：序列构造 $SEQ(\mathcal{A})$**

若单个物品的生成函数为 $A(x)$，且满足 $[x^0]A(x)=0$（即没有大小为 0 的物品），则由该物品排成一列构成的序列生成函数为：

$$G(x) = 1 + A(x) + A^2(x) + A^3(x) + \dots = \frac{1}{1 - A(x)}$$

## 实现

在多项式工业题中，通常使用**多项式求逆**实现；在组合数学推导中，通常利用闭式进行系数提取。

### 代码 (系数提取逻辑)

```cpp
// 场景：已知每种物品的选法 A(x)，求总长度为 n 的排列方案数
// 对应公式：G(x) = 1 / (1 - A(x))
// 如果 A(x) 是简单多项式，通常使用线性递推或 Bostan-Mori 提取系数
// 如果 A(x) 项数较多，使用多项式求逆 O(N log N)
vector<int> PolyInv(vector<int> A, int n); // 标准模板
```

---

# 广义二项式定理 (Generalized Binomial Theorem)

## 定义

将二项式定理 $(1+x)^n$ 推广到 $n$ 为任意实数（负数、分数）的情况：

$$(1+x)^\alpha = \sum_{k=0}^{\infty} \binom{\alpha}{k} x^k$$

其中广义组合数的展开为：

$$\binom{\alpha}{k} = \frac{\alpha(\alpha-1)(\alpha-2)\dots(\alpha-k+1)}{k!}$$

**XCPC 最常用变形（负二项式展开）：**

对于正整数 $n$，处理分母上的 $(1-x)^n$ 时：

$$[x^k] \frac{1}{(1-x)^n} = \binom{n+k-1}{k} = \binom{n+k-1}{n-1}$$

这个公式常用于将“隔板法”问题转化为生成函数系数提取。

## 实现

通过预处理阶乘和逆元，在 $O(1)$ 或 $O(k)$ 时间内提取特定项。

### 代码 (广义组合数计算)

```cpp
// 计算广义组合数 C(alpha, k)，alpha 可以为负
int generalized_C(int alpha, int k) {
    if (k < 0) return 0;
    if (alpha >= 0 && alpha < k) return 0;
    if (alpha >= 0) return C(alpha, k); // 普通组合数

    // 若 alpha 为负数，设 n = -alpha
    // 使用公式：C(-n, k) = (-1)^k * C(n+k-1, k)
    int n = -alpha;
    int res = C(n + k - 1, k);
    if (k & 1) return (mod - res) % mod;
    return res;
}

// 提取 [x^L] (1-x)^{-n} 的系数
int extract_negative_pow(int n, int L) {
    return C(n + L - 1, n - 1);
}
```

# 线性基
## 定义

称线性空间 $V$ 的一个极大线性无关组为 $V$ 的一组 **Hamel 基** 或 **线性基**，简称 **基**。

## 实现1（贪心法）

对原集合的每个数 𝑝![](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7 "p") 转为二进制，从高位向低位扫，对于第 𝑥![](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7 "x") 位是 1![](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7 "1") 的，如果 $a_x$ 不存在，那么令 $a_x\leftarrow p$ 并结束扫描，如果存在，令$p \leftarrow p ~\text{xor}~ a_x$ ![](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7 "p\leftarrow p~\text{xor}~a_x")．

查询原集合内任意几个元素 $\text{xor}$ 的最大值，只需将线性基从高位向低位扫，若 $\text{xor}$ 上当前扫到的 $a_x$ 答案变大，就把答案异或上 $a_x$。
 
### 代码

```cpp
struct Basis
{
    long long p[64], d[64];
    int cnt = 0;
    bool can_zero;
    Basis()
    {
        memset(p, 0, sizeof(p));
        can_zero = 0;
    }
    // 插入元素
    void insert(long long x)
    {
        for (int i = 62; i >= 0; i--)
        {
            if (!(x >> i))
                continue;
            if (!p[i])
            {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
        can_zero = 1;
    }
    // 查询最大异或值
    long long query()
    {
        long long res = 0;
        for (int i = 62; i >= 0; i--)
        {
            res = max(res, res ^ p[i]);
        }
        return res;
    }
    // 合并线性基
    void merge(const Basis &b)
    {
        for (int i = 62; i >= 0; i--)
        {
            if (b.p[i])
                insert(b.p[i]);
        }
    }
    void rebuild()
    {
        cnt = 0;
        for (int i = 62; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if ((p[i] >> j) & 1)
                    p[i] ^= p[j];
            }
        }

        for (int i = 0; i <= 62; i++)
        {
            if (p[i])
                d[cnt++] = p[i];
        }
    }

    long long kth(long long k)
    {
        if (can_zero)
            k--; // 如果原集合能异或出0，第k小要减1
        if (k >= (1LL << cnt))
            return -1;
        long long res = 0;
        for (int i = 0; i < cnt; i++)
        {
            if ((k >> i) & 1)
                res ^= d[i];
        }
        return res;
    }
};
```


## 实现2（高斯消元）
 
### 代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int row = 0;
    auto gauss = [&]()
    {
        for (int i = 60; i >= 0; i--)
        {
            for (int j = row; j < n; j++)
            {
                if ((a[j] >> i) & 1)
                {
                    swap(a[j], a[row]);
                    break;
                }
            }
            if (!((a[row] >> i) & 1))
                continue;
            for (int j = 0; j < n; j++)
            {
                if (j != row && (a[j] >> i) & 1)
                    a[j] ^= a[row];
            }
            row++;
            if (row == n)
                break;
        }
    };
    gauss();
    int ans = 0;
    for (int i = 0; i < row; i++)
        ans ^= a[i];
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
```


# 强连通分量

## Tarjan 算法实现
使用 DFS 过程中产生的 `dfn` (时间戳) 和 `low` (追溯值) 来判定强连通分量。

### 复杂度
* **时间复杂度**: $O(V + E)$
* **空间复杂度**: $O(V + E)$

### 代码
```cpp
struct SCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;
    SCC() {};
    SCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        cur = cnt = 0;
    }
    void add(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int u)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto v : adj[u])
        {
            if (dfn[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (bel[v] == -1)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            do
            {
                v = stk.back();
                stk.pop_back();
                bel[v] = cnt;
            } while (v != u);
            cnt++;
        }
    }
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
                dfs(i);
        }
        return bel;
    }
    vector<vector<int>> get_DAG()
    {
        vector nadj(cnt, vector<int>{});
        for (int u = 0; u < n; u++)
        {
            for (auto v : adj[u])
            {
                if (bel[u] != bel[v])
                    nadj[bel[u]].push_back(bel[v]);
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            ranges::sort(nadj[i]);
            nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
        }
        return nadj;
    }
};
```

# 边双连通分量 (e-BCC)

## Tarjan 算法实现

通过 Tarjan 算法找桥，并第二次 DFS 染色或使用栈来提取每一个边双连通分量。

### 代码

```cpp

struct EBCC
{
    int n;
    vector<vector<array<int, 2>>> adj;
    vector<array<int, 2>> e;
    vector<int> dfn, low, bel, siz;
    vector<int> brg;
    vector<int> stk;
    int cur, cnt;
    EBCC() {};
    EBCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, -1);
        bel.assign(n, -1);
        e.clear();
        stk.clear();
        siz.clear();
        cur = cnt = 0;
    };
    void add(int u, int v)
    {
        adj[u].push_back({v, (int)e.size()});
        adj[v].push_back({u, (int)e.size()});
        e.push_back({u, v});
    }
    void dfs(int u, int fa)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto [v, pos] : adj[u])
        {
            if (pos == fa)
                continue;
            if (dfn[v] == -1)
            {
                dfs(v, pos);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    brg.push_back(pos);
            }
            else if (bel[v] == -1 && dfn[v] < dfn[u])
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            int sz = 0;
            do
            {
                v = stk.back();
                stk.pop_back();
                sz++;
                bel[v] = cnt;
            } while (v != u);
            siz.push_back(sz);
            cnt++;
        }
    }
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {
                dfs(i, -1);
            }
        }
        return bel;
    }
    vector<array<int, 2>> compress()
    {
        vector<array<int, 2>> edges;
        for (int i = 0; i < e.size(); i++)
        {
            auto [u, v] = e[i];
            if (bel[u] != bel[v])
                edges.push_back({bel[u], bel[v]});
        }
        return edges;
    }
};
```

# 点双连通分量 (V-BCC)

## 定义
在一个无向图中，若删除任意一个节点后，原图的某个子图仍然连通，则称该子图为点双连通的。每个极大点双连通子图称为点双连通分量。
**特性：**
1. 两个点双连通分量之间最多只有一个公共点（割点）。
2. 每一个 V-BCC 都可以看作是圆方树中的一个方点。

## 实现
使用 Tarjan 算法维护 `dfn` 和 `low` 数组。当满足 `low[v] >= dfn[u]` 时，说明找到了一个以 $u$ 为根的点双。

### 代码
```cpp
struct VBCC
{
    int n;
    vector<vector<int>> adj, bcc;
    vector<int> dfn, low;
    vector<int> stk;
    vector<int> cut;
    int cur;
    VBCC() {};
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, -1);
        cut.assign(n, 0);
        stk.clear();
        cur = 0;
    }
    VBCC(int n)
    {
        init(n);
    }
    void add(int u, int v)
    {
        adj[u].push_back(v), adj[v].push_back(u);
    }
    void dfs(int u, int f)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        int son = 0;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            if (dfn[v] == -1)
            {
                son++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u])
                {
                    if (f == -1 || son > 1)
                        cut[u] = 1;
                    bcc.push_back({});
                    int y;
                    do
                    {
                        y = stk.back();
                        bcc.back().push_back(y);
                        stk.pop_back();
                    } while (y != v);
                    bcc.back().push_back(u);
                }
            }
            else
                low[u] = min(dfn[v], low[u]);
        }
        if (f == -1 && son == 0)
        {
            bcc.push_back({});
            bcc.back().push_back(u);
        }
    }
    vector<vector<int>> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {
                dfs(i, -1);
            }
        }
        return bcc;
    }
    vector<vector<int>> get_tree()
    {
        vector t(n + bcc.size(), vector<int>());
        for (int i = 0; i < bcc.size(); i++)
        {
            int u = n + i;
            for (auto v : bcc[i])
            {
                t[v].push_back(u);
                t[u].push_back(v);
            }
        }
        return t;
    }
};
```

# 圆方树 (Block-Cut Tree)

## 定义
圆方树是针对无向图构建的一种特殊树结构。原图中的每个节点称为**圆点**，原图中的每个点双连通分量（BCC）对应圆方树中的一个**方点**。每个方点与其对应的点双连通分量中的所有圆点相连。

## **性质**
- 圆方树中圆点仅与方点相连，方点仅与圆点相连，形成一棵二分树。
- 原图中的一个点 $u$ 是割点，当且仅当它在圆方树中的**度数 > 1**。
- **两点间必经点**：原图中两点 $u, v$ 之间所有的**割点**，都在圆方树中 $u$ 到 $v$ 的唯一简单路径上。
- **路径集合关系**：原图中 $u$ 到 $v$ 的所有简单路径的**并集**，恰好等于圆方树中 $u, v$ 路径上所有**方点**所代表的点双连通分量的并集。

# 树直径
## 定义

**我们将树上任意两节点之间最长的简单路径即为树的「直径」。**
显然一棵树可以有多条直径。

## 性质

当树上所有边权为正时，则树的所有直径中点重合。
## 做法

我们可以用两次 $DFS$ ,或者树形$dp$ 的方法去求出树的直径。

1. 两次$DFS$ 
	引理：在一棵树上，从任意节点 $y$ 开始进行一次 DFS，到达的距离其最远的节点 $z$ 必为直径的一端。*(证明可以使用反证法)*
	首先从任意节点 $y$ 开始进行第一次 DFS，到达距离其最远的节点，记为 $z$，然后再从 $z$ 开始做第二次 DFS，到达距离 $z$ 最远的节点，记为 $z'$，则 $\delta(z,z')$ 即为树的直径。
2. 树形dp
	树形 DP 可以在存在负权边的情况下求解出树的直径。
	***方法1***：
		当我们记录1为树的根时，所能延伸的最长路径长度 $d1$ 与次长路径（与最长路径无公共边）长度 $d_1$，那么直径就是对于每一个点，该点 $d_1+d_2$ 能取到的值中的最大值。
	***方法2：***
		定义$dp[u]$为以$u$为根的子树中，从$u$出发的最长路径，那么我们可以的到转移方程：$$dp[u]=max(dp[u],dp[v]+w(u,v))$$ 其中在更新$dp[u]$之前，要先计算$d=max(d,dp[u]+dp[v]+w(u,v))$ 。
## 代码

两次dfs代码：
```cpp
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dis(n + 1);
    int l = 1;
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            dis[v] = dis[u] + 1;
            if (dis[v] > dis[l])
                l = v;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    dis.assign(n + 1, 0);
    dfs(dfs, l, 0);
    cout << dis[l] << '\n';
    return 0;
}
```

树形dp代码1：
```cpp
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> d1(n + 1), d2(n + 1);
    auto dfs=[&](auto &&self, int u, int f) -> int
    {
        d1[u] = 0, d2[u] = 0;
        int d = 0;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            d = max(d, self(self, v, u));
            int tmp = d1[v] + 1;
            if (tmp > d1[u])
                d2[u] = d1[u], d1[u] = tmp;
            else if (tmp > d2[u])
                d2[u] = tmp;
        }
        return max(d, d1[u] + d2[u]);
    };

    cout << dfs(dfs, 1, 0) << '\n';
    return 0;
}
```

树形dp代码2:
```cpp
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dp(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> int
    {
        int d = 0;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            d = max(d, self(self, v, u));
            d = max(d, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
        return d;
    };

    cout << dfs(dfs, 1, 0) << '\n';
    return 0;
}
```

# 树重心 

## 定义
在一个拥有 $n$ 个节点的树中，如果删除某个节点 $u$ 后，剩下的所有连通分量中最大的子树大小最小，则称节点 $u$ 为树的重心。
* 树的重心最多有两个。
* 删除重心后，最大子树的大小 $max\_sz \le \lfloor n/2 \rfloor$。
* 所有点到树重心距离总和最小。

## 实现（dfs）
使用一次深度优先搜索（DFS）即可求出。通过 `sz[u]` 维护子树大小，并计算删除当前节点后的最大连通块。

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n + 1), dp(n + 1);
    vector<int> ans;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = 1;
        dp[u] = 0;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            dp[u] = max(dp[u], sz[v]);
        }
        dp[u] = max(dp[u], n - sz[u]);
        if (dp[u] <= n / 2)
        {
            ans.push_back(u);
        }
    };
    dfs(dfs, 1, 0);
    cout << ans[0] << '\n';
}
```
## 实现（换根dp）

通过两次 DFS 实现：
1. **第一次 DFS**：计算以 0 为根时，每个节点的子树大小 $sz[u]$，并记录每个节点在向下方向的最大子树。
2. **第二次 DFS**：进行换根，计算每个节点向上方向（经过父亲节点）能到达的连通块大小，即 $n - sz[u]$。

### 代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 2e5;
void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n + 1), dp(n + 1), dep(n + 1, -1);
    dp[0] = 1e9;
    vector<int> ans;
    auto dfs1 = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = 1;
        dep[u] = dep[f] + 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
        dp[1] += dep[u];
    };
    dfs1(dfs1, 1, 0);
    auto dfs2 = [&](auto &&self, int u, int f) -> void
    {
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            dp[v] = dp[u] + n - 2 * sz[v];
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    cout << ranges::min_element(dp) - dp.begin() << ' ' << *ranges::min_element(dp) << '\n';
}
```

# 最近公共祖先 (LCA)

## 朴素实现 (Naive)
通过跳指针直到两点相遇。适用于单次查询或树高较小的情况。

### 代码

```cpp
struct LCA {
    int n;
    vector<int> d;
    vector<int> p;
    vector<vector<int>> adj;
    LCA(int n) : n(n), d(n + 1), p(n + 1), adj(n + 1) {}
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int fa) {
        d[u] = d[fa] + 1;
        p[u] = fa;
        for (int v : adj[u]) {
            if (v != fa) dfs(v, u);
        }
    }
    int query(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        while (d[u] > d[v]) u = p[u];
        while (u != v) u = p[u], v = p[v];
        return u;
    }
};
```
### 例题链接

[LuoGu P3379](https://www.luogu.com.cn/problem/P3379) (仅作逻辑验证，大数据量下会超时)

---

## 倍增实现 (Binary Lifting)

利用 $2^k$ 跳跃优化查找过程，预处理 $O(n \log n)$，单次查询 $O(\log n)$。

## 代码

C++

```cpp
struct LCA {
    int n, l;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<int>> adj;

    LCA(int n) : n(n), l(__lg(n) + 1), d(n + 1), f(n + 1, vector<int>(l, 0)), adj(n + 1) {}

    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int rt = 1) {
        dfs(rt, 0);
    }

    void dfs(int u, int fa) {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < l; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != fa) dfs(v, u);
        }
    }

    int query(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        for (int i = l - 1; i >= 0; i--) {
            if (d[f[u][i]] >= d[v]) u = f[u][i];
        }
        if (u == v) return u;
        for (int i = l - 1; i >= 0; i--) {
            if (f[u][i] != f[v][i]) {
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[query(u, v)];
    }
};
```

## 例题链接

[LuoGu P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379)
# 重链剖分 (Heavy-Light Decomposition)

## 实现

通过两次 DFS 预处理出重儿子、深度、父节点、子树大小以及链顶节点。结合线段树可维护路径及子树信息。

### 代码

```cpp
struct HLD
{
    int n, root;
    vector<int> top, son, siz, dep, dfn, rnk, fa;
    vector<vector<int>> g;
    int cur;
    HLD(int n, int root) : n(n), root(root)
    {
        init();
    }
    void init()
    {
        g.assign(n, {});
        top.assign(n, 0);
        fa.assign(n, 0);
        son.assign(n, -1);
        rnk.assign(n, 0);
        dep.assign(n, 0);
        dfn.assign(n, 0);
        siz.assign(n, 0);
        dep[root] = 0;
        cur = 0;
    }
    void add(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs1(int u, int f)
    {
        fa[u] = f, dep[u] = (f == -1 ? -1 : dep[f]) + 1, siz[u] = 1;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
    void dfs2(int u, int ftop)
    {
        dfn[u] = cur, rnk[cur] = u, top[u] = ftop;
        cur++;
        if (son[u] != -1)
            dfs2(son[u], ftop);
        for (auto v : g[u])
        {
            if (v == son[u] || v == fa[u])
                continue;
            dfs2(v, v);
        }
    }
    void work()
    {
        dfs1(root, -1);
        dfs2(root, root);
    }
    int lca(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] > dep[top[v]])
                u = fa[top[u]];
            else
                v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    }
    vector<array<int, 2>> path(int u, int v, bool edge = 0)
    {
        vector<array<int, 2>> res;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            res.push_back({dfn[top[u]], dfn[u]});
            u = fa[top[u]];
        }
        if (u == v && edge)
            return res;
        if (dep[u] > dep[v])
            swap(u, v);
        res.push_back({dfn[u] + (edge ? 1 : 0), dfn[v]});
        return res;
    }
    array<int, 2> subtree(int u, bool edge = 0) const
    {
        return {dfn[u] + (edge ? 1 : 0), dfn[u] + siz[u] - 1};
    }
};
```


# 树上启发式合并 (DSU on Tree)

## 定义
用于处理不带修改的树上子树询问。通过优先遍历轻儿子并清除其贡献，最后遍历重儿子并保留其贡献，利用重链剖分的性质将复杂度优化至 $O(n \log n)$。

## 实现
使用结构体封装，通过 `dfs1` 预处理重儿子 `hson`，`dfs2` 进行启发式合并。

### 代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector adj(n + 1, vector<int>());
    int root = -1;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (root == -1)
            root = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> son(n + 1), sz(n + 1);
    auto get_son = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    };
    get_son(get_son, root, 0);
    int flag = 0, sum = 0, ma = 0;
    vector<int> cnt(n + 1), ans(n + 1);
    auto update = [&](int u, int val)
    {
        cnt[c[u]] += val;
        if (cnt[c[u]] > ma)
        {
            ma = cnt[c[u]];
            sum = c[u];
        }
        else if (cnt[c[u]] == ma)
            sum += c[u];
    };
    auto init = [&]()
    { sum = 0, ma = 0; };
    auto count = [&](auto &&self, int u, int f, int val) -> void
    {
        update(u, val);
        for (auto v : adj[u])
        {
            if (v == f || v == flag)
                continue;
            self(self, v, u, val);
        }
    };
    auto dfs = [&](auto &&self, int u, int f, bool keep) -> void
    {
        for (auto v : adj[u])
        {
            if (v == son[u] || v == f)
                continue;
            self(self, v, u, 0);
        }
        if (son[u])
        {
            self(self, son[u], u, 1);
            flag = son[u];
        }
        count(count, u, f, 1);
        flag = 0;
        ans[u] = sum;
        if (!keep)
        {
            count(count, u, f, -1);
            init();
        }
    };
    dfs(dfs, root, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```


# 点分治 (Centroid Decomposition)

## 实现
通过递归寻找树的重心，将原问题分解为经过重心的路径问题和子树内的递归问题。

### 代码
```cpp
struct CentroidDecomp {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> sz, vis;
    
    CentroidDecomp(int n_) : n(n_), adj(n_ + 1), sz(n_ + 1), vis(n_ + 1) {}

    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void get_sz(int u, int p) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !vis[v]) {
                get_sz(v, u);
                sz[u] += sz[v];
            }
        }
    }

    int get_ct(int u, int p, int tot) {
        for (int v : adj[u]) {
            if (v != p && !vis[v] && sz[v] > tot / 2) {
                return get_ct(v, u, tot);
            }
        }
        return u;
    }

    void calc(int u) {
        // 在此处处理经过重心 u 的贡献
    }

    void solve(int u) {
        get_sz(u, 0);
        int ct = get_ct(u, 0, sz[u]);
        vis[ct] = 1;
        calc(ct); // 处理当前连通块
        for (int v : adj[ct]) {
            if (!vis[v]) solve(v);
        }
    }
};
```

#### 
std
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> siz(n + 1), vis(n + 1), has(inf + 1);
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> q(m);
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
        cin >> q[i];
    auto get_siz = [&](auto &&self, int u, int f) -> void
    {
        siz[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (v == f || vis[v])
                continue;
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    auto get_ct = [&](auto &&self, int u, int f, int tot) -> int
    {
        for (auto [v, w] : adj[u])
        {
            if (v == f || vis[v])
                continue;
            if (siz[v] > tot / 2)
                return self(self, v, u, tot);
        }
        return u;
    };
    auto get_dis = [&](auto &&self, int u, int f, int dis, vector<int> &cur) -> void
    {
        if (dis > inf)
            return;
        cur.push_back(dis);
        for (auto [v, w] : adj[u])
        {
            if (v == f || vis[v])
                continue;
            self(self, v, u, dis + w, cur);
        }
    };
    auto calc = [&](int u) -> void
    {
        vector<int> dis;
        dis.push_back(0);
        has[0] |= 1;
        for (auto [v, w] : adj[u])
        {
            if (vis[v])
                continue;
            vector<int> cur;
            get_dis(get_dis, v, u, w, cur);
            for (auto d : cur)
            {
                for (int i = 0; i < m; i++)
                {
                    if (q[i] >= d && has[q[i] - d])
                    {
                        ans[i] = 1;
                    }
                }
            }
            for (auto d : cur)
            {
                if (d < inf && !has[d])
                    has[d] = 1, dis.push_back(d);
            }
        }
        for (auto d : dis)
            has[d] = 0;
    };
    auto work = [&](auto &&self, int u) -> void
    {
        get_siz(get_siz, u, 0);
        int ct = get_ct(get_ct, u, 0, siz[u]);
        vis[ct] = 1;
        calc(ct);
        for (auto [v, w] : adj[ct])
        {
            if (vis[v])
                continue;
            self(self, v);
        }
    };
    for (int i = 0; i < m; i++)
    {
        if (q[i] == 0)
            ans[i] = 1;
    }
    work(work, 1);
    for (int i = 0; i < m; i++)
    {
        cout << (ans[i] ? "AYE" : "NAY") << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```

# Dinic 算法

Dinic 算法用于求解网络流中的**最大流问题**。它通过在分层图（Level Graph）上多次寻找增广路来优化效率，引入了**当前弧优化**和**多路增广**。

**时间复杂度**：一般图为 $O(V^2 E)$，在二分图中为 $O(E\sqrt{V})$。

## 实现

基于分层图优化的 Dinic 算法。

### 代码

```cpp
struct Flow
{
    struct _edge
    {
        int to;
        int cap;
        _edge(int to, int cap) : to(to), cap(cap) {};
    };
    const int inf = 1e18;
    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    Flow() {};
    Flow(int n) : n(n)
    {
        init(n);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        cur.assign(n, 0);
        h.assign(n, -1);
    }
    void add(int u, int v, int c)
    {
        g[u].push_back(e.size());
        e.push_back({v, c});
        g[v].push_back(e.size());
        e.push_back({u, 0});
    }
    bool bfs(int s, int t)
    {
        h.assign(n, -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto p : g[u])
            {
                auto [v, c] = e[p];
                if (c > 0 && h[v] == -1)
                {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    int dfs(int u, int t, int f)
    {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < g[u].size(); i++)
        {
            int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1)
            {
                int nf = dfs(v, t, min(r, c));
                e[j].cap -= nf;
                e[j ^ 1].cap += nf;
                r -= nf;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    int flow(int s, int t)
    {
        int ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
    vector<bool> minCut()
    {
        vector<bool> c(n);
        for (int i = 0; i < n; i++)
        {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    struct Edge
    {
        int from;
        int to;
        int cap;
        int flow;
    };
    vector<Edge> edges()
    {
        vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2)
        {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```

# Hall 定理 (Hall's Marriage Theorem)

## 定义

**Hall 定理**是二分图包含**完备匹配**的充分必要条件。

设二分图 $G = (V_1 \cup V_2, E)$，其中 $|V_1| \leq |V_2|$。

对于 $V_1$ 的任意子集 $S \subseteq V_1$，设 $N(S)$ 为 $S$ 中所有顶点的邻居集合。

图 $G$ 存在一个匹配覆盖 $V_1$ 中所有顶点的充分必要条件是：

$$\forall S \subseteq V_1, |N(S)| \geq |S|$$

### 推广（Hall 定理的推论）

二分图的最大匹配数为：

$$|V_1| - \max_{S \subseteq V_1} (|S| - |N(S)|)$$

其中 $\max(|S| - |N(S)|)$ 通常被称为二分图的 **缺额 (Deficiency)**。

## 实现

### 复杂度

- **理论判定**：通常涉及指数级数量的子集考察，复杂度为 $O(2^{|V_1|})$。
    
- **实际建模**：在题目中常转化为**网络流**（$O(E\sqrt{V})$）或通过**数据结构**（如线段树）维护序列上的区间 Hall 定理条件，复杂度通常为 $O(n \log n)$ 或 $O(n)$。

# 费用流 (MCMF)

## 定义
在网络流图中，每条边除了容量 $c(u, v)$ 外，还有单位流量的费用 $w(u, v)$。费用流算法旨在寻找从源点 $S$ 到汇点 $T$ 的最大流量中，总费用最小的流。

## 实现 (SPFA 增广路)
采用 SPFA 算法寻找最短路（单位费用为权值），通过 `pre` 数组记录路径进行增广。适用于含负权边但不含负权圈的图。

### 复杂度
$O(F \cdot E \log V)$ 或 $O(F \cdot VE)$，其中 $F$ 是最大流量，$E$ 是边数，$V$ 是点数。

### 代码
```cpp
struct MinCostFlow
{
    const int inf = 1e18;
    struct _edge
    {
        int to;
        int cap;
        int cost;
        _edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {};
    };
    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> dis, h;
    vector<int> pre;
    MinCostFlow(int n) : n(n)
    {
        init(n);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
    }
    void add(int u, int v, int w, int c)
    {
        g[u].push_back(e.size());
        e.pb({v, w, c});
        g[v].push_back(e.size());
        e.pb({u, 0, -c});
    }
    bool dij(int s, int t)
    {
        dis.assign(n, inf);
        pre.assign(n, -1);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        dis[s] = 0;
        pq.push({0, s});
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] != d)
                continue;
            for (auto idx : g[u])
            {
                auto [v, cap, w] = e[idx];
                if (cap > 0 && dis[v] > d + h[u] - h[v] + w)
                {
                    dis[v] = d + h[u] - h[v] + w;
                    pre[v] = idx;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis[t] != inf;
    }
    array<int, 2> flow(int s, int t)
    {
        int f = 0;
        int cost = 0;
        h.assign(n, 0);
        while (dij(s, t))
        {
            for (int i = 0; i < n; i++)
            {
                h[i] += dis[i];
            }
            int nf = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                nf = min(nf, e[pre[i]].cap);
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                e[pre[i]].cap -= nf, e[pre[i] ^ 1].cap += nf;
            f += nf;
            cost += nf * h[t];
        }
        return array<int, 2>({f, cost});
    }
};
```

```cpp
struct MinCostFlow
{
    const int inf = 1e18;
    struct _edge
    {
        int to;
        int cap;
        int cost;
        _edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {};
    };
    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> dis, h;
    vector<int> pre;
    MinCostFlow(int n) : n(n)
    {
        init(n);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
    }
    void add(int u, int v, int w, int c)
    {
        g[u].push_back(e.size());
        e.pb({v, w, c});
        g[v].push_back(e.size());
        e.pb({u, 0, -c});
    }
    bool dij(int s, int t)
    {
        dis.assign(n, inf);
        pre.assign(n, -1);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        dis[s] = 0;
        pq.push({0, s});
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] != d)
                continue;
            for (auto idx : g[u])
            {
                auto [v, cap, w] = e[idx];
                if (cap > 0 && dis[v] > d + h[u] - h[v] + w)
                {
                    dis[v] = d + h[u] - h[v] + w;
                    pre[v] = idx;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis[t] != inf;
    }
    void spfa(int s)
    {
        h.assign(n, inf);
        vector<bool> vis(n, false);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        vis[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (auto idx : g[u])
            {
                auto [v, cap, w] = e[idx];
                if (cap > 0 && h[v] > h[u] + w)
                {
                    h[v] = h[u] + w;
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    array<int, 2> flow(int s, int t)
    {
        int f = 0;
        int cost = 0;
        h.assign(n, 0);
        spfa(s);
        while (dij(s, t))
        {
            for (int i = 0; i < n; i++)
            {
                h[i] += dis[i];
            }
            int nf = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                nf = min(nf, e[pre[i]].cap);
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                e[pre[i]].cap -= nf, e[pre[i] ^ 1].cap += nf;
            f += nf;
            cost += nf * h[t];
        }
        return array<int, 2>({f, cost});
    }
};
```


# Dijkstra 算法

## 功能

- Dijkstra 算法是一种求解 **非负权图** 上单源最短路径的算法。
- 朴素Dijkstra 算法的时间复杂度为$O(N^2)$ ,堆优化Dijkstra 算法的时间复杂度为$O(NlogN)$ 

## 实现

将结点分成两个集合：已确定最短路长度的点集（记为 $S$ 集合）的和未确定最短路长度的点集（记为 $T$ 集合）。一开始所有的点都属于 $T$ 集合。

初始化$dis[s]=0$ ,其他点的 $dis$ 均为 $+\infty$ 

然后重复一下操作：
1. 从$T$ 集合中选取一个最短路长度最小的点，移到集合$S$ 中。
2. 在对刚刚被加入$S$ 集合的结点的所有出边执行松弛操作。
直到 $T$ 集合为空，算法结束。

在稀疏图中，$m=O(n)$ ,堆优化般的Dij具有较大优势；而在稠密图中 $m=O(n^2)$则使用朴素方法更优 
## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
vector<PII> g[maxn];
int d[maxn];
bool st[maxn];
int dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> h;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    h.push({0,1});
    while (h.size())
    {
        auto [dpos, pos] = h.top();
        h.pop();
        if (st[pos])
            continue;
        st[pos] = 1;
        for (auto [son, dson] : g[pos])
        {
            if (d[son] > dpos + dson)
            {
                d[son] = dpos + dson;
                h.push({d[son], son});
            }
        }
    }
    if (d[n] == INF)
        return -1;
    else
        return d[n];
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    cout << dijkstra() << endl;
    return 0;
}
```

# Johnson 全源最短路径算法

## 定义
Johnson 算法用于求解带负权边（但无负环）的有向图全源最短路径。它通过给每个节点赋予一个势能值 $h(u)$，将原边权 $w(u, v)$ 重塑为非负边权 $\hat{w}(u, v) = w(u, v) + h(u) - h(v)$，从而允许对每个源点调用 Dijkstra 算法。

### 实现 (Structure-based)

#### 代码
```cpp
struct johnson
{
    const int inf = 1e9;
    struct _edge
    {
        int to;
        int val;
        _edge(int to, int val) : to(to), val(val) {};
    };
    int n;
    vector<_edge> e;
    vector<vector<int>> g, D;
    vector<int> h;
    johnson(int n) : n(n)
    {
        init(n + 1);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        D.assign(n, vector<int>(n, inf));
    }
    void add(int u, int v, int w)
    {
        g[u].pb(e.size());
        e.pb({v, w});
    }
    int spfa()
    {
        for (int i = 1; i <= n; i++)
        {
            add(0, i, 0);
        }
        queue<int> q;
        h.assign(n + 1, inf);
        vector<int> vis(n + 1);
        vector<int> cnt(n + 1);
        h[0] = 0;
        vis[0] = 1;
        q.push(0);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            for (int idx : g[u])
            {
                auto [v, w] = e[idx];
                if (h[v] > h[u] + w)
                {
                    h[v] = h[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] > n)
                        return 0;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
        return 1;
    }
    void dij(int s)
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        vector<int> dis(n + 1, inf);
        dis[s] = 0;
        pq.push({0, s});
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] != d)
                continue;
            for (auto idx : g[u])
            {
                auto [v, w] = e[idx];
                if (dis[v] > d + h[u] - h[v] + w)
                {
                    dis[v] = d + h[u] - h[v] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > inf / 2)
                D[s][i] = inf;
            else
                D[s][i] = dis[i] - h[s] + h[i];
        }
    }
    bool work()
    {
        if (!spfa())
            return 0;
        for (int i = 1; i <= n; i++)
        {
            dij(i);
        }
        return 1;
    }
    int query(int s, int t)
    {
        return D[s][t];
    }
};
```

# SPFA
## 功能

- 同样的SPFA算法也可以判断负环，只需记录最短路经过了多少条边，当经过了至少 $n$ 条边时,说明存在一个负环。
- 大多时候SPFA算法跑得很快，但其最坏情况的时间复杂度可以到达 $O(nm)$ ，==在没有负权边的时候最好还是使用 [[Dijkstra 算法]]==  。

## 实现

[[Bellman–Ford 算法]]中很多时候我们并不需要很多松弛操作，很显然，只有上一次被松弛的结点，所连接的边，才有可能引起下一次的松弛操作。因此我们可以用队列维护那些点可能*会引起松弛操作* 就可以只访问必要的边了。
 
## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
vector<PII> g[maxn];
int d[maxn];
bool st[maxn];
int spfa()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    st[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (auto [son, dson] : g[t])
        {
            if (d[son] > d[t] + dson)
            {
                d[son] = d[t] + dson;
                if (!st[son])
                {
                    q.push(son);
                }
            }
        }
    }
    return d[n];
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    int t = spfa();
    if (t >INF/2)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}
```


# 最小生成树

## 定义



**最小生成树 (Minimum Spanning Tree, MST)**：
在一个连通的加权无向图中，找到一个边的子集，使得这些边构成的树包含图中的所有顶点，并且这些边的权值之和尽可能小。如果图不连通，则不存在最小生成树（此时可求最小生成森林）。

## 实现
 
求最小生成树主要有两种经典算法：

* **Prim 算法 (普里姆算法)**：基于顶点贪心。每次选择距离当前生成树集合最近且未被访问的节点加入集合。配合优先队列（堆优化）的时间复杂度为 $O(M \log N)$，更适合**稠密图**。
* **Kruskal 算法 (克鲁斯卡尔算法)**：基于边贪心。将所有边按权值从小到大排序后遍历，利用**并查集**判断加入该边是否会形成环。时间复杂度为 $O(M \log M)$，更适合**稀疏图**。

## 代码

### 方式一：Prim 算法 (优先队列优化)

```cpp
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vector<int> vis(n + 1), dis(n + 1, inf);
    int ans = 0, cnt = 0;
    dis[1] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 1});
    while (pq.size())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        cnt++;
        ans += d;
        for (auto [v, w] : g[u])
        {
            if (dis[v] > w)
            {
                dis[v] = w;
                pq.push({w, v});
            }
        }
    }
    if (cnt != n)
        cout << "orz\n";
    else
        cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```

### 方式二：Kruskal 算法

```cpp
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct DSU {
	vector<int> f,siz;
	
	DSU() {}
	DSU(int n) {init(n);}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (x == y) return 0;
		siz[x] += siz[y];
		f[y]=x;
		return 1;
	}
	
	int esize(int x) {
		return siz[find(x)];
	}
	
	int count() {
		unordered_set<int> roots;
		for(int i=0;i<f.size();i++) roots.insert(find(i));
		return roots.size();
	}
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int,3>>e(m);
    for(auto &[w,u,v]:e)
        cin>>u>>v>>w;
    ranges::sort(e);
    DSU dsu(n+1);
    int ans = 0, cnt = 0;
    for(auto [w,u,v]:e){
        if(dsu.merge(u,v)){
            ans+=w,cnt++;
        }
    }
    if (cnt != n - 1)
        cout << "orz\n";
    else
        cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```

# Kruskal 重构树

## 定义
在 Kruskal 算法合并 $u, v$ 所在的连通块时，不直接连边，而是新建一个节点 $node$，令 $node$ 的权值为该边的边权，并让 $u, v$ 所在树的根节点成为 $node$ 的左右儿子。最终形成一棵拥有 $2n-1$ 个节点的二叉树（原图连通情况下）。

**性质：**
1. 是一棵大根堆（如果是最小生成树重构）。
2. 原图中 $u, v$ 路径上最大边权的最小值，等于重构树中 $LCA(u, v)$ 的点权。
3. 叶子节点均为原图节点，非叶子节点均为原图的边。

### 实现
采用 `struct` 封装，包含并查集初始化与重构树构建过程。

### 代码

```cpp
struct DSU
{
    vector<int> dsu;
    DSU(int n)
    {
        dsu.assign(n, 0);
        iota(dsu.begin(), dsu.end(), 0);
    }
    int find(int x)
    {
        return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
    }
};
struct KruTree
{
    int n, cur;
    vector<array<int, 3>> e;
    vector<vector<int>> g;
    vector<int> val;
    vector<vector<int>> fa;
    vector<int> dep;
    DSU dsu;
    KruTree(int n) : n(n), cur(n), e(), g(2 * n + 1, vector<int>{}), val(2 * n + 1), fa(2 * n + 1, vector<int>(31)), dep(2 * n + 1), dsu(2 * n + 1) { dep[0] = -1; };
    void add(int u, int v, int w)
    {
        e.pb({w, u, v});
    }
    void work()
    {
        sort(e.begin(), e.end());
        for (auto [w, u, v] : e)
        {
            int fu = dsu.find(u), fv = dsu.find(v);
            if (fu == fv)
                continue;
            cur++;
            dsu.dsu[fu] = dsu.dsu[fv] = cur;
            val[cur] = w;
            g[cur].pb(fu);
            g[cur].pb(fv);
        }
        for (int i = 1; i <= cur; i++)
        {
            if (dsu.find(i) == i)
                DFS(i, 0);
        }
    }
    void DFS(int u, int f)
    {
        dep[u] = dep[f] + 1;
        fa[u][0] = f;
        for (int i = 1; i <= 30; i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            DFS(v, u);
        }
    }
    int lca(int u, int v)
    {
        if (dsu.find(u) != dsu.find(v))
            return -1;
        if (dep[u] > dep[v])
            swap(u, v);
        int d = dep[v] - dep[u];
        for (int i = 0; i <= 30; i++)
        {
            if (d >> i & 1)
                v = fa[v][i];
        }
        if (u == v)
            return val[u];
        for (int i = 30; i >= 0; i--)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return val[fa[u][0]];
    }
};
```

# 扫描线 (Scanning Line)
## 矩形面积并
通过垂直于 $x$ 轴的直线自左向右扫描，将并集图形划分为若干矩形。利用线段树维护纵坐标方向上的覆盖长度。

### 代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Info
{
    int cnt, len;
    int size;
    Info() : cnt(0), len(0) {};
};
struct SegTree
{
    int n;
    vector<Info> info;
    vector<int> vy;
    SegTree(vector<int> vy) : n(vy.size()), info(4 * vy.size()), vy(vy) {};
    void pull(int p, int l, int r)
    {
        if (info[p].cnt)
            info[p].len = vy[r] - vy[l];
        else
        {
            if (r - l == 1)
                info[p].len = 0;
            else
                info[p].len = info[p << 1 | 1].len + info[p << 1].len;
        }
    }
    void modify(int p, int l, int r, int x, int y, int v)
    {
        if (vy[l] >= y || vy[r] <= x)
            return;
        if (vy[l] >= x && vy[r] <= y)
        {
            info[p].cnt += v;
            pull(p, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        modify(p << 1, l, mid, x, y, v);
        modify(p << 1 | 1, mid, r, x, y, v);
        pull(p, l, r);
    }
    void modify(int x, int y, int v)
    {
        modify(1, 0, n - 1, x, y, v);
    }
    int get_len()
    {
        return info[1].len;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 4>> a;
    vector<int> vy;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1, y1, y2, 1});
        a.push_back({x2, y1, y2, -1});
        vy.push_back(y1), vy.push_back(y2);
    }
    ranges::sort(vy);
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    ranges::sort(a, [&](const array<int, 4> &a, const array<int, 4> &b)
                 { return a[0] < b[0]; });
    SegTree T(vy);
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        auto [x, yl, yr, v] = a[i];
        int nxtx = a[i + 1][0];
        T.modify(yl, yr, v);
        ans += T.get_len() * (nxtx - x);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```


# 异或哈希 (Xor Hashing)

用于判断集合是否相同或处理子段出现次数偶数次等问题。通过给每个权值分配随机 64 位整数，将集合比较转化为异或和比较。

## 基础实现

使用 `std::mt19937_64` 生成随机权值，并用结构体封装哈希逻辑。

### 代码

```cpp
using u64 = unsigned long long;

// 使用高精度时钟作为随机数种子，防止被针对性的测试数据 hack
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// 获取一个随机的 64 位整数
u64 get_random() {
    return rng();
}
```

# 指数哈希

利用多项式哈希将字符串映射为数值。给定字符串 $S$，其哈希值计算公式为：
$$H(S) = \sum_{i=0}^{n-1} S[i] \cdot P^{n-1-i} \pmod M$$
通过预处理前缀哈希值和 $P$ 的幂次，可以在 $O(1)$ 时间内获取任意子串的哈希值。

## 实现 

为了极致的安全性，通常使用两个大质数作为模数（如 $10^9+7$ 和 $10^9+9$）以及随机的底数 $P$。

### 代码

```cpp
using u64 = unsigned long long;
using u128 = __uint128_t;

namespace Hash {
    const u64 MOD = (1ULL << 61) - 1;
    // 使用高精度时钟生成随机底数，并保证是奇数 (| 1)
    const u64 B = chrono::steady_clock::now().time_since_epoch().count() | 1;

    // 安全乘法
    inline u64 mul(u64 a, u64 b) {
        return (u64)((u128)a * b % MOD);
    }

    // 安全加法 (替代 C++ 原生的 +)
    inline u64 add(u64 a, u64 b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    // 安全减法 (替代 C++ 原生的 -，计算相反数用 sub(0, x))
    inline u64 sub(u64 a, u64 b) {
        if (a < b) a += MOD;
        a -= b;
        return a;
    }

    // 快速幂
    inline u64 power(u64 a, u64 b) {
        u64 res = 1;
        while (b) {
            if (b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    // 求数值 x 的哈希值 B^x % MOD
    inline u64 get(u64 x) {
        return power(B, x);
    }
}
```

**1. 求单点哈希值：**

```cpp
u64 h = ExpHash::get(x);
```

**2. 求哈希的相反数（完美解决你之前遇到的死循环和 $2^{64}$ 溢出）：**
```cpp
u64 neg_h = ExpHash::sub(0, ExpHash::get(x)); 
```

# 字符串哈希 (String Hash)

## 定义
将一个字符串映射为一个整数，用于快速比较字符串是否相等。通过预处理前缀哈希值，可以在 $O(1)$ 时间内获取任意子串的哈希值。

**时间复杂度**: 
- 预处理：$O(n)$
- 查询子串：$O(1)$

## 实现 (单模数自然溢出/大模数)

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

const u64 base = chrono::steady_clock::now().time_since_epoch().count() | 1;
struct Hash {
    int n;
    vector<u64> h, p;

    Hash(string s) : n(s.size()), h(n + 1), p(n + 1) {
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] * bs;
            h[i + 1] = h[i] * bs + s[i];
        }
    }

    u64 get(int l, int r) { // [l, r) 左闭右开
        return h[r] - h[l] * p[r - l];
    }
};
```

```cpp
#include <bits/stdc++.h>

using u64 = unsigned long long;
using u128 = __uint128_t;

constexpr u64 MOD = (1ULL << 61) - 1;

u64 base = std::chrono::steady_clock::now().time_since_epoch().count() % (MOD / 2) + MOD / 4 | 1;

struct Hash {
    std::vector<u64> h, p;
    Hash(const std::string &s) {
        int n = s.size();
        h.resize(n + 1);
        p.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = ((u128)h[i] * base + s[i]) % MOD;
            p[i + 1] = (u128)p[i] * base % MOD;
        }
    }
    // 查询 [l, r) 的哈希值，下标从 0 开始
    u64 get(int l, int r) {
        u64 res = h[r] + MOD - (u128)h[l] * p[r - l] % MOD;
        return res >= MOD ? res - MOD : res;
    }
};
```
双哈希
```cpp
#include <bits/stdc++.h>

using i64 = long long;

struct Hash {
    static constexpr int M1 = 1E9 + 7, M2 = 1E9 + 9;
    static int B1, B2;
    std::vector<int> h1, p1, h2, p2;

    Hash(const std::string &s) {
        int n = s.size();
        h1.resize(n + 1); p1.resize(n + 1);
        h2.resize(n + 1); p2.resize(n + 1);
        h1[0] = h2[0] = 0;
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (1LL * h1[i] * B1 + s[i]) % M1;
            p1[i + 1] = 1LL * p1[i] * B1 % M1;
            h2[i + 1] = (1LL * h2[i] * B2 + s[i]) % M2;
            p2[i + 1] = 1LL * p2[i] * B2 % M2;
        }
    }

    // 返回 [l, r) 的双哈希值
    std::array<int, 2> get(int l, int r) {
        int res1 = (h1[r] - 1LL * h1[l] * p1[r - l] % M1 + M1) % M1;
        int res2 = (h2[r] - 1LL * h2[l] * p2[r - l] % M2 + M2) % M2;
        return {res1, res2};
    }
};

// 随机化底数初始化
int Hash::B1 = std::chrono::steady_clock::now().time_since_epoch().count() % 1000 + 131;
int Hash::B2 = std::chrono::steady_clock::now().time_since_epoch().count() % 1000 + 13331;
```

# Trie树
## 定义
Trie 树，又称字典树、单词查找树或前缀树，是一种用于快速检索的多叉树结构。 它的核心思想是**利用字符串的公共前缀来降低查询时间的开销**以达到提高效率的目的（空间换时间）。
**时间复杂度**：插入、查询和删除操作的时间复杂度均为 $O(|S|)$，其中 $|S|$ 为目标字符串的长度，与树中存储的字符串总数无关。
## 实现
采用 `vector` 动态开点的方式模拟指针，避免了内存泄漏和繁琐的指针操作，非常适合算法竞赛和日常刷题。 * `nxt`：二维数组（或由 `vector<array>` 嵌套构成），`nxt[p][x]` 表示节点 `p` 沿着字符 `x` 走到的下一个节点的编号。 * `cnt`：记录以当前节点为**结尾**的单词数量。 * `pass`：记录**经过**当前节点的单词数量（用于统计前缀数量、动态删除和查询字典序第 K 小）。
### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Trie{
    vector<array<int,26>>nxt;
    vector<int> cnt,pass;
    Trie(){
        init();
    };
    void init(){
        nxt.assign(1,{});
        cnt.assign(1, 0);
        pass.assign(1,0);
    }
    void insert(const string s){
        int p=0;
        for(auto c:s){
            int x=c-'a';
            if(nxt[p][x]==0){
                nxt[p][x] = nxt.size();
                nxt.emplace_back();
                cnt.emplace_back(0);
                pass.emplace_back(0);
            }
            pass[p]++;
            p = nxt[p][x];
        }
        cnt[p]++;
        pass[p]++;
    }
    int query(const string s){
        int p=0;
        for(auto c:s){
            int x=c-'a';
            if(nxt[p][x]==0)
                return 0;
            p = nxt[p][x];
        }
        return cnt[p];
    }
    int query_pre(const string s){
        int p=0;
        for(auto c:s){
            int x=c-'a';
            if(nxt[p][x]==0)return 0;
            p=nxt[p][x];
        }
        return pass[p];
    }
    bool erase(const string s){
        if(query(s)==0)return 0;
        int p=0;
        pass[p]--;
        for(auto c:s){
            int x=c-'a';
            p=nxt[p][x];
            pass[p]--;
        }
        cnt[p]--;
        return 1;
    }
    string kth(int k) {
        if (k > pass[0]) return ""; 
        int p = 0;
        string res = "";
        while (k > 0) {
            if (cnt[p] >= k) return res;
            k -= cnt[p];
            for (int i = 0; i < 26; ++i) {
                if (nxt[p][i]) {
                    if (k <= pass[nxt[p][i]]) {
                        res += (char)('a' + i);
                        p = nxt[p][i];
                        break;
                    } else {
                        k -= pass[nxt[p][i]];
                    }
                }
            }
        }
        return res;
    }
};


```

# 01-Trie

01-Trie 是一种特殊的字典树，用于维护异或和、位运算相关问题。通常处理整数的二进制位（如从高位到低位 $2^{30} \to 2^0$）。

## 基础实现

适用于处理固定位数的整数（如 $2^{30}$ 范围），支持插入、删除和查询最大异或值。

### 代码

```cpp
struct Trie01 {
    vector<array<int, 2>> nxt;
    vector<int> cnt, pass;
    int L; // 最大位数

    Trie01(int max_bit = 30) : L(max_bit) {
        init();
    };

    void init() {
        nxt.assign(1, {-1, -1}); // 使用-1表示空节点
        cnt.assign(1, 0);
        pass.assign(1, 0);
    }

    void insert(int val) {
        int p = 0;
        for (int i = L; i >= 0; --i) {
            int x = (val >> i) & 1;
            if (nxt[p][x] == -1) {
                nxt[p][x] = nxt.size();
                nxt.push_back({-1, -1});
                cnt.push_back(0);
                pass.push_back(0);
            }
            pass[p]++;
            p = nxt[p][x];
        }
        cnt[p]++;
        pass[p]++;
    }

    bool erase(int val) {
        if (query_count(val) == 0) return false;
        int p = 0;
        pass[p]--;
        for (int i = L; i >= 0; --i) {
            int x = (val >> i) & 1;
            p = nxt[p][x];
            pass[p]--;
        }
        cnt[p]--;
        return true;
    }

    int query_count(int val) {
        int p = 0;
        for (int i = L; i >= 0; --i) {
            int x = (val >> i) & 1;
            if (nxt[p][x] == -1) return 0;
            p = nxt[p][x];
        }
        return cnt[p];
    }

    // 查询与 val 异或能得到的最大值
    int query_max_xor(int val) {
        if (pass[0] == 0) return 0;
        int p = 0, res = 0;
        for (int i = L; i >= 0; --i) {
            int x = (val >> i) & 1;
            // 尽量走相反的路来保证该位异或为1
            if (nxt[p][x ^ 1] != -1 && pass[nxt[p][x ^ 1]] > 0) {
                res |= (1 << i);
                p = nxt[p][x ^ 1];
            } else {
                p = nxt[p][x];
            }
        }
        return res;
    }

    // 类似原模板的kth，求排名第k小的数值（字典序/数值大小）
    int kth(int k) {
        if (k > pass[0]) return -1; 
        int p = 0, res = 0;
        for (int i = L; i >= 0; --i) {
            // 在这一层，如果节点有停止计数(cnt)，逻辑会略有不同
            // 01Trie通常只在叶子层计数，所以这里逻辑简化为按位分流
            int left_child = nxt[p][0];
            int left_pass = (left_child != -1) ? pass[left_child] : 0;

            if (k <= left_pass) {
                p = left_child;
            } else {
                k -= left_pass;
                res |= (1 << i);
                p = nxt[p][1];
            }
        }
        return res;
    }
};
```

# KMP 算法

## 实现 (结构体封装版)

KMP 算法用于在主串中快速查找模式串。其核心在于利用已匹配的信息，通过 `next` 数组（失配函数）跳过不必要的比较。

### 代码

```cpp
vector<int> kmp(string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
```


# AC 自动机 

## 定义
AC 自动机的拓扑排序优化版本。在标准 AC 自动机中，如果每次文本串匹配到一个节点都暴力向上跳 `fail` 指针更新答案，会被特殊构造的数据（如全 `a` 串）卡成 $O(|S| \times \text{模式串总长})$。拓扑排序优化通过只在匹配时给当前节点打上标记，最后根据 `fail` 树的拓扑序统一向上合并贡献，将时间复杂度严格保证为 $O(|S| + \sum|T|)$。

## 实现

### 代码

```cpp
struct AC
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        array<int, ALPHABET> nxt;
        Node() : len(0), link(0), nxt{} {};
    };
    vector<Node> t;
    AC()
    {
        init();
    }
    void init()
    {
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        return t.size() - 1;
    }
    int insert(string &a)
    {
        int p = 1;
        for (auto c : a)
        {
            int u = c - 'a';
            if (next(p, u) == 0)
            {
                t[p].nxt[u] = newNode();
                t[next(p,u)].len = t[p].len + 1;
            }
            p =next(p,u);
        }
        return p;
    }
    void work()
    {
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++)
            {
                if (next(x, i) == 0)
                {
                    t[x].nxt[i] = next(link(x),i);
                }
                else
                {
                    t[next(x,i)].link = next(link(x),i);
                    q.push(next(x,i));
                }
            }
        }
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
};
```


```cpp
#include <bits/stdc++.h>
using namespace std;

struct AC
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        int cnt;
        array<int, ALPHABET> nxt;
        Node() : len(0), link(0), nxt{}, cnt(0) {};
    };
    vector<Node> t;
    vector<int> ind;
    AC()
    {
        init();
    }
    void init()
    {
        ind.assign(2, 0);
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        ind.emplace_back(0);
        return t.size() - 1;
    }
    int insert(string &a)
    {
        int p = 1;
        for (auto c : a)
        {
            int u = c - 'a';
            if (next(p, u) == 0)
            {
                t[p].nxt[u] = newNode();
                t[next(p, u)].len = t[p].len + 1;
            }
            p = next(p, u);
        }
        return p;
    }
    void work()
    {
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++)
            {
                if (next(x, i) == 0)
                {
                    t[x].nxt[i] = next(link(x), i);
                }
                else
                {
                    ind[next(link(x), i)]++;
                    t[next(x, i)].link = next(link(x), i);
                    q.push(next(x, i));
                }
            }
        }
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
    void match(const string &s)
    {
        int p = 1;
        for (auto c : s)
        {
            p = next(p, c - 'a');
            t[p].cnt++;
        }
    }
    void topu()
    {
        queue<int> q;
        for (int i = 1; i < t.size(); i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            int v = link(u);
            t[v].cnt += t[u].cnt;
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
};
signed main()
{
    int n;
    cin >> n;
    vector<int> pos(n);
    AC ac;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        pos[i] = ac.insert(s);
    }
    ac.work();
    string t;
    cin >> t;
    ac.match(t);
    ac.topu();
    for (int i = 0; i < n; i++)
        cout << ac.t[pos[i]].cnt << '\n';
    return 0;
}
```
# 后缀自动机

## 定义

后缀自动机（Suffix Automaton, 简称 SAM）是一个能识别一个字符串的所有子串的确定性有限状态自动机（DFA）。它的状态数和转移数均是线性的（节点数不超过 $2n-1$，转移数不超过 $3n-2$），常用于解决复杂的字符串子串匹配、出现次数统计、最长公共子串等问题。

## 实现

后缀自动机的线性时间在线构造算法。采用结构体封装，节点下标从 1 开始，0 作为空指针，字符集默认为小写字母。

### 代码

```cpp
struct SAM
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        array<int, ALPHABET> nxt;
        Node() : len{}, link{}, nxt{} {};
    };
    vector<Node> t;
    SAM() { init(); };
    void init()
    {
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        return t.size() - 1;
    }
    int insert(int p, int c)
    {
        if (next(p, c))
        {
            int q = next(p, c);
            if (t[q].len == t[p].len + 1)
                return q;
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = link(q);
            t[r].nxt = t[q].nxt;
            t[q].link = r;
            while (t[p].nxt[c] == q)
            {
                t[p].nxt[c] = r;
                p = link(p);
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!next(p, c))
        {
            t[p].nxt[c] = cur;
            p = link(p);
        }
        t[cur].link = insert(p, c);
        return cur;
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
};
```


```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SAM
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link, cnt;
        array<int, ALPHABET> nxt;
        Node() : len{}, link{}, nxt{}, cnt(0) {};
    };
    vector<Node> t;
    vector<int> ind;
    SAM() { init(); };
    void init()
    {
        ind.assign(2, 0);
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        ind.emplace_back(0);
        return t.size() - 1;
    }
    int insert(int p, int c)
    {
        if (next(p, c))
        {
            int q = next(p, c);
            if (t[q].len == t[p].len + 1)
                return q;
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = link(q);
            if (link(r))
                ind[link(r)]++;
            if (link(q))
                ind[link(q)]--;
            t[r].nxt = t[q].nxt;
            t[q].link = r;
            ind[r]++;
            while (t[p].nxt[c] == q)
            {
                t[p].nxt[c] = r;
                p = link(p);
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        t[cur].cnt = 1;
        while (!next(p, c))
        {
            t[p].nxt[c] = cur;
            p = link(p);
        }
        t[cur].link = insert(p, c);
        if (link(cur))
            ind[link(cur)]++;
        return cur;
    }
    void topu()
    {
        queue<int> q;
        for (int i = 1; i < t.size(); i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            int v = link(u);
            t[v].cnt += t[u].cnt;
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
};
signed main()
{
    string s;
    cin >> s;
    SAM sam;
    int last = 1;
    for (auto c : s)
    {
        last = sam.insert(last, c - 'a');
    }
    sam.topu();
    auto &t = sam.t;
    int ans = 0;
    for (auto u : t)
    {
        if (u.cnt > 1)
            ans = max(ans, u.len * u.cnt);
    }
    cout << ans << '\n';
    return 0;
}
```