
#include <bits/stdc++.h>

using namespace std;

string s;
int f[4];

int main()
{
	cin >> s;
	int n = int(s.size()); 
	f[0] = n > 4;
	for (int i = 0; i < n; i++)
	{
		f[1] |= 'A' <= s[i] && s[i] <= 'Z';
		f[2] |= 'a' <= s[i] && s[i] <= 'z';
		f[3] |= '0' <= s[i] && s[i] <= '9';
	}
	puts(f[0] && f[1] && f[2] && f[3] ? "Correct" : "Too weak");
}