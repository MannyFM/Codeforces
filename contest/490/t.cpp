
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

int a1, b1, a2, b2;
mii d1, d2;

void calc(int x, mii &d)
{
	for (int i = 2; i * i <= x; i++)
		while (x % i == 0)
			d[i]++, x /= i;
	if (x > 1)
		d[x]++;
}

void change(int & a, int & b, int d)
{
	int g = __gcd(a, d);
	a /= g;
	d /= g;
	g = __gcd(b, d);
	b /= g;
	d /= g;
}

void ch(int & a, int & b, int d)
{
	while (d && a % 3 == 0)
		a /= 3, a *= 2, d--;
	while (d && b % 3 == 0)
		b /= 3, b *= 2, d--;
}

int main()
{
	int a1, b1, a2, b2;
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
	
}
