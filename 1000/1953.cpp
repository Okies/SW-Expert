#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int T, N, M, R, C, L;
int map[51][51];
int mark[51][51];
int cnt;
queue<pair<int, int>> q;

typedef struct
{
	int u;
	int r;
	int d;
	int l;
}tile;

tile t[] = { {0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1} };

void goUp(int x, int y)
{
	if (y == 0)
		return;
	y--;

	if (mark[y][x] || !t[map[y][x]].d)
		return;

	q.push(make_pair(y, x));
	mark[y][x] = mark[y + 1][x] + 1;
	cnt++;
}

void goRight(int x, int y)
{
	if (x == M - 1)
		return;
	x++;

	if (mark[y][x] || !t[map[y][x]].l)
		return;

	q.push(make_pair(y, x));
	mark[y][x] = mark[y][x - 1] + 1;
	cnt++;
}

void goDown(int x, int y)
{
	if (y == N - 1)
		return;
	y++;

	if (mark[y][x] || !t[map[y][x]].u)
		return;

	q.push(make_pair(y, x));
	mark[y][x] = mark[y - 1][x] + 1;
	cnt++;
}

void goLeft(int x, int y)
{
	if (x == 0)
		return;
	x--;

	if (mark[y][x] || !t[map[y][x]].r)
		return;

	q.push(make_pair(y, x));
	mark[y][x] = mark[y][x + 1] + 1;
	cnt++;
}

void bfs()
{
	q.push(make_pair(R, C));
	mark[R][C] = 1;
	cnt++;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if (mark[y][x] >= L)
			break;

		switch (map[y][x])
		{
		case 1:
			goUp(x, y);
			goRight(x, y);
			goDown(x, y);
			goLeft(x, y);
			break;
		case 2:
			goUp(x, y);
			goDown(x, y);
			break;
		case 3:
			goRight(x, y);
			goLeft(x, y);
			break;
		case 4:
			goUp(x, y);
			goRight(x, y);
			break;
		case 5:
			goRight(x, y);
			goDown(x, y);
			break;
		case 6:
			goDown(x, y);
			goLeft(x, y);
			break;
		case 7:
			goUp(x, y);
			goLeft(x, y);
			break;
		default:
			break;
		}
	}
}

int solve()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
		memset(mark[i], 0, sizeof(int) * 51);
	while (!q.empty())
		q.pop();

	bfs();

	return cnt;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];

		cout << "#" << tc << " " << solve() << endl;
	}

	return 0;
}