
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
#define F first
#define S second

char s[200], t[200];
char ans[2000];
int n;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s\n%s", s, t);
	n = int(strlen(s));
	int a;
	a = n - 1;
	while(a && s[a] == 'z')
		a--;
	for (int i = 0; i < a; i++)
		ans[i] = s[i];
	ans[a] = s[a] + 1;
	for (int i = a + 1; i < n; i++)
		ans[i] = 'a';
	ans[n] = 0;
	bool fl = 1;
	for (int i = 0; i < n; i++)
		if (ans[i] != t[i])
			fl = 0;
	if (fl)
		puts("No such string");
	else
		printf("%s", ans);
}