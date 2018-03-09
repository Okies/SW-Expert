#include <iostream>
#include <vector>

using namespace std;

int T, N, B;
vector<int> v;
int minS;

vector<int> clear(vector<int> v)
{
	vector<int>empty;
	v = empty;

	return v;
}

void solve(int idx, int sum)
{
	if (sum >= B)
	{
		if (minS > sum)
			minS = sum;
		return;
	}

	if (idx == N)
		return;

	solve(idx + 1, sum);
	solve(idx + 1, sum + v[idx]);
}

int main(void)
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> B;

		v = clear(v);
		minS = 9999999;

		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		
		solve(0, 0);
		if (N == 1)
			minS = v[0];
		cout << "#" << tc << " " << minS - B << endl;
	}

	return 0;
}