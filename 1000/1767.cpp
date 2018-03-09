#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int T, N;
vector<pair<int, int>> v;
int map[13][13];
int maxCore, cntCore;
int maxC, minL, cntL;

int bound(int y, int x)
{
	if (y == 0 || y == N - 1)
		return 1;
	if (x == 0 || x == N - 1)
		return 1;
	return 0;
}

int check(int y, int x, int dir)
{
	int cnt = 0;
	switch (dir)
	{
	case 0:
		for (int i = y - 1; i >= 0; i--, cnt++)
			if (map[i][x])
				return 0;
		break;
	case 1:
		for (int j = x + 1; j < N; j++, cnt++)
			if (map[y][j])
				return 0;
		break;
	case 2:
		for (int i = y + 1; i < N; i++, cnt++)
			if (map[i][x])
				return 0;
		break;
	case 3:
		for (int j = x - 1; j >= 0; j--, cnt++)
			if (map[y][j])
				return 0;
		break;
	}
	return cnt;
}

void draw(int y, int x, int dir, int type)
{
	switch (dir)
	{
	case 0:
		for (int i = y - 1; i >= 0; i--)
			map[i][x] = type;
		break;
	case 1:
		for (int j = x + 1; j < N; j++)
			map[y][j] = type;
		break;
	case 2:
		for (int i = y + 1; i < N; i++)
			map[i][x] = type;
		break;
	case 3:
		for (int j = x - 1; j >= 0; j--)
			map[y][j] = type;
		break;
	}
}

void solve(int idx, int cntcore)
{
	if (idx == v.size())
	{
		if (cntcore > maxC)
		{
			maxC = cntcore;
			minL = cntL;
		}
		if (cntcore == maxC)
		{
			if (cntL < minL)
				minL = cntL;
		}
		return;
	}

	int y = v[idx].first;
	int x = v[idx].second;

	for (int dir = 0; dir < 4; dir++)
	{
		int cnt = check(y, x, dir);
		if (cnt)
		{
			draw(y, x, dir, 2);
			cntL += cnt;
			solve(idx + 1, cntcore + 1);
			draw(y, x, dir, 0);
			cntL -= cnt;
		}
	}
	solve(idx + 1, cntcore);
}

void init()
{
	for (int i = 0; i < 13; i++)
		memset(map[i], 0, sizeof(int) * 13);
	maxCore = 0;
	cntCore = 0;
	maxC = 0;
	minL = 99999;
	cntL = 0;
	vector<pair<int, int>> empty;
	v = empty;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();

		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j])
				{
					maxCore++;
					if (bound(i, j))
						cntCore++;
					else
						v.push_back(make_pair(i, j));
				}
			}

		solve(0, cntCore);
		cout << "#" << tc << " " << minL << endl;
	}

	return 0;
}