
#include <bits/stdc++.h>

using namespace std;

int n, h = 0, last = 0;

int main()
{
	cin >> n;
	while (n >= last + h)
	{
		h++;
		last += h;
		n-= last;
		if (n < 0)
		{
			h--;
			break;
		}
	}
	cout << h;
}