
#include <bits/stdc++.h>

using namespace std;

int n, top, bottom, l[200], r[200];
int f[3];

void get(int i)
{
	vector <int> v(7, 1);
	f[0] = f[1] = f[2] = -1;
	v[l[i]] = v[7 - l[i]] = 0;
	v[r[i]] = v[7 - r[i]] = 0;
	int cnt = 0;
	for (int i = 1; i <= 6; i++)
		if (v[i])
			f[cnt++] = i;
	if (f[2] != -1)
	{
		puts("NO");
		exit(0);
	}
	if (f[0] != bottom && f[1] != bottom)
	{
		puts("NO");
		exit(0);
	}
}

int main()
{
	scanf("%d%d", &n, &top);
	for (int i = 0; i < n; i++)
		scanf("%d%d", l + i, r + i);
	bottom = 7 - top;
	for (int i = 1; i < n; i++)
		get(i);
	puts("YES");
}