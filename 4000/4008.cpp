#include <iostream>

using namespace std;

int arr[13];
int minN;
int maxN;
int N;

void solve(int idx, int p, int s, int t, int m, int sum)
{
	if (idx == N)
	{
		if (maxN < sum) maxN = sum;
		if (minN > sum) minN = sum;
	}

	if (p > 0) solve(idx + 1, p - 1, s, t, m, sum + arr[idx]);
	if (s > 0) solve(idx + 1, p, s - 1, t, m, sum - arr[idx]);
	if (t > 0) solve(idx + 1, p, s, t - 1, m, sum * arr[idx]);
	if (m > 0) solve(idx + 1, p, s, t, m - 1, sum / arr[idx]);
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

		int p, s, t, m;

		cin >> p >> s >> t >> m;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		maxN = -100000000;
		minN = 100000000;

		solve(1, p, s, t, m, arr[0]);

		cout << "#" << tc << " " << maxN - minN << endl;
	}

	return 0;
}