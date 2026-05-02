---
tags:
  - 数据结构
  - 字符串
Time: 2026-03-16T22:19:00
---

# 定义
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
### 例题链接
[Luogu P8306 【模板】字典树](https://www.luogu.com.cn/problem/P8306)

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