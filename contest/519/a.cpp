
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
#define F first
#define S second

char a[10][10];
int f[2];

void F(char q)
{
	if (q == '.' || q == 'K' || q == 'k')
		return;
	int fl = !('a' <= q && q <= 'z');
	if (fl)
		q = q - 'A' + 'a';
	if (q == 'q')
		f[fl] += 9;
	if (q == 'r')
		f[fl] += 5;
	if (q == 'b' || q == 'n')
		f[fl] += 3;
	if (q == 'p')
		f[fl]++;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int i = 0;
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	scanf("%s", a[i++]);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		F(a[i][j]);
	if (f[0] == f[1])
		puts("Draw");
	else
	puts(f[0] < f[1] ? "White" : "Black");
}