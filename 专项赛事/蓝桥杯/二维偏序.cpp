#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int lowbit(int x){
    return x & -x;
}
vector<PII> a;
vector<int> b;
struct tre{
    int t[2*N];
    void add(int pos,int x){
        for (int i = pos; i<=2*N;i+=lowbit(i))
            t[i] += x;
    }
    int query(int x){
        int ans = 0;
        for (int i = x; i;i-=lowbit(i))
            ans += t[i];
        return ans;
    }
} tr;
int find(int x){
    int l = -1, r = b.size();
    while(l+1!=r){
        int mid = l + r >> 1;
        if(b[mid]>=x)
            r = mid;
        else
            l = mid;
    }
    return r + 1;
}
signed main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        b.push_back(y);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    sort(a.begin(), a.end());
    int ans = 0;
    for(auto [x,y]:a){
        int pos = find(y);
        ans += tr.query(pos);
        tr.add(pos, 1);
    }
    cout << ans << endl;
    return 0;
}