
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5) + 12

char a[maxn];
string s, t;
int n;

int main()
{
	t = "<3";
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", a);
		t = t + string(a) + "<3";
	}
	cin >> s;
	int j = 0;
	for (int i = 0; i < int(s.size()); i++)
	{
		if (j == int(t.size()))
		{
			puts("yes");
			return 0;
		}
		if (s[i] == t[j])
			j++;
	}
	puts(j == int(t.size()) ? "yes" : "no");
}