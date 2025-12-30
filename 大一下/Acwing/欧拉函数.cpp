#include<bits/stdc++.h>
using namespace std;

// φ(n):表示1~n中与n互质的个数
// ϕ(N)=N*(1-1/p1)*(1-1/p2)……
//证明：容斥原理
//在1~n中去掉p1,p2,p3,……pk的所有倍数
signed main()
{
    int n;
    cin >> n;
    while(n--){
        int ans;
        int x;
        cin >> x;
        ans = x;
        for (int i = 2; i <= x / i;i++){
            if(x%i==0){
                ans = ans / i * (i - 1);
                while(x%i==0)
                    x /= i;
            }
        }
        if (x > 1)
            ans = ans / x * (x- 1);
        cout << ans << endl;
    }
    return 0;
}