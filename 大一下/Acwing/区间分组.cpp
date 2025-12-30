#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct Range{
    int l, r;
    bool operator<(const Range &M)const{
        return l < M.l;
    }
} range[N];
int n;
signed main(){
    cin >> n;
    for (int i = 1; i <=n;i++)
        cin >> range[i].l >> range[i].r;
    sort(range + 1, range + 1 + n);
    priority_queue<int, vector<int>, greater<int>> h;
    for (int i = 1; i <=n;i++){
        auto [l,r] = range[i];
        if(h.empty()||l<=h.top())
            h.push(r);
        else {
            int rm = h.top();
            h.pop();
            h.push(r);
        }
    }
    cout << h.size() << endl;
    return 0;
}