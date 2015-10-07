
#include <bits/stdc++.h>

using namespace std;

ll n, x[1010], y[1010];

const double eps = 1e-8;

struct pt
{
	ll x, y, id;
	double at;
	pt()
	{
		x = y = id = 0;
		at = .0;
	}
	pt(ll a, ll b, ll i)
	{
		x = a, y = b;
		at = atan2(x, y);
		id = i;
	}
};

pt a[1010];

bool cmp(pt a, pt b)
{
	if (abs(a.at - b.at) <= eps)
	{
		if (a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
	return a.at - b.at < eps;
}

ll main ()
{								  
	freopen("hobby.in", "r", stdin);
	freopen("hobby.out", "w", stdout);
	cin >> n;
	ll X = ll(1e5) + 12, Y = ll(1e5) + 12;
	for(ll i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (y[i] < Y || (y[i] == Y && x[i] < X))
		{
			Y = y[i];
			X = x[i];
		}
	}
	
	for (ll i = 0; i < n; i++)
		a[i] = pt(x[i] - X, y[i] - Y, i + 1);
	
	sort(a, a + n, cmp);
	cout << n / 2 << '\n';
	for(ll i = 0; i + 1 < n; i += 2)
	{
		cout << a[i].id << " " << a[i + 1].id << '\n';
	}
}
