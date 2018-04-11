#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
	int n, dir;
	int max;
}INFO;

typedef struct
{
	int y, x;
	INFO info;
}MON;

vector<MON> v;
vector<MON> temp1;
vector<MON> temp2;

typedef struct
{
	int y, x;
}DIR;

DIR d[] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1},{ 0, 1 } };

INFO map[101][101];

int N, M, K;

int bound(int y, int x)
{
	if (y == 0 || x == 0 || y == N - 1 || x == N - 1)
		return true;
	return false;
}

vector<MON> clear()
{
	vector<MON> empty;
	return empty;
}

void move()
{
	for (auto a : v)
	{
		a.y += d[a.info.dir].y;
		a.x += d[a.info.dir].x;

		if (bound(a.y, a.x))
		{
			if (a.info.dir == 1 || a.info.dir == 3) a.info.dir++;
			else a.info.dir--;
			a.info.n /= 2;
			temp1.push_back(a);
		}
		else temp2.push_back(a);
	}
}

void merge()
{
	for (auto a : temp2)
	{
		if (map[a.y][a.x].max < a.info.n)
		{
			map[a.y][a.x].max = a.info.n;
			map[a.y][a.x].dir = a.info.dir;
		}
		map[a.y][a.x].n += a.info.n;
	}

	for (auto a : temp2)
	{
		if (map[a.y][a.x].n)
		{
			a.info.n = map[a.y][a.x].n;
			a.info.dir = map[a.y][a.x].dir;

			map[a.y][a.x].dir = 0;
			map[a.y][a.x].max = 0;
			map[a.y][a.x].n = 0;

			temp1.push_back(a);
		}
	}
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		temp1 = clear();
		temp2 = clear();

		move();

		merge();

		v = temp1;
	}
}

int print_sum()
{
	int sum = 0;
	for (auto a : v)
		sum += a.info.n;

	return sum;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{

		cin >> N >> M >> K;

		v = clear();

		for (int i = 0; i < K; i++)
		{
			MON m;
			
			cin >> m.y >> m.x >> m.info.n >> m.info.dir;

			v.push_back(m);
		}

		solve();

		cout << "#" << tc << " " << print_sum() << endl;
	}
	return 0;
}