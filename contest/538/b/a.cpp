
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

char s[10];
int cnt[10], x;

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[n - i + 1] = s[i] - '0';
		x += s[i] - '0';
	}
	vector <int> v;
	while (x > 0)
	{
		int y = 0;
		for (int i = n; i > 0; i--)
		{
			y *= 10;
			if (cnt[i])
			{
				cnt[i]--;
				x--;
				y++;
			}
		}
		v.pb(y);
	}
	printf("%d\n", v.size());
	for (int x : v)
		printf("%d ", x);
}
