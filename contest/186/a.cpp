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
#define NO {puts("NO"); return 0;}
//#define fn ""

char s[maxn], t[maxn];
int n, m;
vector <int> pos;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	if (n != m)
		NO;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i])
			pos.pb(i);
	if (pos.size() != 2)
		NO;
	if (s[pos[0]] == t[pos[1]] && s[pos[1]] == t[pos[0]])
		puts("YES");
	else
		NO;
}
