#include<bits/stdc++.h>
using namespace std;

const int N = 15, M = 1e3 + 10;
int n, m;
char s[M][N];
int dp[N][N];
int solve(char a[],char b[])
{
    int n = strlen(a + 1), m = strlen(b + 1);
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    return dp[n][m];
}
signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> (s[i] + 1);
    while(m--){
        int t;
        char b[N];
        cin >> b + 1 >> t;
        int ans = 0;
        for (int i = 1; i <= n;i++)if(solve(s[i],b)<=t)
                ans++;
        cout << ans << endl;
    }
        return 0;
}