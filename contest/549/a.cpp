
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
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n, m;
char s[55][55];
int ans;
map <char, int> face;
string _face;

bool check(int i, int j)
{
	map <char, int> cur;
	cur[s[i][j]]++;
	cur[s[i + 1][j]]++;
	cur[s[i][j + 1]]++;
	cur[s[i + 1][j + 1]]++;
	return (cur == face);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	face['f']++;
	face['a']++;
	face['c']++;
	face['e']++;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			ans += check(i, j);
	printf("%d", ans);
}

