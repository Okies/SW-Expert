#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int arr[17][17];
int N;
int minN = 200000 * 8 + 1;

void solve(int idx, vector<int> a, vector<int> b)
{
	if (a.size() == N / 2 && b.size() == N / 2) //°è»ê
	{
		int sumA = 0, sumB = 0;
		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
				if (i == j)
					continue;
				else
					sumA += arr[a[i]][a[j]];

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
				if (i == j)
					continue;
				else
					sumB += arr[b[i]][b[j]];

		int minSub = abs(sumA - sumB);
		if (minN > minSub)
			minN = minSub;
		return;
	}

	if (a.size() < N / 2)
	{
		a.push_back(idx);
		solve(idx + 1, a, b);
		a.pop_back();
	}

	if (b.size() < N / 2)
	{
		b.push_back(idx);
		solve(idx + 1, a, b);
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
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		
		minN = 200000 * 8 + 1;

		vector<int> a;
		vector<int> b;

		b.push_back(0);
		solve(1, a, b);

		cout << "#" << tc << " " << minN << endl;
	}

	return 0;
}