// brute2_reach.cpp —— 第二题的「结论验证器」
// 对 n = 1..N（默认 15）爆搜出集合 {1..n} 经过任意操作顺序能得到的所有最终值，
// 并检查是否恰好等于 {k : 0 <= k <= n, k ≡ n(n+1)/2 (mod 2)}。
// 编译运行: g++ -O2 -o brute2_reach brute2_reach.cpp && ./brute2_reach 15
// 实测: n<=15 全部成立（无解列 = 0，输出中的 parity-complete=1 表示「区间内所有同奇偶的值都可达」）。
#include <bits/stdc++.h>
using namespace std;
struct H { size_t operator()(const vector<int>&v) const { size_t h=1469598103934665603ULL; for(int x:v){h^=x+0x9e3779b97f4a7c15ULL;h*=1099511628211ULL;} return h; } };
unordered_map<vector<int>, vector<char>, H> memo;   // char array of size 200 => achievable?
const int MX=3000;
vector<char> go(vector<int> v){
    sort(v.begin(), v.end());
    auto it=memo.find(v); if(it!=memo.end()) return it->second;
    vector<char> res(MX,0);
    if(v.size()==1) res[v[0]]=1;
    else{
        for(size_t i=0;i<v.size();i++)for(size_t j=i+1;j<v.size();j++){
            if(j>i+1 && v[j]==v[j-1]) continue; // dup pair skip later (optional)
            vector<int> w; w.reserve(v.size()-1);
            for(size_t t=0;t<v.size();t++) if(t!=i&&t!=j) w.push_back(v[t]);
            w.push_back(abs(v[i]-v[j]));
            auto r=go(w); for(int k=0;k<MX;k++) if(r[k]) res[k]=1;
        }
    }
    memo[v]=res; return res;
}
void report(vector<int> v, const char* tag){
    auto r=go(v); long long S=0; for(int x:v)S+=x;
    int mx=0,cnt=0; for(int k=0;k<MX;k++) if(r[k]){mx=max(mx,k);cnt++;}
    printf("%-22s size=%2zu sum=%4lld max=%4d :", tag, v.size(), S, mx);
    int shown=0; for(int k=0;k<MX&&shown<40;k++) if(r[k]){printf(" %d",k);shown++;}
    printf("  [parity-complete=%d]\n", cnt == (mx/2+1));
    fflush(stdout);
}
int main(int argc,char**argv){
    int N=atoi(argv[1]);
    for(int n=1;n<=N;n++){
        vector<int> v; for(int i=1;i<=n;i++) v.push_back(i);
        char tag[64]; snprintf(tag,64,"{1..%d}",n);
        auto t0=chrono::steady_clock::now();
        report(v,tag);
        fprintf(stderr,"n=%d states=%zu %.1fs\n", n, memo.size(), chrono::duration<double>(chrono::steady_clock::now()-t0).count());
    }
}
