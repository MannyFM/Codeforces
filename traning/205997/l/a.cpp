
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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

int n, k;
int a[maxn], b[maxn];
ll ans;
char s[maxn];
vector <int> pos;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &k);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	pos.pb(0);
	for (int i = 1; i <= n; i++)
	{
		a[i] = s[i] == '1';
		b[i] = b[i - 1] + a[i];
		if (a[i])
			pos.pb(i);
	}
	pos.pb(n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i - 1] + k + 1 >= (int)pos.size())
			break;
		int l = pos[b[i - 1] + k], r = pos[b[i - 1] + k + 1];
		umax(l, i);
//		printf("%d : [%d %d)\n", i, l, r);
		ans += r - l;
	}
	printf(I64, ans);
}

