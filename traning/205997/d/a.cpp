
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
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int const mod = int(1e9) + 7, p = 31;
ll const mod2 = mod * 1ll * mod;
char s[maxn], t[maxn];
ll H[maxn], T[maxn];
ll p_pow[maxn];

ll get_h(ll * H, int l, int r)
{
	return (H[r] - H[l - 1] * p_pow[r - l + 1] + mod2) % mod;
}

void pre(ll * H, char * s)
{
	p_pow[0] = 1ll;
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		H[i] = (H[i - 1] * p + s[i] - 'a' + 1) % mod;
		p_pow[i] = (p_pow[i - 1] * p) % mod;
	}
//	for (int i = 0; i <= n; i++)
//		printf(I64 " ", H[i]);
//	puts("");
}

bool check(ll * H, int len, int n)
{
	ll h = get_h(H, 1, len);
//	printf("%d %d: " I64 " ", len, n, h);
	for (int i = len + 1; i + len - 1 <= n; i += len)
	{
//		printf(I64 " ", get_h(H, i, i + len - 1));
		if (get_h(H, i, i + len - 1) != h)
		{
//			puts("-");
			return 0;
		}
	}
//	puts("+");
	return 1;
}

void out(char * S, ll * h)
{
	string s = string(S + 1);
	int n = (int)s.length();
	for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++)
			printf("[%d %d] %s = " I64 "\n", l, r, s.substr(l, r - l + 1).c_str(), get_h(h, l + 1, r + 1));
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s\n%s", s + 1, t + 1);
	pre(H, s);
	pre(T, t);
	int n = strlen(s + 1), m = strlen(t + 1), ans = 0;
	int x = __gcd(n, m);
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i)
			continue;
		if (get_h(H, 1, i) == get_h(T, 1, i))
			if (check(H, i, n) && check(T, i, m))
			{
				ans++;
//				printf("%d ", i);
			}
		int j = x / i;
		if (i == j)
			continue;
		if (get_h(H, 1, j) == get_h(T, 1, j))
			if (check(H, j, n) && check(T, j, m))
			{
				ans++;
//				printf("%d ", j);
			}
	}
	printf("%d", ans);
}

