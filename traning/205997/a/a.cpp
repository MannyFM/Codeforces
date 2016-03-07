
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(6e5 + 12);
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

ll const p = 5, mod = ll(1e15) + 7;
ll p_pow[maxn], H[maxn];

void calc(char * s, int n)
{
	p_pow[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		H[i] = (H[i - 1] * p + s[i] - 'a' + 1) % mod;
		p_pow[i] = (p_pow[i - 1] * p) % mod;
	}
}

ll get_h(int l, int r)
{
	if (l > r)
		return -1;
	ll h = (H[r] - H[l - 1] * p_pow[r - l + 1]) % mod;
	while (h < 0)
		h += mod;
	return h;
}

int n, m;
int next[4][maxn], last;
bool End[maxn];
char s[maxn];
set <pair<ll, char>> hs[maxn];

void add(char * s)
{
	int n = strlen(s + 1);
	calc(s, n);
	int v = 0;
//	puts(s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (!next[s[i] - 'a'][v])
			next[s[i] - 'a'][v] = ++last;
		if (i + 1 <= n)
		{
			hs[v].insert({get_h(i + 1, n), s[i]});
//			printf("%d+ " I64 "\n", v, get_h(i + 1, n));
		}
		v = next[s[i] - 'a'][v];
	}
	End[v] = 1;
}

bool has(char * s)
{
	int n = strlen(s + 1);
	calc(s, n);
	int v = 0;
	for (int i = 1; i < n; i++)
	{
		ll h = get_h(i + 1, n);
		auto it = hs[v].lower_bound({h, 0});
		if (it != hs[v].end() && it -> F == h)
		{
			if (it -> S != s[i])
			{
//				printf("v:%d " I64 " %c\n", v, it -> F, it -> S);
				return 1;
			}
			it++;
			if (it != hs[v].end() && it -> F == h && it -> S != s[i])
			{
//				printf("v:%d " I64 " %c\n", v, it -> F, it -> S);
				return 1;
			}
		}
		if (!next[s[i] - 'a'][v])
			return 0;
		v = next[s[i] - 'a'][v];
	}
	for (int i = 0; i < 3; i++)
		if (i != s[n] - 'a' && next[i][v] && End[next[i][v]])
			return 1;
	return 0;
}

void out(int v)
{
	printf("%d %c: ", v, End[v] ? '+' : '-');
	for (auto x : hs[v])
		printf("(" I64 " %c) ", x.F, x.S);
	puts("");
	for (int i = 0; i < 3; i++)
		if (next[i][v])
			out(next[i][v]);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		add(s);
	}
//	out(0);
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", s + 1);
		puts(has(s) ? "YES" : "NO");
	}
}

