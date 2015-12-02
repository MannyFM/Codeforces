
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
//#define fn

char s[60][60];
char us[60][60];
int n, m;

void dfs(int i, int j)
{
	if (us[i][j])
		return;
	us[i][j] = 1;
	if (i == 1 && j == m)
	{
		puts("YES");
		exit(0);
	}
	for (int x = -1; x <= 1; x++)
		for (int y = 0; y <= 1; y++)
			if (s[i + x][j + y] == '.')
				dfs(i + x, j + y);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	n = 2;
	scanf("%d",&m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	dfs(1, 1);
	puts("NO");
}

