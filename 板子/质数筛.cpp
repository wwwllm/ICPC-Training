// 质数筛
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int prime[maxn], ans = 0;
void sieve(int n, bool a[])
{ // 普通筛:时间复杂度：O(nlogn)
	a[0] = a[1] = 1;
	memset(a, 0, sizeof(bool) * n + 1);
	for (int i = 2; i * i <= n; i++)
	{
		if (a[i] == 0)
		{
			prime[++ans] = i;
		}
		for (int j = i << 1; j <= n; j += i)
		{
			a[j] = 1;
		}
	}
}
void Eratothenes_sieve(int n, bool a[])
{ // 埃氏筛:时间复杂度：O(nloglogn)
	// 寻找不超过n的所有质数，数组a来存放结果，a[i]==0表示质数
	a[0] = a[1] = 1;
	memset(a, 0, sizeof(bool) * n + 1);
	for (int i = 2; i * i <= n; i++)
	{
		if (a[i] == 0)
		{
			prime[++ans] = i;
			for (int j = i << 1; j <= n; j += i)
			{
				a[j] = 1;
			}
		}
	}
}
void Eratothenes_sievepro(int n, bool a[])
{ // 埃氏筛优化
	a[0] = a[1] = 1;
	memset(a, 0, sizeof(bool) * n + 1);
	for (int i = 2; i * i <= n; i++)
	{
		if (a[i] == 0)
			prime[++ans] = i;
		for (int j = 0; j <= ans && prime[j] * i <= n; j++)
		{
			a[prime[j] * i] = 1;
		}
	}
}
void Euler_sieve(int n, bool a[])
{ // 欧拉筛 ：时间复杂度：O(n)
	a[0] = a[1] = 1;
	memset(a, 0, sizeof(bool) * n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0)
			prime[++ans] = i;
		for (int j = 1; prime[j] <= n / i; j++)
		{
			a[prime[j] * i] = 1;
			if (i % prime[j] == 0)
				break; // 保证prime[j]为最小质因数
		}
	}
}
int main()
{
	int n;
	return 0;
}
