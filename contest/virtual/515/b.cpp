
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
#define fn "a"
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

int us[200][200];
int n, m, a[200], b[200];
int N, M, A[200], B[200];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", A + i), a[A[i]]++;
	scanf("%d", &M);
	for (int j = 0; j < M; j++)
		scanf("%d", B + j), b[B[j]]++;
	/*
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");
	for (int j = 0; j < m; j++)
		printf("%d ", b[j]);
	puts("");
	*/
	int i = 0;
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int l = 0; l < n; l++)
			for (int r = 0; r < m; r++)
				us[l][r] = 0;
		while (!us[i % n][i % m])
		{
			int l = i % n, r = i % m;
			//printf("%d %d %d %d\n", l, r, a
			if (a[l] ^ b[r])
			{
				ok = 1;
				a[l] = b[r] = 1;
			}
			us[l][r] = 1;
			i++;
		}
	}
	ok = 1;
	for (int i = 0; i < n; i++)
		if (!a[i])
			ok = 0;
	for (int j = 0; j < m; j++)
		if (!b[j])
			ok = 0;
	puts(ok ? "Yes" : "No");
}
