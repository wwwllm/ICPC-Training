const fs = require("fs");
const path = require("path");

const root = process.cwd();
const wikiRoot = path.join(root, "ACM知识库");
const outFile = path.join(root, "XCPC赛场Codebook.md");

const order = ["基础模板", "数据结构", "图论", "动态规划", "数学", "字符串", "杂项工具"];
const dirMap = {
  "数据结构": "数据结构",
  "图论": "图论",
  "动态规划": "动态规划",
  "数论": "数学",
  "字符串": "字符串",
  "计算几何": "数学",
  "杂项工具": "杂项工具",
};

const skip = new Set(["ACM综合模板", "最短路题目", "题单", "算法笔记模板(算法)", "Hall定理"]);

const pageMeta = {
  "Ubuntu ICPCOS": ["赛场 Linux 环境下一键编译运行当前题目文件。", "用脚本统一 g++ 参数、输出文件名和运行日志，减少手敲命令失误。", "编译 O(源文件大小)，运行按程序复杂度"],
  "位运算": ["快速查询整数二进制性质，如 popcount、前导零、后缀零和 2 的幂。", "优先使用 C++20 `<bit>` 标准函数；兼容时使用 GCC builtin。", "O(1)"],
  "向上向下取整": ["处理带负数的整数除法上取整和下取整。", "先按 C++ 截断除法求商，再根据余数和符号修正。", "O(1)"],
  "三分查找": ["在整数单峰函数上求最大/最小值位置或值。", "每次取两个三等分点缩小单峰区间，最后暴力扫小区间。", "O(log n * T_f)"],
  "广义二项式定理": ["处理负二项式展开和生成函数系数提取。", "用 C(-n,k)=(-1)^k C(n+k-1,k) 把负上标组合数转成普通组合数。", "预处理 O(n)，单次 O(1)"],
  "并查集": ["维护集合连通性，支持合并与查询两个点是否属于同一集合。", "父指针表示集合代表元，路径压缩与按大小合并保证近似常数复杂度。", "均摊 O(alpha(n))"],
  "可撤销并查集": ["支持合并集合并回滚到历史状态，常配合线段树分治。", "不用路径压缩，只记录每次成功合并前的状态，回溯时从栈中恢复。", "O(log n) 或近似 O(log n)"],
  "线段树": ["维护区间和、最值、区间修改等动态区间信息。", "递归拆分区间，节点保存可合并信息，懒标记延迟下传区间修改。", "单次 O(log n)，空间 O(n)"],
  "权值线段树": ["维护值域频次，支持排名、第 k 小、前驱后继等查询。", "在线段树上维护值域而非下标区间，节点保存该值域内数量。", "O(log V)"],
  "主席树": ["静态区间第 k 小和历史版本查询。", "每次修改复制根到叶的一条链，其他节点复用，区间信息用两个版本相减。", "建树 O(n log V)，查询 O(log V)"],
  "线段树分治": ["处理按时间区间生效的离线动态图/约束问题。", "把生存区间挂到时间线段树节点，DFS 时用可撤销结构维护当前状态。", "O(m log q * T)"],
  "线段树合并与分裂": ["合并/拆分动态开点线段树，常用于树上值域统计。", "递归合并左右儿子；分裂时按计数把指定前缀拆出。", "均摊 O(节点数)"],
  "莫队": ["离线处理区间查询，要求端点移动能快速维护答案。", "按块排序询问，让左右端点总移动距离降到约 O(n sqrt n)。", "O((n+m) sqrt n)"],
  "扫描线": ["处理矩形面积/周长并、区间覆盖长度等几何转数据结构问题。", "把二维事件按一维排序，另一维用线段树维护覆盖长度。", "O(n log n)"],

  "Dijkstra 算法": ["非负权图单源最短路，赛场默认使用堆优化版。", "每次取当前最短距离的点出堆，用它松弛出边，过期状态直接跳过。", "O((n+m) log n)"],
  "SPFA算法": ["有负权边时的单源最短路或负环判断，慎用于强数据。", "队列维护可能继续松弛其他点的点，只访问被影响的出边。", "最坏 O(nm)"],
  "Bellman–Ford 算法": ["有负权边、限制边数最短路、负环检测。", "重复对所有边松弛，第 n 轮仍可松弛说明存在可达负环。", "O(nm)"],
  "Floyd 算法": ["点数较小时求全源最短路。", "枚举中转点 k，逐步允许路径经过更多中转点。", "O(n^3)"],
  "Johnson 算法": ["稀疏图全源最短路，允许负权边但不能有负环。", "先求势能重标边权为非负，再对每个源点跑 Dijkstra。", "O(nm + n(m+n)log n)"],
  "差分约束": ["求解形如 xi-xj<=c 的不等式系统并判无解。", "把约束转为有向边，负环代表矛盾。", "通常 O(nm)"],
  "最小生成树": ["无向连通图选 n-1 条边使总权最小。", "Kruskal 按边权排序，用并查集跳过成环边。", "O(m log m)"],
  "Kruskal重构树": ["处理最小生成树上瓶颈路径、连通时间等问题。", "Kruskal 合并连通块时新建点，边权成为新点权值。", "O(m log m + n log n)"],
  "LCA": ["查询树上两个点最近公共祖先，支撑树上距离/路径问题。", "倍增预处理祖先，先拉平深度再同步上跳。", "预处理 O(n log n)，查询 O(log n)"],
  "重链剖分": ["把树上路径问题转成若干连续区间问题。", "重儿子优先编号，一条路径可拆成 O(log n) 段链上区间。", "O(log^2 n)"],
  "树直径": ["求树上最长简单路径。", "两次 DFS/BFS：任取点找最远点，再从最远点找最远距离。", "O(n)"],
  "树重心": ["找删除后最大连通块最小的点。", "DFS 统计子树大小并计算每个点作为根时的最大剩余块。", "O(n)"],
  "点分治": ["处理树上路径统计，尤其路径长度/点对计数。", "每次选重心分治，统计经过当前重心的路径贡献。", "O(n log n)"],
  "DSU on Tree": ["离线维护子树颜色/众数等信息。", "轻儿子信息清空，重儿子信息保留，再合并轻儿子贡献。", "O(n log n) 或 O(n)"],
  "强连通分量": ["有向图缩点、环结构分析。", "Tarjan 用 dfn/low 维护 DFS 栈，发现 SCC 根时弹栈。", "O(n+m)"],
  "点双连通分量": ["无向图点双、割点相关问题。", "Tarjan 维护边栈/low，遇到 low[v]>=dfn[u] 形成点双。", "O(n+m)"],
  "边双连通分量": ["无向图边双、桥相关问题。", "Tarjan 找桥，去桥后 DFS 染色得到边双。", "O(n+m)"],
  "圆方树": ["把仙人掌/点双结构转成树处理路径问题。", "原点和点双新建方点连边，图上双连通结构树化。", "O(n+m)"],
  "Dinic": ["最大流标准模板。", "BFS 建分层图，DFS 在分层图中用当前弧增广。", "一般 O(n^2m)"],
  "EK算法": ["最大流基础版，适合小图或教学核对。", "每次 BFS 找一条增广路并沿路增广。", "O(nm^2)"],
  "费用流": ["最小费用最大流、费用最优匹配/分配。", "在残量网络中不断找最短费用增广路。", "O(F * m log n) 视实现而定"],

  "01背包问题": ["每个物品最多选一次的容量最优化。", "一维 dp 时容量倒序，避免同一物品被重复使用。", "O(nV)"],
  "完全背包问题": ["每个物品可选无限次的容量最优化。", "一维 dp 时容量正序，让当前物品可重复转移。", "O(nV)"],
  "多重背包问题": ["每种物品数量有限的背包模型。", "朴素枚举选几个；赛场大数据优先二进制优化。", "朴素 O(nVK)"],
  "多重背包问题的二进制优化": ["有限件物品转化为若干 01 物品。", "把数量拆成 1,2,4,... 的组合包，再按 01 背包倒序转移。", "O(V sum log cnt)"],

  "KMP算法": ["单模式串匹配、border、周期问题。", "失配时跳到最长相等前后缀位置，主串指针不回退。", "O(n+m)"],
  "扩展kmp（Z函数）": ["求每个后缀与原串的最长公共前缀。", "维护当前最右匹配区间，复用对称位置的 Z 值。", "O(n)"],
  "Manacher": ["线性求所有回文半径。", "插入分隔符统一奇偶回文，维护最右回文区间。", "O(n)"],
  "Trie树": ["维护字符串集合，支持插入、查找、前缀统计。", "公共前缀共享节点，沿字符转移向下走。", "O(|S|)"],
  "01-Trie": ["维护整数集合，查询最大异或值/第 k 小等。", "按二进制位建 Trie，最大异或时优先走相反位。", "O(log V)"],
  "AC自动机": ["多模式串匹配与出现次数统计。", "Trie 上建 fail 指针，匹配后沿 fail 树汇总贡献。", "O(文本长+模式总长)"],
  "后缀自动机": ["维护一个字符串所有子串的信息。", "在线扩展状态，link 表示最长可接受后缀。", "O(n)"],
  "字符串哈希": ["快速判断子串相等、去重、LCP 二分。", "前缀哈希支持 O(1) 计算任意子串哈希。", "预处理 O(n)，查询 O(1)"],

  "int128类定义": ["读写和计算超过 long long 的整数。", "用 __int128 存值，手写输入输出和常用运算。", "按位数 O(log n)"],
  "矩阵快速幂": ["线性递推、路径计数等矩阵转移快速幂。", "把转移写成矩阵乘法，用二进制快速幂加速。", "O(k^3 log n)"],
  "线性基": ["异或最大值、异或可表示性、异或空间秩。", "每个最高位保留一个基向量，高位优先消元。", "O(n log V)"],
  "快速傅里叶变换（FFT）": ["复数域卷积和多项式乘法。", "分治/迭代把系数表示转点值表示，逐点相乘后逆变换。", "O(n log n)"],
  "快速数论变换（NTT）": ["模意义下整数卷积。", "用模数原根替代复数单位根，避免浮点误差。", "O(n log n)"],
  "普通生成函数": ["组合计数和序列卷积建模。", "把计数序列写成形式幂级数，运算对应组合结构。", "视卷积实现而定"],
  "二项式反演": ["处理含组合数的求和反推。", "利用二项式变换互逆关系在两个序列间转换。", "O(n) 或 O(n log n)"],
  "计算几何": ["点、线、线段、圆的基础几何运算。", "用点积处理投影/角度，用叉积处理方向/面积/相交。", "基础操作 O(1)"],

  "异或哈希": ["集合/状态随机哈希，常用于无序集合比较。", "给元素随机权值，集合哈希用异或维护。", "O(1) 更新"],
  "指数哈希": ["把数值映射到指数形式哈希，适合多重集合差分。", "用随机底数的幂表示元素，集合组合转为模运算。", "O(log x)"],
  "随机": ["生成随机数或随机哈希种子。", "使用 chrono 作为种子初始化 mt19937/mt19937_64。", "O(1)"],
};

