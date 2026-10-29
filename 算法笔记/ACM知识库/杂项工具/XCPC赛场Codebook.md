---
tags:
  - acm
  - tool
category: 杂项工具
source:
  - "XCPC赛场Codebook.md"
---

# XCPC赛场Codebook

## 模块名称

XCPC赛场Codebook

## 来源

- XCPC赛场Codebook.md

## 适用场景

比赛中辅助建模、优化实现或降低出错率的工具模板。

## 核心思想

XCPC赛场Codebook 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：XCPC赛场Codebook.md

# XCPC赛场Codebook

> 页码：P001

## 首页：目录

```text
ACM Codebook
1. 基础模板  P005-P009
   1.1 基础模板  P005
   1.2 三分查找  P006
   1.3 位运算  P007
   1.4 向上向下取整  P008
   1.5 Ubuntu ICPCOS  P009
2. 数据结构  P010-P018
   2.1 并查集  P010
   2.2 可撤销并查集  P011
   2.3 莫队  P012
   2.4 权值线段树  P013
   2.5 扫描线  P014
   2.6 线段树  P015
   2.7 线段树分治  P016
   2.8 线段树合并与分裂  P017
   2.9 主席树  P018
3. 图论  P019-P038
   3.1 边双连通分量  P019
   3.2 差分约束  P020
   3.3 点分治  P021
   3.4 点双连通分量  P022
   3.5 费用流  P023
   3.6 强连通分量  P024
   3.7 树直径  P025
   3.8 树重心  P026
   3.9 重链剖分  P027
   3.10 最小生成树  P028
   3.11 Bellman–Ford 算法  P029
   3.12 Dijkstra 算法  P030
   3.13 Dinic  P031
   3.14 DSU on Tree  P032
   3.15 EK算法  P033
   3.16 Floyd 算法  P034
   3.17 Johnson 算法  P035
   3.18 Kruskal重构树  P036
   3.19 LCA  P037
   3.20 SPFA算法  P038
4. 动态规划  P039-P042
   4.1 01背包问题  P039
   4.2 多重背包问题  P040
   4.3 多重背包问题的二进制优化  P041
   4.4 完全背包问题  P042
5. 数学  P043-P051
   5.1 二项式反演  P043
   5.2 广义二项式定理  P044
   5.3 计算几何  P045
   5.4 矩阵快速幂  P046
   5.5 快速傅里叶变换（FFT）  P047
   5.6 快速数论变换（NTT）  P048
   5.7 普通生成函数  P049
   5.8 线性基  P050
   5.9 int128类定义  P051
6. 字符串  P052-P059
   6.1 01-Trie  P052
   6.2 后缀自动机  P053
   6.3 扩展kmp（Z函数）  P054
   6.4 字符串哈希  P055
   6.5 AC自动机  P056
   6.6 KMP算法  P057
   6.7 Manacher  P058
   6.8 Trie树  P059
7. 杂项工具  P060-P062
   7.1 随机  P060
   7.2 异或哈希  P061
   7.3 指数哈希  P062
```

---

# 高频必带模板 TOP 15

> 页码：P002

1. 线段树  P015
2. 并查集  P010
3. Dijkstra 算法  P030
4. LCA  P037
5. KMP算法  P057
6. 字符串哈希  P055
7. Dinic  P031
8. 费用流  P023
9. 01背包问题  P039
10. 完全背包问题  P042
11. 多重背包问题的二进制优化  P041
12. 最小生成树  P028
13. AC自动机  P056
14. 快速数论变换（NTT）  P048
15. 计算几何  P045

---

# 最容易写错 TOP 10

> 页码：P003

1. 线段树：pushdown 忘记清空 tag，区间开闭混用。
2. Dijkstra：负权边误用，距离没开 long long。
3. SPFA：vis 只表示在队列中，不表示最短路确定。
4. 背包：01 倒序，完全正序，多重拆包后倒序。
5. 可撤销并查集：不能路径压缩。
6. 字符串哈希：区间长度和 base/pow 下标写错。
7. Floyd：k 必须在最外层，初始化 d[i][i]=0。
8. KMP：pi/next 下标体系混用。
9. 网络流：反向边 i^1 编号必须成对维护。
10. 计算几何：eps 比较和叉积方向先统一。

---

# 推荐使用顺序

> 页码：P004

1. 基础模板、读入输出、随机、int128。
2. 数据结构：并查集、线段树、主席树、莫队。
3. 图论：最短路、最小生成树、LCA、连通性、网络流。
4. 动态规划：背包模型先扫循环方向。
5. 字符串：KMP、哈希、Trie、AC自动机、SAM。
6. 数学：矩阵快速幂、线性基、FFT/NTT、组合工具。


---

# 基础模板

> 页码：P005

## 作用

基础模板 的赛场模板。

## 核心思想

保留最短可用实现，按题目条件直接套用。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
```

## 复杂度

见代码主循环。

## 易错点

- 多测时清空全局变量。
- 关闭同步后不要混用 scanf/printf 和 cin/cout。


---

# 三分查找

> 页码：P006

## 作用

在整数单峰函数上求最大/最小值位置或值。

## 核心思想

每次取两个三等分点缩小单峰区间，最后暴力扫小区间。

## 标准代码

```cpp
template<class F>
long long ternary_max_ll(long long l, long long r, F f) {
    while (r - l > 3) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) l = m1 + 1;
        else r = m2 - 1;
    }
    long long best = l;
    for (long long i = l + 1; i <= r; i++) {
        if (f(i) > f(best)) best = i;
    }
    return best;
}
```

## 复杂度

O(log n * T_f)

## 易错点

- 只适用于单峰/单谷函数。
- 整数三分最后要暴力扫剩余小区间。


---

# 位运算

> 页码：P007

## 作用

快速查询整数二进制性质，如 popcount、前导零、后缀零和 2 的幂。

## 核心思想

优先使用 C++20 `<bit>` 标准函数；兼容时使用 GCC builtin。

## 标准代码

```cpp
#include <bit>

