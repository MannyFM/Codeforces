
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

set <string> s = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

bool Is(string x)
{
	return s.find(x) != s.end();
}

bool IsInt(string x)
{
	for (int i = 0; i < int(x.size()); i++)
		if (!('0' <= x[i] && x[i] <= '9'))
			return 0;
	return 1;
}

int n, ans;
string a[200];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (IsInt(a[i]))
			ans += atoi(a[i].c_str()) < 18;
		else
			ans += Is(a[i]);
	}
	printf("%d", ans);
}
