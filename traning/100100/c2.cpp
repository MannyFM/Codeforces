
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(3e5 + 12)
#define mod (int)(1e9)

int n, a[maxn], last = -1;
set <int> s;
char c[maxn];

int main()
{
	freopen("next.in", "r", stdin);
	freopen("next.out", "w", stdout);
	cin >> n;
	cin >> c[0] >> a[0];
	if (c[0] == '?')
	{
		set <int> :: iterator it = s.lower_bound(a[0]);
		if (it != s.end())
			last = *it;
		else
			last = -1;
		printf("%d\n", last);
	}
	if (c[0] == '+')
	{
		s.insert(a[0]);
	}
	for (int i = 1; i < n; i++)
	{
		cin >> c[i] >> a[i];
		if (c[i] == '?')
		{
			set <int> :: iterator it = s.lower_bound(a[i]);
			if (it != s.end())
				last = *it;
			else
				last = -1;
			printf("%d\n", last);
		}
		if (c[i] == '+')
		{
			if (c[i - 1] == '?')
				s.insert((a[i] + last) % mod);
			else
				s.insert(a[i]);
		}
	}
}