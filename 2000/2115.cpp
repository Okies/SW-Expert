#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAXSIZE 11

int map[MAXSIZE][MAXSIZE];
int sum[MAXSIZE][MAXSIZE];

int T;
int N, M, C;

void init()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		memset(map[i], 0, sizeof(int) * MAXSIZE);
		memset(sum[i], 0, sizeof(int) * MAXSIZE);
	}
}

int getMaxSum(int y, int x, int m, int sum, int ssum)
{
	if (m >= M) return ssum;

	int maxSum = 0;
	int nextSum = 0;

	for (int i = m; i < M; i++)
	{
		if (sum + map[y][x + i] <= C)
		{
			nextSum = getMaxSum(y, x, i + 1, sum + map[y][x + i], ssum + map[y][x + i] * map[y][x + i]);
			if (nextSum > maxSum) maxSum = nextSum;
		}

		nextSum = getMaxSum(y, x, i + 1, sum, ssum);
		if (nextSum > maxSum) maxSum = nextSum;
	}

	return maxSum;
}

int getMaxPair(int y, int x)
{
	int ret = 0;

	for (int j = x + M; j <= N - M; j++)
		if (sum[y][j] > ret) ret = sum[y][j];

	for (int i = y + 1; i < N; i++)
		for (int j = 0; j <= N - M; j++)
			if (sum[i][j] > ret) ret = sum[i][j];

	return ret;
}

int solve()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= N - M; j++)
			sum[i][j] = getMaxSum(i, j, 0, 0, 0);

	int ret = 0;
	int pairSum = 0;
	for(int i = 0; i < N; i++)
		for (int j = 0; j <= N - M; j++)
		{
			pairSum = sum[i][j] + getMaxPair(i, j);
			if (pairSum > ret) ret = pairSum;
		}

	return ret;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> C;

		init();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		cout << "#" << t << " " << solve() << endl;
	}
}