#include <iostream>
#include <string.h>

using namespace std;

int T, R, C;
char map[21][21];
int mark[21][21][4][16];
int flag;

typedef struct
{
	int y, x;
}Dir;

Dir d[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void init()
{
	for (int i = 0; i < 21; i++)
		memset(map[i], 0, sizeof(int) * 21);
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 4; k++)
				for (int z = 0; z < 16; z++)
					mark[i][j][k][z] = 0;
	flag = 0;
}

void solve(int y, int x, int dir, int cell)
{
	if (mark[y][x][dir][cell]) return;
	mark[y][x][dir][cell] = 1;

	char cmd = map[y][x];

	int dy = y;
	int dx = x;
	switch (cmd)
	{
	case '0':case '1':case '2':
	case '3':case '4':case '5':
	case '6':case '7':case '8':
	case '9':
		cell = cmd - '0';
		break;

	case '<':
		dir = 3;
		break;

	case '>':
		dir = 1;
		break;

	case '^':
		dir = 0;
		break;
		
	case 'v':
		dir = 2;
		break;

	case '_':
		if (!cell) dir = 1;
		else dir = 3;
		break;

	case '|':
		if (!cell) dir = 2;
		else dir = 0;
		break;

	case '+':
		if (cell < 15) cell++;
		else cell = 0;
		break;

	case '-':
		if (cell > 0) cell--;
		else cell = 15;
		break;

	case '@':
		flag = 1;
		return;
	}

	if(cmd == '?')
		for (int i = 0; i < 4; i++)
		{
			int dy = y + d[i].y;
			if (dy < 0) dy = R - 1;
			if (dy == R) dy = 0;
			int dx = x + d[i].x;
			if (dx < 0) dx = C - 1;
			if (dx == C) dx = 0;

			solve(dy, dx, i, cell);
		}

	switch (dir)
	{
	case 0:
		if (y == 0) dy = R - 1;
		else dy = y - 1;
		break;
	case 1:
		if (x == C - 1) dx = 0;
		else dx = x + 1;
		break;
	case 2:
		if (y == R - 1) dy = 0;
		else dy = y + 1;
		break;
	case 3:
		if (x == 0) dx = C - 1;
		else dx = x - 1;
		break;
	}
	solve(dy, dx, dir, cell);
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> R >> C;
		init();

		int find = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
					find = 1;
			}

		if (find)
			solve(0, 0, 1, 0);
		else
		{
			cout << "#" << tc << " NO" << endl;
			continue;
		}

		cout << "#" << tc << " ";
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}