const codeOverride = {
  "Ubuntu ICPCOS": `#!/bin/bash
target=$1
src="\${target}.cpp"
g++ -std=gnu++20 -O2 -Wall -Wextra "$src" -o "$target" && \\
./"$target" 2>&1 | tee "\${target}.txt"`,
  "位运算": `#include <bit>

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
// __builtin_ctz(x), __builtin_ctzll(x)`,
  "向上向下取整": `long long floor_div(long long a, long long b) {
    long long q = a / b, r = a % b;
    if (r && ((a < 0) ^ (b < 0))) q--;
    return q;
}

long long ceil_div(long long a, long long b) {
    long long q = a / b, r = a % b;
    if (r && !((a < 0) ^ (b < 0))) q++;
    return q;
}`,
  "三分查找": `template<class F>
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
}`,
  "广义二项式定理": `const int MOD = 998244353;

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
};`,
  "基础模板": `#include <bits/stdc++.h>
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
}`,
  "Dijkstra 算法": `struct Dijkstra {
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
};`,
  "最小生成树": `struct DSU {
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
}`,
  "KMP算法": `vector<int> prefix_function(const string &s) {
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
}`,
  "字符串哈希": `using u64 = unsigned long long;
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
u64 StringHash::base = chrono::steady_clock::now().time_since_epoch().count() % (StringHash::MOD / 2) + StringHash::MOD / 4;`,
  "Trie树": `struct Trie {
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
};`,
  "01-Trie": `struct BinaryTrie {
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
};`,
  "随机": `mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rand_ll(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng64);
}`,
};

