
#include <stdio.h>

int main() {
	int n = 6, m = 5, cnt = 5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", i < m - j ? '*' : '+');
		puts("");
	}
}
