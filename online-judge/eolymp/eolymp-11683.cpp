// Fuad's Challenge
/*
permutasi yang mungkin adalah:
"4, 2, 3, 1," 5, 6, ..., n
*/
#include<cstdio>
signed main() {
	int n; scanf("%d", &n);
	if (n <= 3) printf("-1\n");
	else {
		printf("4 2 3 1 ");
		for (int i = 5; i <= n; i++) printf("%d ", i);
		printf("\n");
	}
}