const manualPages = [
  {
    title: "Ubuntu ICPCOS",
    category: "基础模板",
    source: "ACM模板.md",
    lang: "shell",
    mistakes: ["先执行 chmod +x ./run.sh。", "文件名传入不带 .cpp 后缀。"],
  },
  {
    title: "基础模板",
    category: "基础模板",
    source: "手工整理",
    mistakes: ["多测时清空全局变量。", "关闭同步后不要混用 scanf/printf 和 cin/cout。"],
  },
  {
    title: "位运算",
    category: "基础模板",
    source: "ACM模板.md",
    mistakes: ["__builtin_clz/ctz 不能传 0。", "clz/ctz 的 int 和 long long 版本不要混用。"],
  },
  {
    title: "向上向下取整",
    category: "基础模板",
    source: "ACM模板.md",
    mistakes: ["除数不能为 0。", "负数除法不能直接用 (a+b-1)/b。"],
  },
  {
    title: "三分查找",
    category: "基础模板",
    source: "ACM模板.md",
    mistakes: ["只适用于单峰/单谷函数。", "整数三分最后要暴力扫剩余小区间。"],
  },
  {
    title: "广义二项式定理",
    category: "数学",
    source: "ACM模板.md",
    mistakes: ["预处理阶乘上界要覆盖 n+k。", "负上标组合数要处理 (-1)^k。"],
  },
];

