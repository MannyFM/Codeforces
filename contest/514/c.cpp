
#include <bits/stdc++.h>

using namespace std;

#define maxn int(3e5 + 12)
#define mod (long long)(1e18 + 7)
#define ll long long

vector <ll> se;

const int p = 7;

string s;
int n, m;

ll calc()
{
	int P = 1;
	ll hash = 0;
	for (int i = 0; i < int(s.size()); i++)
	{
		hash = (hash + (s[i] - 'a' + 1) * P) % mod;
		P *= p;
	}
	return hash;
}

bool find(ll a)
{
	int l = -1, r = int(se.size());
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (se[m] == a)
			return 1;
		if (se[m] > a)
			r = m;
		else
			l = m;	
	}
	//printf("%I64d %I64d %I64d\n", a, se[l], se[r]);
	return se[l] == a || se[r] == a;
}

bool check(int j)
{
	char old = s[j];
	for (char q = 'a'; q <= 'c'; q++)
		if (q != old)
		{
			//printf("%d %c ", j, q);
			s[j] = q;
			int ok = find(calc());
			if (ok)
				return 1;
		}
	s[j] = old;
	return 0;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		se.push_back(calc());
		//printf("%I64d\n", calc());
		//puts("");
	}
	sort(begin(se), end(se));
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		int ok = 0;
		for (int j = 0; j < int(s.size()); j++)
		{
			if (check(j))
			{
				ok = 1;
				break;
			}
			//puts("");
		}
		puts(ok ? "YES" : "NO");
	}
}