
#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
	vector <int> v;
	while (x > 0)
	{
		if (x % 10)
			v.push_back(x % 10);
		x /= 10;
	}
	int ans = 0;
	reverse(begin(v), end(v));
	for (auto i : v)
		ans = ans * 10 + i;
	return ans;
}

int main()
{
	int a[2], b[2], c[2];
	scanf("%d%d", a, b);
	c[0] = a[0] + b[0];
	a[1] = f(a[0]);
	b[1] = f(b[0]);
	c[1] = f(c[0]);
	puts(c[1] == a[1] + b[1] ? "YES" : "NO");
}