const highTop = [
  "线段树", "并查集", "Dijkstra 算法", "LCA", "KMP算法",
  "字符串哈希", "Dinic", "费用流", "01背包问题", "完全背包问题",
  "多重背包问题的二进制优化", "最小生成树", "AC自动机", "快速数论变换（NTT）", "计算几何",
];

const wrongTop = [
  "线段树：pushdown 忘记清空 tag，区间开闭混用。",
  "Dijkstra：负权边误用，距离没开 long long。",
  "SPFA：vis 只表示在队列中，不表示最短路确定。",
  "背包：01 倒序，完全正序，多重拆包后倒序。",
  "可撤销并查集：不能路径压缩。",
  "字符串哈希：区间长度和 base/pow 下标写错。",
  "Floyd：k 必须在最外层，初始化 d[i][i]=0。",
  "KMP：pi/next 下标体系混用。",
  "网络流：反向边 i^1 编号必须成对维护。",
  "计算几何：eps 比较和叉积方向先统一。",
];

function read(p) {
  return fs.readFileSync(p, "utf8").replace(/\r\n/g, "\n");
}

function listMarkdown(dir) {
  const res = [];
  for (const ent of fs.readdirSync(dir, { withFileTypes: true })) {
    const p = path.join(dir, ent.name);
    if (ent.isDirectory()) res.push(...listMarkdown(p));
    else if (ent.name.endsWith(".md")) res.push(p);
  }
  return res;
}

function extractCategory(txt, file) {
  const m = txt.match(/^category:\s*(.+)$/m);
  if (m) return dirMap[m[1].trim()] || m[1].trim();
  const parent = path.basename(path.dirname(file));
  return dirMap[parent] || parent;
}

function extractSection(txt, heading) {
  const re = new RegExp(`## ${heading}\\n\\n([\\s\\S]*?)(?=\\n## |$)`);
  const m = txt.match(re);
  return m ? m[1].trim() : "";
}

function extractBullets(txt, heading) {
  return extractSection(txt, heading)
    .split("\n")
    .map((s) => s.trim())
    .filter((s) => s.startsWith("- "))
    .map((s) => s.slice(2).trim());
}

function codeBlocks(txt) {
  const out = [];
  const re = /```(?:cpp|c\+\+|c|shell)?\n([\s\S]*?)```/g;
  let m;
  while ((m = re.exec(txt))) out.push(m[1].trim());
  return out;
}

function selectCode(title, blocks) {
  if (codeOverride[title]) return codeOverride[title];
  if (!blocks.length) return "// No code template in source.";
  if (title === "Dijkstra 算法" && blocks.length >= 2) return blocks[1];
  if (title === "后缀自动机" && blocks.length >= 2) return blocks[0];
  if (title === "AC自动机" && blocks.length >= 2) return blocks[1];
  if (title === "线段树" && blocks.length >= 1) return blocks[0];
  return blocks[0];
}

function defaultMistakes(title) {
  const by = {
    "数据结构": ["确认下标和区间开闭。", "数组/节点池按最大数据范围预留。"],
    "图论": ["确认有向/无向和边权范围。", "距离、流量、费用按范围使用 long long。"],
    "动态规划": ["确认状态初始化。", "滚动数组注意循环方向。"],
    "数学": ["确认取模、逆元、溢出。", "特殊值 0/1 和负数要单测。"],
    "字符串": ["确认字符集大小。", "下标和区间 `[l,r)` 统一。"],
    "杂项工具": ["随机种子只初始化一次。", "不要让哈希值有未定义溢出。"],
    "基础模板": ["多测清空状态。", "读题确认 long long。"],
  };
  return by[title] || ["确认边界。", "提交前跑最小样例和极限样例。"];
}

