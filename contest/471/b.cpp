
#include <bits/stdc++.h>

using namespace std;

#define print(v) {for(auto i : v) printf("%d ", i.second); puts("");}

vector <pair<int, int>> input, swaps;
int n, a[2002];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		input.push_back(make_pair(a[i], i + 1));
	}
	sort(begin(input), end(input));
	for (int i = 1; i < n; i++)
		if (input[i].first == input[i - 1].first)
			swaps.push_back(make_pair(i - 1, i));
	if (swaps.empty() || swaps.size() < 2)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	print(input);
	swap(input[swaps[0].first], input[swaps[0].second]);
	print(input);
	swap(input[swaps[1].first], input[swaps[1].second]);
	print(input);
}