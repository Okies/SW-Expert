#include <iostream>
#include <algorithm>

using namespace std;

int T;
int pd, pm, pm3, py;
int arr[12];

int m3(int idx, int sum)
{
	if (idx > 11)
		return sum;

	if (arr[idx] + arr[idx + 1] + arr[idx + 2] > pm3)
		return min(m3(idx + 3, sum + pm3), m3(idx + 1, sum + arr[idx]));
	else
		return m3(idx + 1, sum + arr[idx]);

}

int solve()
{
	for (int i = 0; i < 12; i++)
		arr[i] *= pd;

	for (int i = 0; i < 12; i++)
		if (arr[i] > pm)
			arr[i] = pm;

	int sum = m3(0, 0);

	if (sum > py)
		return py;
	return sum;
}

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> pd >> pm >> pm3 >> py;
		for (int i = 0; i < 12; i++)
			cin >> arr[i];

		cout << "#" << tc << " " << solve() << endl;
	}

	return 0;
}