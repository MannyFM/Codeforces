
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "b"
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

mii d;

int n, a[maxn];

void f(int a, int b)
{
	if (b == 1)
		return;
	vector <int> v;
	int x = b;
	while (x > 0)
	{
		v.pb(x & 1);
		x /= 2;
	}
	d[a] = 0;
	for (int i = 0; i < int(v.size()); i++)
		if (v[i])
			d[a + i]++;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), d[a[i]]++;
	/*
	for (auto i : d)
		printf("%d %d\n", i.f, i.s);
	puts("");
	*/
	for (auto it = begin(d); it != end(d); it++)
		f(it -> f, it -> s);
	/*
	for (auto i : d)
		printf("%d %d\n", i.f, i.s);
	*/
	int last = -1;
	int ans = 0;
	for (auto i : d)
	{
		if (i.s)
		{
			ans += (i.f - last - 1);
			last = i.f;
		}
	}
	printf("%d", ans);
}