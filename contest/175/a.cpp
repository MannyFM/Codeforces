
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
//#define fn "a"
#define F first
#define S second

char s[50];
int n;
int ans = -1;

int atoi(int l, int r)
{
	int x = 0;
	if ((s[l] == '0' && r != l) || r - l + 1 > 7)
		return -1;
	for (int i = l; i <= r; i++)
		x = x * 10 + (s[i] - '0');
	if (x > int(1e6))
		return -1;
	return x;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	n = int(strlen(s + 1));
	if (n > 21 || n < 3)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int a = atoi(1, i);
			int b = atoi(i + 1, j);
			int c = atoi(j + 1, n);
			if (a == -1  || b == -1 || c == -1)
				continue;
			printf("%d %d %d %d %d\n", a, b, c, i, j);
			ans = max(a + b + c, ans);
		}
	printf("%d", ans);
}
