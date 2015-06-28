
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"

const int sz = 'z' - 'a' + 1;

int n;
int g[sz + 1][sz + 1];
int us[sz + 1];
string a[200];

vector <int> ans;	

void dfs(int v)
{
	us[v] = 1;
	for (int i = 0; i < sz; i++)
		if (g[v][i])
		{
			if (!us[i])
				dfs(i);
			if (us[i] == 1)
			{
				puts("Impossible");
				exit(0);
			}
		}
	us[v] = 2;
	ans.pb(v);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			for (int k = 0; k < int(a[i].size()); k++)
			{
				if (k == int(a[j].size()))
				{
					puts("Impossible");
					return 0;
				}
				if (a[i][k] == a[j][k])
					continue;
				g[a[i][k] - 'a'][a[j][k] - 'a'] = 1;
				break;
			}
		}
	/*
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
		if (g[i][j])
			printf("(%c %c) ", i + 'a', j + 'a');
	puts("");
	*/
	for (int i = 0; i < sz; i++)
		if (!us[i])
			dfs(i);
	reverse(begin(ans), end(ans));
	for (int i = 0; i < int(ans.size()); i++)
		printf("%c", ans[i] + 'a');
}