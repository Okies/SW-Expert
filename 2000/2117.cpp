#include <iostream>

using namespace std;

typedef struct
{
	int y, x;
	int size;
}Service;

int N, M;
int map[21][21];
int maxCnt;

int inmap(int y, int x)
{
	if (y >= 0 && y <= N - 1 && x >= 0 && x <= N - 1)
		return true;
	return false;
}

int eval(Service s)
{
	int sum = 0;
	for (int i = 0; i <= s.size; i++)
		for (int j = s.x - i; j <= s.x + i; j++)
			if (inmap(s.y - s.size + i, j) && map[s.y - s.size + i][j])
				sum++;
	for (int i = 1; i <= s.size; i++)
		for (int j = s.x - s.size + i; j <= s.x + s.size - i; j++)
			if (inmap(s.y + i, j) && map[s.y + i][j])
				sum++;
	sum *= M;

	int ss = (s.size + 1) * (s.size + 1) + s.size * s.size;
	if (sum >= ss)
		return sum / M;
	return 0;
}

void solve()
{
	Service s;

	s.size = N;
	s.y = 0;
	s.x = 0;

	while (s.size != -1)
	{	
		if (maxCnt >= (s.size + 1) * (s.size + 1) + s.size * s.size)
			break;
		int cnt = eval(s);
		
		if (cnt > maxCnt)
			maxCnt = cnt;
		
		if (s.x == N - 1)
			if (s.y == N - 1)
			{
				s.y = 0;
				s.x = 0;
				s.size--;
			}
			else
			{
				s.y++;
				s.x = 0;
			}
		else
			s.x++;
	}
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
		cin >> N >> M;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		maxCnt = 0;

		solve();

		cout << "#" << tc << " " << maxCnt << endl;
	}

	return 0;
}