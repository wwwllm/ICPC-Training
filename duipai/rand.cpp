#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int randINT(int l, int r)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(l, r);
	return distrib(gen);
}

signed main()
{
	int n = randINT(1, 10), k = randINT(1, 10);
	cout << n << ' ' << k << '\n';
	for (int i = 0; i < n; i++)
		cout << randINT(1, 100) << ' ';
	cout << '\n';
	string s;
	for (int i = 0; i < k; i++)
	{
		int op = randINT(0, 1);
		if (op == 0)
			cout << 's';
		else
			cout << 'p';
	}
	cout << '\n';
	return 0;
}