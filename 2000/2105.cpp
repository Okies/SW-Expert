#include <iostream>

using namespace std;

int T, N;
int map[21][21];

typedef struct
{
	int x;
	int y;
}dir;

int dfs(int a, int b, int x, int y)
{
	dir d[] = { {0, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1} };
	int visit[101] = { 0 };

	for (int i = 1; i <= 4; i++)
	{
		if (i % 2)
		{
			for (int j = 1; j < y; j++)
			{
				a += d[i].x;
				b += d[i].y;

				if (visit[map[b][a]])
					return -1;
				else
					visit[map[b][a]] = 1;
			}
		}
		else
		{
			for (int j = 1; j < x; j++)
			{
				a += d[i].x;
				b += d[i].y;

				if (visit[map[b][a]])
					return -1;
				else
					visit[map[b][a]] = 1;
			}
		}
	}

	return 2 * x + (y - 2) * 2;
}

int route(int x, int y)
{
	if (x == 1 || y == 1)
		return 0;

	if (x + y - 1 > N)
		return 0;
	else
	{
		for(int i = 0; i <= N - (x + y - 1); i++)
			for (int j = x - 1; j < N - y + 1; j++)
			{
				int ret = dfs(j, i, x, y);
				if (ret > 0)
					return ret;
			}
	}

	return 0;
}

int solve()
{
	int ret = 0;
	for (int i = N - 1; i > 1; i--)
		for (int j = N - 1; j > 1; j--)
		{
			int temp = route(i, j);
			if (temp > ret)
				ret = temp;
		}

	if (ret)
		return ret;
	else
		return -1;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		cout << "#" << tc << " " << solve() << endl;
	}

	return 0;
}