
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
#define fn "c"
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

int n, k;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	if (n == 1)
	{
		puts(k ? "-1" : "1");
		return 0;
	}
	if (n / 2 > k)
	{
		puts("-1");
		return 0;
	}
	int delta = k - (n / 2) + 1;
	set <int> s;
	s.insert(delta * 2);
	s.insert(delta * 3);
	vector <int> v;
	v.push_back(delta * 2);
	v.push_back(delta * 3);
	int x = 1;
	for (int i = 2; i <= n / 2; i++)
	{
		while ((s.find(x) != s.end()) || (s.find(x + 1) != s.end()))
			x++;
		s.insert(x);
		s.insert(x + 1);
		v.push_back(x);
		v.push_back(x + 1);
	}
	while (s.find(x) != s.end())
		x++;
	if (n & 1)
		v.push_back(x);
	
	for (auto i : v)
		printf("%d ", i);
}