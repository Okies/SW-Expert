#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int T, N, X;
int map[21][21];
int cnt;

void check(vector<int> &v)
{
	int t = 0;
	int flag = 0;
	int diff = 0;

	for (int i = 0; i < N - 1; i++)
	{
		diff = v[i + 1] - v[i];
		t++;

		if (abs(diff) > 1)
			return;

		if (flag)
		{
			if (X == t)
			{
				flag = 0;
				t = 0;
			}
			if (diff == 0)
				continue;

			if (diff && flag)
				return;

			if (diff == 1)
				if (X <= t)
					t = 0;
				else
					return;

			if (diff == -1)
			{
				flag = 1;
				t = 0;
			}
		}
		else
		{
			if (diff == 0)
				continue;

			if (diff == 1)
				if (X <= t)
					t = 0;
				else
					return;

			if (diff == -1)
			{
				flag = 1;
				t = 0;
			}
		}
	}
	if (!flag || X <= t + 1)
		cnt++;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> X;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		cnt = 0;

		vector<int> v1;
		vector<int> v2;

		v1.resize(N);
		v2.resize(N);

		for (int i = 0; i < N; i++)
		{
			

			for (int j = 0; j < N; j++)
			{
				v1[j] = map[i][j];
				v2[j] = map[j][i];
			}

			check(v1);
			check(v2);
		}

		cout << "#" << tc << " " << cnt << endl;
	}

	return 0;
}