int ones(unsigned x) { return popcount(x); }
int ones_ll(unsigned long long x) { return popcount(x); }
int leading_zero(unsigned x) { return countl_zero(x); }
int trailing_zero(unsigned x) { return countr_zero(x); }
bool is_pow2(unsigned x) { return has_single_bit(x); }
unsigned down_pow2(unsigned x) { return bit_floor(x); }
unsigned up_pow2(unsigned x) { return bit_ceil(x); }

// GCC fallback:
// __builtin_popcount(x), __builtin_popcountll(x)
// __builtin_clz(x), __builtin_clzll(x)
// __builtin_ctz(x), __builtin_ctzll(x)
```

## 复杂度

O(1)

## 易错点

- __builtin_clz/ctz 不能传 0。
- clz/ctz 的 int 和 long long 版本不要混用。


---

# 向上向下取整

> 页码：P008

## 作用

处理带负数的整数除法上取整和下取整。

## 核心思想

先按 C++ 截断除法求商，再根据余数和符号修正。

## 标准代码

```cpp
long long floor_div(long long a, long long b) {
    long long q = a / b, r = a % b;
    if (r && ((a < 0) ^ (b < 0))) q--;
    return q;
}

long long ceil_div(long long a, long long b) {
    long long q = a / b, r = a % b;
    if (r && !((a < 0) ^ (b < 0))) q++;
    return q;
}
```

## 复杂度

O(1)

## 易错点

- 除数不能为 0。
- 负数除法不能直接用 (a+b-1)/b。


---

# Ubuntu ICPCOS

> 页码：P009

## 作用

赛场 Linux 环境下一键编译运行当前题目文件。

## 核心思想

用脚本统一 g++ 参数、输出文件名和运行日志，减少手敲命令失误。

## 标准代码

```shell
#!/bin/bash
target=$1
src="${target}.cpp"
g++ -std=gnu++20 -O2 -Wall -Wextra "$src" -o "$target" && \
./"$target" 2>&1 | tee "${target}.txt"
```

## 复杂度

编译 O(源文件大小)，运行按程序复杂度

## 易错点

- 先执行 chmod +x ./run.sh。
- 文件名传入不带 .cpp 后缀。


---

# 并查集

> 页码：P010

## 作用

维护集合连通性，支持合并与查询两个点是否属于同一集合。

## 核心思想

父指针表示集合代表元，路径压缩与按大小合并保证近似常数复杂度。

## 标准代码

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

## 复杂度

均摊 O(alpha(n))

## 易错点

- 初始化范围要覆盖所有编号。
- 合并前必须 find。
- 维护 size 时只能在根节点维护。


---

# 可撤销并查集

> 页码：P011

## 作用

支持合并集合并回滚到历史状态，常配合线段树分治。

## 核心思想

不用路径压缩，只记录每次成功合并前的状态，回溯时从栈中恢复。

## 标准代码

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

## 复杂度

O(log n) 或近似 O(log n)

## 易错点

- 初始化范围要覆盖所有编号。
- 合并前必须 find。
- 维护 size 时只能在根节点维护。


---

# 莫队

> 页码：P012

## 作用

离线处理区间查询，要求端点移动能快速维护答案。

## 核心思想

按块排序询问，让左右端点总移动距离降到约 O(n sqrt n)。

## 标准代码

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

## 复杂度

O((n+m) sqrt n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 权值线段树

> 页码：P013

## 作用

维护值域频次，支持排名、第 k 小、前驱后继等查询。

## 核心思想

在线段树上维护值域而非下标区间，节点保存该值域内数量。

## 标准代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int cnt;
    Info() : cnt(0){};
    Info(int value) :cnt(value) {};
    Info operator+(const Info &other) const
    {
        return Info(cnt+other.cnt);
    }
};
struct ValueSegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    ValueSegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
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
    int query(int x, int y)
    {
        return query(1, 0, n, x, y).cnt;
    };

    int rank(int val){
        return query(0,val)+1;
    }
    
    // 单点修改:在x上加v
    void modify(int p, int l, int r, int x, int v)
    {
        if (r - l == 1)
        {
            info[p].cnt += v;
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
        modify(1, 0, n, x, v);
    }

    int query_kth(int p,int l,int r,int k){
        if(r-l==1){
            return l;
        }
        int mid=l+r>>1;
        int l_cnt=info[p<<1].cnt;
        if(k<=l_cnt)
            return query_kth(p<<1,l,mid,k);
        else 
            return query_kth(p<<1|1,mid,r,k-l_cnt);
    }
    int query_kth(int k){
        return query_kth(1,0,n,k);
    }
};
void solve()
{
    int n;
    cin>>n;
    vector<array<int,2>>q(n);
    vector<int>b;
    for(auto &[op,v]:q){
        cin>>op>>v;
        b.push_back(v);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(),b.end()),b.end());
    auto get_idx=[&](int x){
        return ranges::lower_bound(b,x)-b.begin()+1;
    };
    ValueSegTree T((int)b.size()+1);
    
    for(auto [op,v]:q){
        int idx=get_idx(v);
        if(op==1){
            T.modify(idx,1);
        }
        else if(op==2){
            T.modify(idx,-1);
        }
        else if(op==3){
            cout<<T.rank(idx)<<'\n';
        }
        else if(op==4){
            cout<<b[T.query_kth(v)-1]<<'\n';
        }
        else if(op==5){
            cout<<b[T.query_kth(T.rank(idx)-1)-1]<<'\n';
        }
        else{
            cout<<b[T.query_kth(T.query(0,idx+1)+1)-1]<<'\n';
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

## 复杂度

O(log V)

## 易错点

- `mid = l + r >> 1` 建议写成 `(l + r) >> 1`，避免读代码时误判优先级。
- 区间统一使用 `[l, r)` 或 `[l, r]`，不要混用。
- 下放懒标记前要保证当前节点确实有标记。


---

# 扫描线

> 页码：P014

## 作用

处理矩形面积/周长并、区间覆盖长度等几何转数据结构问题。

## 核心思想

把二维事件按一维排序，另一维用线段树维护覆盖长度。

## 标准代码

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

## 复杂度

O(n log n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 线段树

> 页码：P015

## 作用

维护区间和、最值、区间修改等动态区间信息。

## 核心思想

递归拆分区间，节点保存可合并信息，懒标记延迟下传区间修改。

## 标准代码

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

## 复杂度

单次 O(log n)，空间 O(n)

## 易错点

- `mid = l + r >> 1` 建议写成 `(l + r) >> 1`，避免读代码时误判优先级。
- 区间统一使用 `[l, r)` 或 `[l, r]`，不要混用。
- 下放懒标记前要保证当前节点确实有标记。


---

# 线段树分治

> 页码：P016

## 作用

处理按时间区间生效的离线动态图/约束问题。

## 核心思想

把生存区间挂到时间线段树节点，DFS 时用可撤销结构维护当前状态。

## 标准代码

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

## 复杂度

O(m log q * T)

## 易错点

- `mid = l + r >> 1` 建议写成 `(l + r) >> 1`，避免读代码时误判优先级。
- 区间统一使用 `[l, r)` 或 `[l, r]`，不要混用。
- 下放懒标记前要保证当前节点确实有标记。


---

# 线段树合并与分裂

> 页码：P017

## 作用

合并/拆分动态开点线段树，常用于树上值域统计。

## 核心思想

递归合并左右儿子；分裂时按计数把指定前缀拆出。

## 标准代码

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

## 复杂度

均摊 O(节点数)

## 易错点

- `mid = l + r >> 1` 建议写成 `(l + r) >> 1`，避免读代码时误判优先级。
- 区间统一使用 `[l, r)` 或 `[l, r]`，不要混用。
- 下放懒标记前要保证当前节点确实有标记。


---

# 主席树

> 页码：P018

## 作用

静态区间第 k 小和历史版本查询。

## 核心思想

每次修改复制根到叶的一条链，其他节点复用，区间信息用两个版本相减。

## 标准代码

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

## 复杂度

建树 O(n log V)，查询 O(log V)

## 易错点

- 离散化后查询答案要映射回原值。
- 节点池大小要按 n log n 预估。


---

# 边双连通分量

> 页码：P019

## 作用

无向图边双、桥相关问题。

## 核心思想

Tarjan 找桥，去桥后 DFS 染色得到边双。

## 标准代码

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

## 复杂度

O(n+m)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 差分约束

> 页码：P020

## 作用

求解形如 xi-xj<=c 的不等式系统并判无解。

## 核心思想

把约束转为有向边，负环代表矛盾。

## 标准代码

```cpp
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

  
// https://www.luogu.com.cn/problem/P1993
const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].pb({b, -c});
        }
        else if (op == 2)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[b].pb({a, c});
        }
        else
        {
            int a, b;
            cin >> a >> b;
            g[a].pb({b, 0});
            g[b].pb({a, 0});
        }
    }
    for (int i = 1; i <= n; i++)
        g[0].pb({i, 0});
    vector<int> dis(n + 1, inf);
    auto spfa = [&]() -> bool
    {
        vector<int> vis(n + 1), cnt(n + 1);
        queue<int> q;
        dis[0] = 0;
        q.push(0);
        vis[0] = 1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            for (auto [v, w] : g[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    cnt[v] = cnt[u] + 1;
                    dis[v] = dis[u] + w;
                    if (cnt[v] >= n)
                        return 0;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
        return 1;
    };
    bool ok = spfa();
    cout << (ok ? "Yes\n" : "No\n");
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

## 复杂度

通常 O(nm)

## 易错点

- 大于等于约束要先变形成小于等于。
- 要加超级源点保证所有变量可达。


---

# 点分治

> 页码：P021

## 作用

处理树上路径统计，尤其路径长度/点对计数。

## 核心思想

每次选重心分治，统计经过当前重心的路径贡献。

## 标准代码

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

## 复杂度

O(n log n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 点双连通分量

> 页码：P022

## 作用

无向图点双、割点相关问题。

## 核心思想

Tarjan 维护边栈/low，遇到 low[v]>=dfn[u] 形成点双。

## 标准代码

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

## 复杂度

O(n+m)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 费用流

> 页码：P023

## 作用

最小费用最大流、费用最优匹配/分配。

## 核心思想

在残量网络中不断找最短费用增广路。

## 标准代码

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

## 复杂度

O(F * m log n) 视实现而定

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 强连通分量

> 页码：P024

## 作用

有向图缩点、环结构分析。

## 核心思想

Tarjan 用 dfn/low 维护 DFS 栈，发现 SCC 根时弹栈。

## 标准代码

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

## 复杂度

O(n+m)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 树直径

> 页码：P025

## 作用

求树上最长简单路径。

## 核心思想

两次 DFS/BFS：任取点找最远点，再从最远点找最远距离。

## 标准代码

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

## 复杂度

O(n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 树重心

> 页码：P026

## 作用

找删除后最大连通块最小的点。

## 核心思想

DFS 统计子树大小并计算每个点作为根时的最大剩余块。

## 标准代码

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

## 复杂度

O(n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 重链剖分

> 页码：P027

## 作用

把树上路径问题转成若干连续区间问题。

## 核心思想

重儿子优先编号，一条路径可拆成 O(log n) 段链上区间。

## 标准代码

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

## 复杂度

O(log^2 n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 最小生成树

> 页码：P028

## 作用

无向连通图选 n-1 条边使总权最小。

## 核心思想

Kruskal 按边权排序，用并查集跳过成环边。

## 标准代码

```cpp
struct DSU {
    vector<int> f, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        f.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        f[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

long long kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long ans = 0;
    int cnt = 0;
    for (auto [u, v, w] : edges) {
        if (dsu.merge(u, v)) {
            ans += w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return cnt == n - 1 ? ans : -1;
}
```

## 复杂度

O(m log m)

## 易错点

- 图不连通时只有最小生成森林。
- 边要按权排序，重边自环要处理。


---

# Bellman–Ford 算法

> 页码：P029

## 作用

有负权边、限制边数最短路、负环检测。

## 核心思想

重复对所有边松弛，第 n 轮仍可松弛说明存在可达负环。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 1e4 + 10, INF = 0x3f3f3f3f;
struct edge
{
    int a, b, v;
} e[M];
int n, m, k;
int d[N], back_d[N];
int bellman_ford()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= k; i++)
    {
        memcpy(back_d, d, sizeof(d));
        for (int j = 1; j <= m; j++)
        {
            int a = e[j].a, b = e[j].b, v = e[j].v;
            d[b] = min(d[b], back_d[a] + v);
        }
    }
    return d[n];
}
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].a >> e[i].b >> e[i].v;
    }
    int ans = bellman_ford();
    if (ans > INF / 2)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}
```

## 复杂度

O(nm)

## 易错点

- 限制边数版本需要备份上一轮距离。
- 不可达点不能参与 INF + w 的有效松弛。


---

# Dijkstra 算法

> 页码：P030

## 作用

非负权图单源最短路，赛场默认使用堆优化版。

## 核心思想

每次取当前最短距离的点出堆，用它松弛出边，过期状态直接跳过。

## 标准代码

```cpp
struct Dijkstra {
    using ll = long long;
    const ll INF = (1LL << 62);
    int n;
    vector<vector<pair<int, int>>> g;
    Dijkstra(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        g.assign(n + 1, {});
    }
    void addEdge(int u, int v, int w) {
        g[u].push_back({v, w});
    }
    vector<ll> run(int s) {
        vector<ll> dis(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dis[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dis[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    }
};
```

## 复杂度

O((n+m) log n)

## 易错点

- 不能处理负权边。
- 距离建议 long long。
- 堆优化要跳过过期状态。


---

# Dinic

> 页码：P031

## 作用

最大流标准模板。

## 核心思想

BFS 建分层图，DFS 在分层图中用当前弧增广。

## 标准代码

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

## 复杂度

一般 O(n^2m)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# DSU on Tree

> 页码：P032

## 作用

离线维护子树颜色/众数等信息。

## 核心思想

轻儿子信息清空，重儿子信息保留，再合并轻儿子贡献。

## 标准代码

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

## 复杂度

O(n log n) 或 O(n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# EK算法

> 页码：P033

## 作用

最大流基础版，适合小图或教学核对。

## 核心思想

每次 BFS 找一条增广路并沿路增广。

## 标准代码

```cpp
const int inf = 1e18;
struct EK
{
    int n;
    struct _edge
    {
        int to;
        int cap;
        _edge(int to, int cap) : to(to), cap(cap) {};
    };
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> pre, pre_e;

    EK() {};
    EK(int n) : n(n) { init(n); };
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        pre.assign(n, 0);
        pre_e.assign(n, 0);
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
        vector<int> vis(n);
        queue<int> q;
        q.push(s);
        pre[s] = -1;
        pre_e[s] = -1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto p : g[u])
            {
                auto [v, c] = e[p];
                if (vis[v] || c <= 0)
                    continue;
                vis[v] = 1;
                pre[v] = u;
                pre_e[v] = p;
                q.push(v);
                if (v == t)
                    return 1;
            }
        }
        return 0;
    }
    int flow(int s, int t)
    {
        int res = 0;
        while (bfs(s, t))
        {
            int f = inf;
            for (int v = t; v != s; v = pre[v])
            {
                int p = pre_e[v];
                f = min(f, e[p].cap);
            }
            for (int v = t; v != s; v = pre[v])
            {
                int p = pre_e[v];
                e[p].cap -= f;
                e[p ^ 1].cap += f;
            }
            res += f;
        }
        return res;
    }
};
```

## 复杂度

O(nm^2)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# Floyd 算法

> 页码：P034

## 作用

点数较小时求全源最短路。

## 核心思想

枚举中转点 k，逐步允许路径经过更多中转点。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 205, INF = 0x3f3f3f3f;
int n, m, k;
int d[N][N];
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    Floyd();
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << d[a][b] << endl;
    }
    return 0;
}
```

## 复杂度

O(n^3)

## 易错点

- 三重循环顺序必须 k 在最外层。
- 重边取 min，不可达用 INF/2 判断。


---

# Johnson 算法

> 页码：P035

## 作用

稀疏图全源最短路，允许负权边但不能有负环。

## 核心思想

先求势能重标边权为非负，再对每个源点跑 Dijkstra。

## 标准代码

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

## 复杂度

O(nm + n(m+n)log n)

## 易错点

- 最后距离要还原 `dis' - h[s] + h[t]`。
- 有负环时必须提前返回无解。


---

# Kruskal重构树

> 页码：P036

## 作用

处理最小生成树上瓶颈路径、连通时间等问题。

## 核心思想

Kruskal 合并连通块时新建点，边权成为新点权值。

## 标准代码

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

## 复杂度

O(m log m + n log n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# LCA

> 页码：P037

## 作用

查询树上两个点最近公共祖先，支撑树上距离/路径问题。

## 核心思想

倍增预处理祖先，先拉平深度再同步上跳。

## 标准代码

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

## 复杂度

预处理 O(n log n)，查询 O(log n)

## 易错点

- 根节点父亲、深度初始化要统一。
- 倍增数组越界和 log 上界常出错。


---

# SPFA算法

> 页码：P038

## 作用

有负权边时的单源最短路或负环判断，慎用于强数据。

## 核心思想

队列维护可能继续松弛其他点的点，只访问被影响的出边。

## 标准代码

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

## 复杂度

最坏 O(nm)

## 易错点

- 无负权边优先 Dijkstra。
- 判负环要记录入队/路径边数。
- vis 表示是否在队列中，不是最短路已确定。


---

# 01背包问题

> 页码：P039

## 作用

每个物品最多选一次的容量最优化。

## 核心思想

一维 dp 时容量倒序，避免同一物品被重复使用。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, v;
    cin >> n >> v;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1];
    vector<int> dp(v + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [cost, val] = a[i];
        for (int j = v; j >= cost; j--)
            dp[j] = max(dp[j], dp[j - cost] + val);
    }
    cout << dp[v] << '\n';
    return 0;
}
```

## 复杂度

O(nV)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 多重背包问题

> 页码：P040

## 作用

每种物品数量有限的背包模型。

## 核心思想

朴素枚举选几个；赛场大数据优先二进制优化。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1), s(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        cin >>
            v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[n][m] << endl;
    return 0;
}
```

