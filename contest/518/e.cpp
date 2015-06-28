
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define LOCAL

int n, k, a[maxn];
vector <int> v[maxn];
char buf[20];

void fill(int st, int l, int r)
{
	int value = -inf;
	if (v[st][l] < 0 && v[st][r] < 0)
	{
		value = v[st][r] - 1;
		//printf("%d %d %d %d %d--\n", l, r, v[st][l], v[st][r], value);
		for (int i = r - 1; i >= l + 1; i--)
			v[st][i] = value, value--;
	}
	if (v[st][l] > 0 && v[st][r] > 0)
	{
		value = v[st][l] + 1;
		//printf("%d %d %d %d %d++\n", l, r, v[st][l], v[st][r], value);
		for (int i = l + 1; i <= r - 1; i++)
			v[st][i] = value, value++;
	}
	if (v[st][l] < 0 && v[st][r] > 0)
	{
		int sz = r - l - 1;
		value = max(v[st][l], - (sz - 1) / 2);
			//printf("%d %d %d %d %d-+1\n", l, r, v[st][l], v[st][r], value);
		for (int i = l + 1; i <= r - 1; i++)
			v[st][i] = value, value++;
	}
}

void f(int st)
{
	int l = 0, r = 1;
	//printf("%d:\n", st);
	while (l < int(v[st].size()) - 1)
	{
		r = l + 1;
		while (r <= (int)v[st].size() && (int)v[st][r] == inf)
			r++;
		//printf("%d %d %d %d\n", l, r, v[st][l], v[st][r]);
		if (r - l > v[st][r] - v[st][l])
		{
			puts("Incorrect sequence");
			exit(0);
		}
		fill(st, l, r);
		/*
		for (int i = l + 1; i < r; i += k)
			v[st][i] = -inf;
		*/
		l = r;
	}
	/*
	for (int i = 1; i < int(v[st].size()) - 1; i++)
		printf("%d ", v[st][i]);
	puts("");
	*/
}

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
		v[i].pb(-inf);
	for (int i = 0; i < n; i++)
	{
		scanf("\n%s", buf);
		a[i] = buf[0] == '?' ? inf : atoi(buf);
		v[i % k].pb(a[i]);
	}
	for (int i = 0; i < k; i++)
		v[i].pb(inf + 123);
	/*
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < int(v[i].size()); j++)
			if (j < int(v[i].size()))
				printf("%d ", v[i][j]);
		puts("");
	}
	puts("");
	
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");
	*/
	for (int st = 0; st < k; st++)
		f(st);
	/*
	puts("");
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j < int(v[i].size()) - 1; j++)
			printf("%d ", v[i][j]);
		puts("");
	}
	puts("");
	*/
	for (int i = 0; i < (n + k - 1) / k; i++)
		for (int j = 0; j < k; j++)
			if (i < int(v[j].size()) && v[j][i + 1] < inf + 123)
				printf("%d ", v[j][i + 1]);
}