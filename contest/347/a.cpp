
#include <bits/stdc++.h>

using namespace std;

int n, a;
vector <int> v;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(begin(v), end(v));
	swap(v[0], v[n - 1]);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
}