## 复杂度

朴素 O(nVK)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 多重背包问题的二进制优化

> 页码：P041

## 作用

有限件物品转化为若干 01 物品。

## 核心思想

把数量拆成 1,2,4,... 的组合包，再按 01 背包倒序转移。

## 标准代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, W;
    cin >> n >> W;
    vector<array<int, 3>> its(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> its[i][0] >> its[i][1] >> its[i][2];
    }
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [val, cost, cnt] = its[i];
        for (int k = 1; k <= cnt; k *= 2)
        {
            for (int i = W; i >= k * cost; i--)
                dp[i] = max(dp[i], dp[i - k * cost] + val * k);
            cnt -= k;
        }
        int k = cnt;
        for (int i = W; i >= k * cost; i--)
            dp[i] = max(dp[i - k * cost] + val * k, dp[i]);
    }
    cout << dp[W] << '\n';
    return 0;
}
```

## 复杂度

O(V sum log cnt)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 完全背包问题

> 页码：P042

## 作用

每个物品可选无限次的容量最优化。

## 核心思想

一维 dp 时容量正序，让当前物品可重复转移。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, v;
    cin >> n >> v;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1];
    vector<int> dp(v + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [cost, val] = a[i];
        for (int j = cost; j <= v; j++)
            dp[j] = max(dp[j], dp[j - cost] + val);
    }
    cout << dp[v] << '\n';
    return 0;
}
```

