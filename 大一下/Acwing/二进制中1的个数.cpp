#include <bits/stdc++.h>
using namespace std;

// 位运算的常见操作：
// x都第k位数字==(x>>k&1)
// lowbit操作：返回x最后一位1
//     eg:x=1010----lowbit(x)=10;x=101000---lowbit(x)=1000
//lowbit(x)=x&-x
//证：c++中-x=~x+1(~x为取反)
int lowbit(int x){
    return x & -x;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int ans = 0;
        while (x)
            x -= lowbit(x),ans++;
        cout << ans << ' ';
    }
    return 0;
}