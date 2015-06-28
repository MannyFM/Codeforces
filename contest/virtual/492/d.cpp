
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 10)
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define ll long long

int n, a[maxn], x, y;
vector <string> v;

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	int s = x + y;
	int cx = 0, cy = 0;
	while (cx < x && cy < y)
	{
		if ((ll)(cx + 1) * y > (ll)(cy + 1) * x)
			v.pb("Vova"), cy++;
		
		if ((ll)(cx + 1) * y < (ll)(cy + 1) * x)
			v.pb("Vanya"), cx++;
		
		if ((ll)(cx + 1) * y == (ll)(cy + 1) * x)
		{
			v.pb("Both"), cy++;
			v.pb("Both"), cx++;
		}

	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cout << (v[(a[i] - 1) % (x + y)]) << '\n';
	}
}