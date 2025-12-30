#include <bits/stdc++.h>
#define MAXN 100050
using namespace std;

//主要思想：分治
int n;
int t[MAXN];
void solve(int l, int r)
{
	if (l >= r)
		return;
	int mid = t[(l + r) >> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do
			i++;
		while (t[i] < mid);
		do
			j--;
		while (mid < t[j]);
		if (i < j)
			swap(t[i], t[j]);
	}
	solve(l, j);
	solve(j + 1, r);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	solve(1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << t[i] << ' ';
	}
	return 0;
}
