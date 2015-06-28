
#include <bits/stdc++.h>

using namespace std;

int t;
string x;

bool check(int a, int b)
{
	for (int i = 0; i < b; i++)
	{
		int ok = 1;
		for (int j = 0; j < a; j++)
			if (x[j * b + i] != 'X')
			{
				ok = 0;
				break;
			}
		if (ok)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		cin >> x;
		vector <int> us;
		for (int a = 1; a <= 12; a++)
			if (12 % a == 0 && check(a, 12 / a))
				us.push_back(a);
		if (us.empty())
		{
			puts("0");
			continue;
		}
		printf("%d ", us.size());
		if (!us.empty())
			for (int i = 0; i < (int)(us.size()); i++)
				printf("%dx%d ", us[i], 12 / us[i]);
		puts("");
	}
}