## 复杂度

O(nV)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 二项式反演

> 页码：P043

## 作用

处理含组合数的求和反推。

## 核心思想

利用二项式变换互逆关系在两个序列间转换。

## 标准代码

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

## 复杂度

O(n) 或 O(n log n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 广义二项式定理

> 页码：P044

## 作用

处理负二项式展开和生成函数系数提取。

## 核心思想

用 C(-n,k)=(-1)^k C(n+k-1,k) 把负上标组合数转成普通组合数。

## 标准代码

```cpp
const int MOD = 998244353;

long long qpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

struct Comb {
    vector<long long> fac, ifac;
    Comb(int n = 0) { init(n); }
    void init(int n) {
        fac.assign(n + 1, 1);
        ifac.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
        ifac[n] = qpow(fac[n], MOD - 2);
        for (int i = n; i; i--) ifac[i - 1] = ifac[i] * i % MOD;
    }
    long long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    }
    long long generalized_C(int alpha, int k) {
        if (k < 0) return 0;
        if (alpha >= 0) return C(alpha, k);
        int n = -alpha;
        long long res = C(n + k - 1, k);
        return (k & 1) ? (MOD - res) % MOD : res;
    }
    long long coeff_negative_pow(int n, int k) {
        return C(n + k - 1, n - 1);
    }
};
```

## 复杂度

预处理 O(n)，单次 O(1)

## 易错点

- 预处理阶乘上界要覆盖 n+k。
- 负上标组合数要处理 (-1)^k。


---

# 计算几何

> 页码：P045

## 作用

点、线、线段、圆的基础几何运算。

## 核心思想

用点积处理投影/角度，用叉积处理方向/面积/相交。

## 标准代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);

int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

int cmp(double x, double y)
{
    return sign(x - y);
}

double Acos(double x)
{
    if (x < -1)
        return pi;
    if (x > 1)
        return 0;
    return acos(x);
}

// ==========================================
// 点与向量的结构体
// ==========================================
struct Point;
using Vector = Point;

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }

    bool operator==(const Point &b) const
    {
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0;
    }

    // 点的大小比较：以 x 为第一关键字，y 为第二关键字（常用于排序）
    bool operator<(const Point &b) const
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }

    // 计算向量模长（两点间距离）
    double len() const
    {
        return hypot(x, y);
    }

    // 计算向量模长的平方
    double len2() const
    {
        return x * x + y * y;
    }

    // 求当前向量的法向量（逆时针旋转 90 度）
    Vector normal() const
    {
        return Point(-y, x);
    }

    // 求该点/向量关于原点的极角，范围在 [-pi, pi] 之间
    double p_angle() const
    {
        return atan2(y, x);
    }

    // 向量单位化（归一化）
    Vector unit() const
    {
        double l = this->len();
        if (sign(l) == 0)
            return (*this);
        return (*this) / l;
    }

    // 向量逆时针旋转给定弧度 angle
    Vector rotate(double angle) const
    {
        double c = cos(angle), s = sin(angle);
        return Point(x * c - y * s, x * s + y * c);
    }
};

