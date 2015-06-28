
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

char _char[20];
int n;
int a[20], f[20];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	f[0] = f[1] = 1;
	for (int i = 2; i < 12; i++)
		f[i] = f[i - 1] * i;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("\n%c", _char + i);
		a[i] = _char[i] - '0';
	}
	multiset <int> s;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 4)
		{
			s.insert(3);
			s.insert(2);
			s.insert(2);
			continue;
		}
		if (a[i] == 6)
		{
			s.insert(3);
			s.insert(5);
			continue;
		}
		if (a[i] == 8)
		{
			s.insert(2);
			s.insert(2);
			s.insert(2);
			s.insert(7);
			continue;
		}
		if (a[i] == 9)
		{
			s.insert(2);
			s.insert(3);
			s.insert(3);
			s.insert(7);
			continue;
		}
		if (a[i] != 1 && a[i] != 0)
			s.insert(a[i]);
	}
	auto it = end(s);
	do
	{
		it--;
		printf("%d", *it);
	} while (it != begin(s));
}