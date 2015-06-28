
#include <bits/stdc++.h>

using namespace std;

int n, d[110];
int us[100];
vector <int> v;

void add(int x)
{
	if (x == 0)
	{
		if (!us[0])
		{
			us[0] = 1;
			v.push_back(0);
		}
		return;
	}
	if (1 <= x && x <= 9)
	{
		if (!us[1])
		{
			us[1] = 1;
			v.push_back(x);
		}
		return;
	}
	if (10 <= x && x <= 99)
	{
		if (!us[2])
		{
			us[2] = 1;
			v.push_back(x);
		}
		return;
	}
	if (x == 100)
	{
		if (!us[3])
		{
			us[3] = 1;
			v.push_back(x);
		}
		return;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", d + i);
	for (int i = 0; i < n; i++)
		add(d[i]);
	printf("%d\n", int(v.size()));
	for (int i : v)
		printf("%d ", i);
}