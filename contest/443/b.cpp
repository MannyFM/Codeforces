
#include <bits/stdc++.h>

using namespace std;

string s;
int k, sz;

bool f(int l, int r)
{
	if ((r - l + 1) & 1)
		return 0;
	int m = (r + l) >> 1;
	int d = (r - l + 1) >> 1;
	/*
	if (r - l + 1 == 21)
		printf("%d %d %d: ", l, r, m);
	*/
	for (int i = l; i <= m; i++)
	{
		if (r - l + 1 == 21)
			printf("(%c %c)", s[i], s[i + d]);
		if (s[i] == s[i + d] || s[i] == '#' || s[i + d] == '#')
			continue;
		return 0;
	}
	return 1;
}

int main()
{
	cin >> s >> k;
	for (int i = 0; i < k; i++)
		s.push_back('#');
	sz = int(s.size());
	int ans = 0;
	for (int l = 0; l < sz; l++)
	for (int r = l; r < sz; r++)
	{
		bool t = f(l, r);
		if (t)
			ans = max(ans, r - l + 1);
		/*
		if (r - l + 1 == 21)
			printf(" %d %d\n", t, ans);
		*/
	}
	printf("%d", ans);
}