
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define maxn (int)(1e3)

string s, t;
int i, j;

int main()
{
	cin >> s >> t;
	while (j < (int) t.size())
	{
		if (s[i] == t[j])
			i++, j++;
		else
			j++;
	}
	cout << i + 1;
}