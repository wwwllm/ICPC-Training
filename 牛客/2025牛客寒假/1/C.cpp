#include <bits/stdc++.h>
using namespace std;

int c[26];
bool cmp(int a, int b)
{
	return a > b;
}
void solve()
{
	memset(c, 0, sizeof(c));
	int n, k;
	char s;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		c[s - 'a']++;
	}
	int a = 0, b = 0;
	for (int i = 0; i < 26; i++)
	{
		a += (c[i] / 2);
		b += (c[i] % 2);
	}
	int x = a / k, y = a % k;
	if (b + 2 * y >= k)
	{
		cout << x * 2 + 1 << endl;
	}
	else
	{
		cout << x * 2 << endl;
	}
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
