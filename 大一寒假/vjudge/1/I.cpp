#include <bits/stdc++.h>
#define int long long
using namespace std;

struct dian
{
	int pos, num;
};
bool cmp(dian a, dian b)
{
	return a.num > b.num;
}
void solve()
{
	int n, m;
	cin >> m >> n;
	vector<int> ma(n);
	vector<vector<dian>> p(m, vector<dian>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> p[i][j].num;
			p[i][j].pos = j;
			ma[j] = max(ma[j], p[i][j].num);
		}
	}
	int max2 = 0, max1p = -1, max2p = -1;
	for (int i = 0; i < m; i++)
	{
		vector<dian> temp(n);
		for (int j = 0; j < n; j++)
		{
			temp[j] = p[i][j];
		}
		sort(temp.begin(), temp.end(), cmp);
		if (temp[1].num > max2)
		{
			max2 = temp[1].num;
			max2p = temp[1].pos;
			max1p = temp[0].pos;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i != max2p && i != max1p)
		{
			max2 = min(max2, ma[i]);
		}
	}
	cout << max2 << endl;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
