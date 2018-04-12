#include <iostream>
#include <string>

using namespace std;

int D, W, K;
int film[14][21];
int change[14];

int minN;

int check()
{
	for (int j = 0; j < W; j++)
	{
		int cnt = 1;
		int maxCnt = 0;
		for (int i = 0; i < D - 1; i++)
		{
			int now, next;
			if (change[i] == 2)
				now = film[i][j];
			else
				now = change[i];

			if (change[i + 1] == 2)
				next = film[i + 1][j];
			else
				next = change[i + 1];

			if (now == next)
				cnt++;
			else
			{
				maxCnt = cnt > maxCnt ? cnt : maxCnt;
				cnt = 1;
			}
		}
		maxCnt = cnt > maxCnt ? cnt : maxCnt;
		if (maxCnt < K)
			return false;
	}

	return true;
}

void solve(int idx, int n, int type)
{
	if(n >= minN)
		return;

	change[idx] = type;

	if (idx == D)
	{
		if (check() && n < minN)
			minN = n;
		return;
	}

	solve(idx + 1, n, 2);
	solve(idx + 1, n + 1, 0);
	solve(idx + 1, n + 1, 1);
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				cin >> film[i][j];
		minN = 999;

		solve(0, 0, 2);
		solve(0, 1, 0);
		solve(0, 1, 1);

		cout << "#" << tc << " " << minN << endl;
	}

	return 0;
}