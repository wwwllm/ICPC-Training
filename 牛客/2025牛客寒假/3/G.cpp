#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n, K;
	cin >> n >> K;
	int vcnt = 0;
	int l = -1, r = n;
	auto cmp = [&](int x) -> array<int, 2>
	{
		int ll = 1, rr, cnt = 0, ans = 0;
		while (ll <= n)
		{
			int k = n / ll;
			rr = n / k;
			int a = n % ll;
			if (a < x)
			{
				ll = rr + 1;
				continue;
			}
			int len = min((a - x) / k + 1, rr - ll + 1);
			cnt += len;
			ans += (a * 2 - k * (len - 1)) * len / 2;
			ll = rr + 1;
		}
		return {cnt, ans};
	};
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		auto [res, x] = cmp(mid);
		if (res >= K)
			l = mid;
		else
		{
			r = mid;
			vcnt = res;
		}
	}
	int ans = max(0LL, (K - vcnt) * (r - 1));
	auto [x, sum] = cmp(r);
	cout << ans + sum << '\n';
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}