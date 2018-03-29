#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
vector<int> v;

void init()
{
	vector<int> empty;

	v = empty;
}

long long solve(long long left, long long right)
{
	if(left + 1 >= right)
		return right;

	long long mid = (left + right) / 2;
	long long sum = 0;

	for (int i = 0; i < N; i++)
		sum += mid / v[i];

	if (sum < M)
		return solve(mid, right);
	else
		return solve(left, mid);
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

		cin >> N >> M;

		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];

		cout << "#" << tc << " " << solve(1, 1e14 + 1) << endl;
	}

	return 0;
}