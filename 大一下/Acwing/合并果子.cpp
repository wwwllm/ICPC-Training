#include<bits/stdc++.h>
using namespace std;

signed main(){
    priority_queue<int, vector<int>, greater<int>> h;
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        h.push(x);
    }
    int ans = 0;
    while(h.size()!=1){
        int a = h.top();
        h.pop();
        int b = h.top();
        h.pop();
        ans += a + b;
        h.push(a + b);
    }
    cout << ans << endl;
    return 0;
}