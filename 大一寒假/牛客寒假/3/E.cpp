#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e10;
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, k;
	cin >> N >> k;
	vector<int> p, q;
	for (int i = 1; i <= N; i++)
	{
		int x, v;
		cin >> x >> v;
		if (v == -1)
			q.push_back(x);
		else
			p.push_back(x);
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	int n = p.size(), m = q.size();
	auto cmp = [&](int x) -> bool
	{
		int ans = 0;
		for (int i = 0, p1 = 0, p2 = 0; i < n; i++)
		{

			while (p1 < m && q[p1] < p[i])
				p1++;
			while (p2 < m && q[p2] <= p[i] + x)
				p2++;
			ans += p2 - p1;
		}
		// cout << x << ' ' << ans << '\n';
		return ans >= k;
	};
	int l = 0, r = INF;
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		if (cmp(mid))
			r = mid;
		else
			l = mid;
	}
	if (r > INF / 2)
		cout << "No\n";
	else
	{
		double t = 1.0 * r / 2;
		cout << "Yes\n";
		cout << fixed << setprecision(6) << t << '\n';
	}
	return 0;
}