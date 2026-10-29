#include<bits/stdc++.h>
using namespace std;

//区间dp:一般状态表示为某一个区间
const int N = 310,INF=1e9;
int n;
int dp[N][N], s[N];
signed main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i], s[i] += s[i - 1];
    for (int len = 2; len <= n;len++){
        for (int l = 1; l + len - 1 <= n;l++){
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l ; k < r;k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}