// 计算两个向量的点积（内积）
double dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

// 计算两个向量的叉积（外积）
double cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}

// 计算两个向量的夹角，范围在 [0, pi] 之间
double get_angle(const Vector &a, const Vector &b)
{
    return fabs(atan2(cross(a, b), dot(a, b)));
}

// 计算以点 a 为起点，ab 和 ac 构成的平行四边形的有向面积
double area(const Point &a, const Point &b, const Point &c)
{
    return cross(b - a, c - a);
}

// 判断三点是否共线
bool is_collinear(const Point &a, const Point &b, const Point &c)
{
    return sign(cross(b - a, c - a)) == 0;
}

// 求当前点关于点 o 的对称点
Point reflect(const Point &p, const Point &o)
{
    return o * 2.0 - p;
}

// 精准全平面极角排序比较器（按逆时针排序，不使用 atan2，防精度误差）
struct Polarcmp
{
    // 象限判断：1->右上(含X正), 2->左上(含Y正), 3->左下(含X负), 4->右下(含Y负)
    int quad(const Point &p) const
    {
        if (p.x >= 0 && p.y >= 0)
            return 1;
        if (p.x < 0 && p.y >= 0)
            return 2;
        if (p.x < 0 && p.y < 0)
            return 3;
        return 4;
    }

