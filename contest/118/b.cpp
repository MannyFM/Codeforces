
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * (n - i); j++)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << j << " ";
		for (int j = i; j > 0; j--)
			cout << j << " ";
		cout << "0\n";
	}
	for (int i = 0; i <= n; i++)
		cout << i << " ";
	for (int i = n - 1; i > 0; i--)
		cout << i << " ";
	cout << "0\n";
	for (int i = n - 1; i >= 0; i--)
	{

		for (int j = 0; j < 2 * (n - i); j++)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << j << " ";
		for (int j = i; j > 0; j--)
			cout << j << " ";
		cout << "0\n";
	}
}