#include <bits/stdc++.h>
using namespace std;

// s[++top]=s[top-1]+c  是错的！！！

// x0:[l,r)
// 取mid=（l+r）>>1
// 目标判断x大于mid还是小于mid
// 找一个ci，使得当x0=mid时，xi+ci为n的倍数
// ci=((xi/n)+1)*n-sum-mid
// 若x(i+1)/n变大了说明x大于等于mid
int p[12] = {0}, sum[12] = {0};
void solve()
{
	int n;
	cin >> n;
	int l = 1, r = n, t = 0, top = 0, mid;
	while (l + 1 != r && t <= 10)
	{
		int c;
		mid = (l + r) >> 1;
		c = (p[t] + 1) * n - mid - sum[top];
		cout << "+ " << c << endl;
		sum[top + 1] = sum[top] + c;
		top++;
		fflush(stdout);
		cin >> p[++t];
		if (p[t] == p[t - 1] + 1)
			l = mid;
		else
			r = mid;
	}
	cout << "! " << l + sum[top] << endl;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	//	cin>>t;
	while (t--)
		solve();
	return 0;
}