    // 比较函数
    bool operator()(const Point &a, const Point &b) const
    {
        int qa = quad(a), qb = quad(b);
        if (qa != qb)
            return qa < qb; // 象限不同，象限小的排前面
        double c = cross(a, b);
        if (sign(c) != 0)
            return sign(c) > 0;     // 象限相同，叉积大于0说明 b 在 a 的左侧（逆时针）
        return a.len2() < b.len2(); // 极角相同时，距离近的排前面
    }
};

// ==========================================
// 直线
// ==========================================
struct Line
{
    Point p;  // 直线上的基准点
    Vector v; // 直线的方向向量（参数方程：p + t*v）
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {}

    // 判定两条直线的关系
    // 返回值：0 相交 | 1 平行 | 2 重合
    static int line_relation(const Line &a, const Line &b)
    {
        if (sign(cross(a.v, b.v)) != 0)
            return 0;
        if (sign(cross(a.v, b.p - a.p)) == 0)
            return 2;
        return 1;
    }

    // 判定点 a 与有向直线（p -> p+v） Orient/To-Left 的位置关系
    // 返回值：1 在直线左侧 | -1 在直线右侧 | 0 在直线上
    int to_left(const Point &a) const
    {
        return sign(cross(v, a - p));
    }

    // 计算点 a 到该直线的垂直距离
    double dist(const Point &a) const
    {
        return fabs(cross(v, a - p)) / v.len();
    }

    // 求点 a 在该直线上的垂直投影点
    Point proj(const Point &a) const
    {
        return p + v * (dot(a - p, v) / v.len2());
    }

    // 求点 a 关于该直线的对称点（镜像点）
    Point reflect(const Point &a) const
    {
        Point pr = proj(a);
        return pr * 2.0 - a;
    }
};

// 求两条直线 a 和 b 的唯一交点（需提前断定它们不平行）
Point inter_l2l(const Line &a, const Line &b)
{
    assert(sign(cross(a.v, b.v)) != 0);
    Vector u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p + a.v * t;
}

// ==========================================
// 线段
// ==========================================
struct Segment
{
    Point a, b; // 线段的两个端点
    Segment() {}
    Segment(Point a, Point b) : a(a), b(b) {}

    // 判断点 p 与当前线段的位置关系：-1 在端点上 | 1 严格在线段内部 | 0 不在线段上
    int on_segment(const Point &p) const
    {
        if (p == a || p == b)
            return -1;
        if (sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0)
            return 1;
        return 0;
    }

    // 判断两线段是否相交：-1 端点处接触相交 | 1 严格在内部交叉相交 | 0 互不相交
    int is_inter(const Segment &s) const
    {
        if (on_segment(s.a) != 0 || on_segment(s.b) != 0 || s.on_segment(a) != 0 || s.on_segment(b) != 0)
            return -1;
        double c1 = cross(b - a, s.a - a), c2 = cross(b - a, s.b - a);
        double c3 = cross(s.b - s.a, a - s.a), c4 = cross(s.b - s.a, b - s.a);
        return (sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0) ? 1 : 0;
    }

    // 计算点 p 到当前线段的最短距离
    double dist(const Point &p) const
    {
        if (a == b)
            return (p - a).len();
        Vector v1 = b - a, v2 = p - a, v3 = p - b;
        if (sign(dot(v1, v2)) < 0)
            return v2.len();
        if (sign(dot(v1, v3)) > 0)
            return v3.len();
        Line l{a, b - a};
        return l.dist(p); // 正常向线段作垂线距离
    }

    // 计算当前线段到另一条线段 s 的最短距离
    double dist(const Segment &s) const
    {
        if (is_inter(s) != 0)
            return 0;
        return min({dist(s.a), dist(s.b), s.dist(a), s.dist(b)});
    }
};

// 求两条线段的交点坐标（调用前必须先确保 is_inter 返回非 0 状态）
Point inter_s2s(const Segment &s1, const Segment &s2)
{
    assert(s1.is_inter(s2) == 0);
    Line l1{s1.a, s1.b - s1.a};
    Line l2{s2.a, s2.b - s2.a};
    return inter_l2l(l1, l2);
}

// ==========================================
// 圆
// ==========================================
struct Circle
{
    Point o;
    double r;
    Circle() {};
    Circle(Point o, double r) : o(o), r(r) {};