function buildPage(entry, pageNo) {
  const meta = pageMeta[entry.title] || [
    `${entry.title} 的赛场模板。`,
    "保留最短可用实现，按题目条件直接套用。",
    "见代码主循环。",
  ];
  const mistakes = entry.mistakes || extractBullets(entry.raw || "", "常见错误");
  const bad = mistakes.length ? mistakes.slice(0, 3) : defaultMistakes(entry.category);
  return `# ${entry.title}

> 页码：P${String(pageNo).padStart(3, "0")}

## 作用

${meta[0]}

## 核心思想

${meta[1]}

## 标准代码

\`\`\`${entry.lang || "cpp"}
${entry.code.trim()}
\`\`\`

## 复杂度

${meta[2]}

## 易错点

${bad.map((x) => `- ${x}`).join("\n")}
`;
}

function toc(entries, pageOf) {
  const grouped = new Map();
  for (const cat of order) grouped.set(cat, []);
  for (const e of entries) {
    if (!grouped.has(e.category)) grouped.set(e.category, []);
    grouped.get(e.category).push(e);
  }
  let idx = 1;
  const lines = ["ACM Codebook"];
  for (const cat of order) {
    const arr = grouped.get(cat) || [];
    if (!arr.length) continue;
    const first = pageOf.get(arr[0].title);
    const last = pageOf.get(arr[arr.length - 1].title);
    lines.push(`${idx}. ${cat}  P${String(first).padStart(3, "0")}-P${String(last).padStart(3, "0")}`);
    arr.forEach((e, j) => lines.push(`   ${idx}.${j + 1} ${e.title}  P${String(pageOf.get(e.title)).padStart(3, "0")}`));
    idx++;
  }
  return lines.join("\n");
}

function build() {
  const files = listMarkdown(wikiRoot).filter((p) => path.dirname(p) !== wikiRoot);
  const entries = manualPages.map((page) => ({
    ...page,
    code: codeOverride[page.title],
    raw: "",
  }));

  for (const file of files) {
    const title = path.basename(file, ".md");
    if (skip.has(title)) continue;
    const raw = read(file);
    const category = extractCategory(raw, file);
    if (!order.includes(category)) continue;
    const blocks = codeBlocks(raw);
    const code = selectCode(title, blocks);
    if (!code || code.includes("No code template")) continue;
    entries.push({ title, category, source: path.relative(root, file).replaceAll("\\", "/"), raw, code });
    if (title === "Trie树") {
      entries.push({ title: "01-Trie", category: "字符串", source: "字符串/Trie树.md", raw, code: codeOverride["01-Trie"] });
    }
  }

  entries.sort((a, b) => {
    const ca = order.indexOf(a.category), cb = order.indexOf(b.category);
    return ca - cb || a.title.localeCompare(b.title, "zh-CN");
  });

  const frontPages = 4;
  const pageOf = new Map();
  entries.forEach((entry, i) => pageOf.set(entry.title, frontPages + i + 1));

  const body = [];
  body.push(`# XCPC赛场Codebook\n\n> 页码：P001\n\n## 首页：目录\n\n\`\`\`text\n${toc(entries, pageOf)}\n\`\`\``);
  body.push(`# 高频必带模板 TOP 15\n\n> 页码：P002\n\n${highTop.map((x, i) => `${i + 1}. ${x}${pageOf.has(x) ? `  P${String(pageOf.get(x)).padStart(3, "0")}` : ""}`).join("\n")}`);
  body.push(`# 最容易写错 TOP 10\n\n> 页码：P003\n\n${wrongTop.map((x, i) => `${i + 1}. ${x}`).join("\n")}`);
  body.push(`# 推荐使用顺序\n\n> 页码：P004\n\n1. 基础模板、读入输出、随机、int128。\n2. 数据结构：并查集、线段树、主席树、莫队。\n3. 图论：最短路、最小生成树、LCA、连通性、网络流。\n4. 动态规划：背包模型先扫循环方向。\n5. 字符串：KMP、哈希、Trie、AC自动机、SAM。\n6. 数学：矩阵快速幂、线性基、FFT/NTT、组合工具。\n`);

  for (const entry of entries) body.push(buildPage(entry, pageOf.get(entry.title)));
  fs.writeFileSync(outFile, body.join("\n\n---\n\n"), "utf8");
  console.log(`Generated ${entries.length} printable pages: ${outFile}`);
}

build();
