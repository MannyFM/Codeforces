
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

int n, x[maxn], y[maxn];
int us[maxn], sz;

void dfs(int v)
{
	us[v] = 1;
	for (int i = 0; i < n; i++)
		if ((x[i] == x[v] || y[i] == y[v]) && !us[i])
			dfs(i);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x + i, y + i);
	for (int i = 0; i < n; i++)
		if (!us[i])
			dfs(i), sz++;
	printf("%d", sz - 1);
}