    bool operator==(const Circle &a) const
    {
        return o == a.o && cmp(r, a.r) == 0;
    }
};
```

## 复杂度

基础操作 O(1)

## 易错点

- 不要直接比较 double 相等。
- 叉积方向和端点接触返回值要先约定。
- 断言条件要和函数返回值一致。


---

# 矩阵快速幂

> 页码：P046

## 作用

线性递推、路径计数等矩阵转移快速幂。

## 核心思想

把转移写成矩阵乘法，用二进制快速幂加速。

## 标准代码

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

## 复杂度

O(k^3 log n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 快速傅里叶变换（FFT）

> 页码：P047

## 作用

复数域卷积和多项式乘法。

## 核心思想

分治/迭代把系数表示转点值表示，逐点相乘后逆变换。

## 标准代码

```cpp
const double pi = acos(-1.0);
using Complex = complex<double>;
struct FFT
{
    vector<int> a, b;
    FFT(vector<int> &a, vector<int> &b) : a(a), b(b) {};
    vector<int> mul()
    {
        int n = 1;
        int tot = a.size() + b.size() - 1;
        while (n < tot)
        {
            n <<= 1;
        }
        vector<Complex> fa(n), fb(n);
        for (int i = 0; i < a.size(); i++)
        {
            fa[i] = a[i];
        }
        for (int i = 0; i < b.size(); i++)
        {
            fb[i] = b[i];
        }
        dft(fa);
        dft(fb);
        for (int i = 0; i < n; i++)
        {
            fa[i] *= fb[i];
        }
        idft(fa);
        vector<int> c(tot);
        for (int i = 0; i < c.size(); i++)
        {
            c[i] = round(fa[i].real());
        }
        return c;
    }
    void dft(vector<Complex> &a)
    {
        int n = a.size();
        vector<int> rev(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < n; k <<= 1)
        {
            Complex wn(cos(pi / k), sin(pi / k));
            for (int i = 0; i < n; i += 2 * k)
            {
                Complex w(1, 0);
                for (int j = 0; j < k; j++)
                {
                    Complex u = a[i + j], v = a[i + j + k] * w;
                    a[i + j] = u + v;
                    a[i + j + k] = u - v;
                    w *= wn;
                }
            }
        }
    }
    void idft(vector<Complex> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        for (int i = 0; i < n; i++)
        {
            a[i] /= n;
        }
    }
};
```

## 复杂度

O(n log n)

## 易错点

- 长度要扩到不小于卷积长度的 2 的幂。
- 浮点四舍五入和精度误差要处理。


---

# 快速数论变换（NTT）

> 页码：P048

## 作用

模意义下整数卷积。

## 核心思想

用模数原根替代复数单位根，避免浮点误差。

## 标准代码

```cpp
namespace NTT
{
    const int mod = 998244353, g = 3;
    int exp(int a, int b)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = a * ans % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    void dft(vector<int> &a)
    {
        int n = a.size();
        vector<int> rev(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < n; k <<= 1)
        {
            int wn = exp(g, (mod - 1) / (2 * k));
            for (int i = 0; i < n; i += 2 * k)
            {
                int w = 1;
                for (int j = 0; j < k; j++)
                {
                    int u = a[i + j], v = a[i + j + k] * w % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + k] = (u - v + mod) % mod;
                    (w *= wn) %= mod;
                }
            }
        }
    }
    void idft(vector<int> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        int inv = exp(n, mod - 2);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= inv) %= mod;
        }
    }
    vector<int> mul(vector<int> a, vector<int> b)
    {
        int tot = a.size() + b.size() - 1;
        int n = 1;
        while (n < tot)
        {
            n <<= 1;
        }
        a.resize(n), b.resize(n);
        dft(a), dft(b);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= b[i]) %= mod;
        }
        idft(a);
        a.resize(tot);
        return a;
    }
};
```

## 复杂度

O(n log n)

## 易错点

- 模数必须支持所需长度的原根。
- 逆变换后要乘 inv(n)。


---

# 普通生成函数

> 页码：P049

## 作用

组合计数和序列卷积建模。

## 核心思想

把计数序列写成形式幂级数，运算对应组合结构。

## 标准代码

```cpp
// 场景：已知每种物品的选法 A(x)，求总长度为 n 的排列方案数
// 对应公式：G(x) = 1 / (1 - A(x))
// 如果 A(x) 是简单多项式，通常使用线性递推或 Bostan-Mori 提取系数
// 如果 A(x) 项数较多，使用多项式求逆 O(N log N)
vector<int> PolyInv(vector<int> A, int n); // 标准模板
```

## 复杂度

视卷积实现而定

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 线性基

> 页码：P050

## 作用

异或最大值、异或可表示性、异或空间秩。

## 核心思想

每个最高位保留一个基向量，高位优先消元。

## 标准代码

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

## 复杂度

O(n log V)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# int128类定义

> 页码：P051

## 作用

读写和计算超过 long long 的整数。

## 核心思想

用 __int128 存值，手写输入输出和常用运算。

## 标准代码

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

## 复杂度

按位数 O(log n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 01-Trie

> 页码：P052

## 作用

维护整数集合，查询最大异或值/第 k 小等。

## 核心思想

按二进制位建 Trie，最大异或时优先走相反位。

## 标准代码

```cpp
struct BinaryTrie {
    vector<array<int, 2>> nxt;
    vector<int> pass;
    int L;
    BinaryTrie(int max_bit = 30) : L(max_bit) { init(); }
    void init() {
        nxt.assign(1, {-1, -1});
        pass.assign(1, 0);
    }
    void insert(int x) {
        int p = 0;
        pass[p]++;
        for (int i = L; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (nxt[p][b] == -1) {
                nxt[p][b] = (int)nxt.size();
                nxt.push_back({-1, -1});
                pass.push_back(0);
            }
            p = nxt[p][b];
            pass[p]++;
        }
    }
    int max_xor(int x) const {
        int p = 0, ans = 0;
        for (int i = L; i >= 0; i--) {
            int b = (x >> i) & 1;
            int q = nxt[p][b ^ 1];
            if (q != -1 && pass[q] > 0) {
                ans |= 1 << i;
                p = q;
            } else {
                p = nxt[p][b];
            }
        }
        return ans;
    }
};
```

## 复杂度

O(log V)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 后缀自动机

> 页码：P053

## 作用

维护一个字符串所有子串的信息。

## 核心思想

在线扩展状态，link 表示最长可接受后缀。

## 标准代码

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

## 复杂度

O(n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 扩展kmp（Z函数）

> 页码：P054

## 作用

求每个后缀与原串的最长公共前缀。

## 核心思想

维护当前最右匹配区间，复用对称位置的 Z 值。

## 标准代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://www.luogu.com.cn/problem/P5410
vector<int> Z(string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++)
    {
        z[i] = max(0LL, min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > j + z[j])
            j = i;
    }
    return z;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    auto z = Z(b);
    vector<int> e(n);
    for (int i = 0, j = 0; i < n; i++)
    {
        e[i] = max(0LL, min(j + e[j] - i, z[i - j]));
        while (i + e[i] < n && e[i] < m && a[i + e[i]] == b[e[i]])
            e[i]++;
        if (i + e[i] > j + e[j])
            j = i;
    }
    int valz = 0;
    for (int i = 0; i < m; i++)
    {
        valz ^= (i + 1) * (z[i] + 1);
    }
    int vale = 0;
    for (int i = 0; i < n; i++)
    {
        vale ^= (i + 1) * (e[i] + 1);
    }
    cout << valz << '\n'
         << vale << '\n';
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

## 复杂度

O(n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 字符串哈希

> 页码：P055

## 作用

快速判断子串相等、去重、LCP 二分。

## 核心思想

前缀哈希支持 O(1) 计算任意子串哈希。

## 标准代码

```cpp
using u64 = unsigned long long;
using u128 = __uint128_t;

