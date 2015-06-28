
#include <bits/stdc++.h>

using namespace std;

string a = "WBWBWBWB", b ="BWBWBWBW";
string c[8];

int main()
{
	for (int i = 0; i < 8; i++)
		cin >> c[i];
	for (int i = 0; i < 8; i++)
		if (c[i] == a || c[i] == b)
			continue;
		else
		{
			puts("NO");
			return 0;
		}
	puts("YES");
}
