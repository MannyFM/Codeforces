
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

char s[maxn];
string _s;
int k, good[30];
int cnt[maxn];

int const mod1 = inf, mod2 = 1000000207;
ll const md1 = inf * 1ll * inf, md2 = mod2 * 1ll * mod2;
int const p1 = 31, p2 = 83;
int p_pow1[maxn], p_pow2[maxn], h1[maxn], h2[maxn], n;
set <pii> se;

pii get_hash(int l, int r)
{
	return {(h1[r] - h1[l - 1] * 1ll * p_pow1[r - l + 1] + md1) % mod1, (h2[r] - h2[l - 1] * 1ll * p_pow2[r - l + 1] + md2) % mod2};
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	_s = string(s + 1);
	for (int i = 0; i < 26; i++)
	{
		char c;
		scanf(" %c", &c);
		good[i] = c == '1';
	}
	scanf("%d", &k);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		cnt[i] = cnt[i - 1] + !good[s[i] - 'a'];
	p_pow1[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		h1[i] = (h1[i - 1] * 1ll * p1 + (s[i] - 'a' + 1) + md1) % mod1;
		p_pow1[i] = (p_pow1[i - 1] * 1ll * p1 + md1) % mod1;
	}
	p_pow2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		h2[i] = (h2[i - 1] * 1ll * p2 + (s[i] - 'a' + 1) + md2) % mod2;
		p_pow2[i] = (p_pow2[i - 1] * 1ll * p2 + md2) % mod2;
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", h[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", p_pow[i]);
//	puts("");
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
		{
			pii H = get_hash(l, r);
			if (cnt[r] - cnt[l - 1] <= k)
				se.insert(H);
//			printf("[%d %d] %s %d\n", l, r, _s.substr(l - 1, r - l + 1).c_str(), H);
		}
	printf("%d", (int)se.size());
}

