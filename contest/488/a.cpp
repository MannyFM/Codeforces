
#include <bits/stdc++.h>

using namespace std;

bool ch(int a)
{
	bool fl = 0;
	a = abs(a);
	while (a > 0)
	{
		if (a % 10 == 8)
			return 1;
		a /= 10;
	}
	return 0;
}

int main()
{
	int a, b = 1;
	cin >> a;
	while (!ch(a + b))
		b++;
	cout << b;
}
