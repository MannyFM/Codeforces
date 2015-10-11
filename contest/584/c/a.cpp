#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

char s[maxn], t[maxn], z[maxn];
int n, T, same;

int f(char * s, char * t)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += s[i] != t[i];
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &T);
	scanf("%s %s", s, t);
	same = n - T;
	for (int i = 0; i < n; i++)
		if (same && s[i] == t[i])
		{
			z[i] = s[i];
			same--;
		}
	if (same)
	{
		int b = same;
		for (int i = 0; i < n; i++)
			if (b && !z[i])
			{
				z[i] = s[i];
				b--;
			}
		if (b)
		{
			puts("-1");
			return 0;
		}
		b = same;
		for (int i = 0; i < n; i++)
			if (b && !z[i])
			{
				z[i] = t[i];
				b--;
			}
		if (b)
		{
			puts("-1");
			return 0;
		}
	}
	/*
	for (int i = 0; i < n; i++)
		putchar(z[i] ? z[i] : '!');
	puts("");
	*/
	for (int i = 0; i < n; i++)
		if (!z[i])
		{
			z[i] = 'a';
			if (z[i] == s[i] || z[i] == t[i])
				z[i]++;
			if (z[i] == s[i] || z[i] == t[i])
				z[i]++;
		}
	/*
	for (int i = 0; i < n; i++)
		putchar(z[i] ? z[i] : '!');
	puts("\n\n");
	*/
	int q = f(s, z);
	if (q == f(t, z) && q == T)
	{
		puts(z);
		return 0;
	}
	puts("-1");
}
