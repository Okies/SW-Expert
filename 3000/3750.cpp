#include <stdio.h>

int T;

int solve(long long int n)
{
	if (n < 10)
		return n;

	long long int sum = 0;
	while (n > 9)
	{
		sum += n % 10;
		n /= 10;
	}
	sum += n;

	return solve(sum);
}

int main(void)
{
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		long long int n;

		scanf("%lld", &n);

		printf("#%d %d\n", tc, solve(n));
	}

	return 0;
}