struct StringHash {
    static constexpr u64 MOD = (1ULL << 61) - 1;
    static u64 base;
    vector<u64> h, p;

    static u64 add(u64 a, u64 b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }
    static u64 sub(u64 a, u64 b) {
        return a >= b ? a - b : a + MOD - b;
    }
    static u64 mul(u64 a, u64 b) {
        return (u64)((u128)a * b % MOD);
    }
    StringHash(const string &s = "") { init(s); }
    void init(const string &s) {
        int n = (int)s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = add(mul(h[i], base), (unsigned char)s[i]);
            p[i + 1] = mul(p[i], base);
        }
    }
    u64 get(int l, int r) {
        return sub(h[r], mul(h[l], p[r - l]));
    }
};
u64 StringHash::base = chrono::steady_clock::now().time_since_epoch().count() % (StringHash::MOD / 2) + StringHash::MOD / 4;
```

## 复杂度

预处理 O(n)，查询 O(1)

## 易错点

- base/bs 变量名要一致。
- 单哈希可能冲突，关键题建议双哈希或 2^61-1。
- 区间 `[l,r)` 长度要写对。


---

# AC自动机

> 页码：P056

## 作用

多模式串匹配与出现次数统计。

## 核心思想

Trie 上建 fail 指针，匹配后沿 fail 树汇总贡献。

## 标准代码

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

## 复杂度

O(文本长+模式总长)

## 易错点

- fail 转移要补全，否则匹配时会掉到 0。
- 多模式计数要处理重复模式和 fail 树贡献。


---

# KMP算法

> 页码：P057

## 作用

单模式串匹配、border、周期问题。

## 核心思想

失配时跳到最长相等前后缀位置，主串指针不回退。

## 标准代码

```cpp
vector<int> prefix_function(const string &s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_match(const string &text, const string &pat) {
    string s = pat + '#' + text;
    vector<int> pi = prefix_function(s), pos;
    int m = (int)pat.size();
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (pi[i] == m) pos.push_back(i - 2 * m);
    }
    return pos;
}
```

## 复杂度

O(n+m)

## 易错点

- next/f 数组含义和下标要统一。
- 模式串为空或长度 1 时注意边界。


---

# Manacher

> 页码：P058

## 作用

线性求所有回文半径。

## 核心思想

插入分隔符统一奇偶回文，维护最右回文区间。

## 标准代码

```cpp
struct Manacher
{
    int n;
    string s;
    vector<int> r;
    Manacher(string _s)
    {
        s = '#';
        for (auto c : _s)
        {
            s += c, s += '#';
        }
        n = s.size();
        r.resize(n);
        init();
    }
    void init()
    {
        for (int i = 0, c = 0; i < n; i++)
        {
            if (2 * c - i >= 0 && c + r[c] > i)
            {
                r[i] = min(r[2 * c - i], c + r[c] - i);
            }
            while (i - r[i] >= 0 && i + r[i] < n && s[i - r[i]] == s[i + r[i]])
            {
                r[i]++;
            }
            if (i + r[i] > c + r[c])
                c = i;
        }
    }
    int get_max()
    {
        int res = 0;
        for (int l : r)
        {
            res = max(res, l - 1);
        }
        return res;
    }
    bool check(int x, int y)
    {
        int nl = x * 2 + 1;
        int nr = y * 2 + 1;
        int mid = nl + nr >> 1;
        return r[mid] - 1 >= y - x + 1;
    }
};
```

## 复杂度

O(n)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# Trie树

> 页码：P059

## 作用

维护字符串集合，支持插入、查找、前缀统计。

## 核心思想

公共前缀共享节点，沿字符转移向下走。

## 标准代码

```cpp
struct Trie {
    vector<array<int, 26>> nxt;
    vector<int> cnt, pass;
    Trie() { init(); }
    void init() {
        nxt.assign(1, {});
        cnt.assign(1, 0);
        pass.assign(1, 0);
    }
    void insert(const string &s) {
        int p = 0;
        pass[p]++;
        for (char c : s) {
            int x = c - 'a';
            if (!nxt[p][x]) {
                nxt[p][x] = (int)nxt.size();
                nxt.push_back({});
                cnt.push_back(0);
                pass.push_back(0);
            }
            p = nxt[p][x];
            pass[p]++;
        }
        cnt[p]++;
    }
    int query(const string &s) const {
        int p = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!nxt[p][x]) return 0;
            p = nxt[p][x];
        }
        return cnt[p];
    }
    int prefix_count(const string &s) const {
        int p = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!nxt[p][x]) return 0;
            p = nxt[p][x];
        }
        return pass[p];
    }
};
```

## 复杂度

O(|S|)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 随机

> 页码：P060

## 作用

生成随机数或随机哈希种子。

## 核心思想

使用 chrono 作为种子初始化 mt19937/mt19937_64。

## 标准代码

```cpp
mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rand_ll(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng64);
}
```

## 复杂度

O(1)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 异或哈希

> 页码：P061

## 作用

集合/状态随机哈希，常用于无序集合比较。

## 核心思想

给元素随机权值，集合哈希用异或维护。

## 标准代码

```cpp
using u64 = unsigned long long;

// 使用高精度时钟作为随机数种子，防止被针对性的测试数据 hack
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// 获取一个随机的 64 位整数
u64 get_random() {
    return rng();
}
```

## 复杂度

O(1) 更新

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。


---

# 指数哈希

> 页码：P062

## 作用

把数值映射到指数形式哈希，适合多重集合差分。

## 核心思想

用随机底数的幂表示元素，集合组合转为模运算。

## 标准代码

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

## 复杂度

O(log x)

## 易错点

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 复杂度

见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。

## 常见错误

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 相关联知识

[[ACM综合模板]]
[[随机]]
