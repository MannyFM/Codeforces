
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
#define fn "tiv"
#define NO {puts("No"); return 0;}

vector <int> g[12], ans;
int n, clr[12], N[12];
char s[12][12];

bool dfs(int v)
{
	cerr << v << " ";
	clr[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (clr[to] == 2)
			continue;
		if (clr[to] == 1)
			return 1;
		if (clr[to] == 0)
			if (dfs(to))
				return 1;
	}
	clr[v] = 2;
	ans.pb(v);
	return 0;
}

int ANS[11];
bool cant[11];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		N[i] = strlen(s[i]);
		cant[s[i][0] - 'a'] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (N[i - 1] > N[i])
			NO
		if (N[i - 1] < N[i])
			continue;
		int j = 0;
		while (j < N[i - 1] && s[i - 1][j] == s[i][j])
			j++;
		if (j == N[i])
			NO
		g[s[i - 1][j] - 'a'].pb(s[i][j] - 'a');
	}
	/*
	for (int i = 0; i < 10; i++)
		for (int x : g[i])
			printf("%c->%c\n", i + 'a', x + 'a');
	*/
	for (int i = 0; i < 10; i++)
		if (!clr[i] && dfs(i))
		{
			//printf("!%c ", i + 'a');
			NO;
		}
	int cur = 0;
	/*
	for (int i = 0; i < 10; i++)
		printf("%d ", cant[i]);
	puts("");
	*/
	for (int i = 9; i >= 0; i--)
	{
		int x = ans[i];
		if (!cur && cant[x])
			cur++;
		ANS[x] = cur++;
		cur %= 10;
		//printf("ans[%d/%c] = %d\n", x, x + 'a', ANS[x]);
	}
	for (int i = 0; i < 10; i++)
		if (cant[i] && !ANS[i])
			NO;
	puts("Yes");
	for (int i = 0; i < 10; i++)
		printf("%d ", ANS[i]);
}
