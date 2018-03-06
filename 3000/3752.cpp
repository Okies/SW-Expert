#include <iostream>
#include <string.h>

using namespace std;

int T, N;
int arr[100];
int	check[10001];

int solve()
{
	check[0] = 1;
	int maxN = 0;
	for (int i = 0; i < N; i++)
		for (int j = maxN; j >= 0; j--)
			if (check[j])
			{
				check[j + arr[i]] = 1;
				if (j + arr[i] > maxN)
					maxN = j + arr[i];
			}

	int ret = 0;
	for (int i = 0; i < 10001; i++)
		if (check[i])
			ret++;

	return ret;
}

int main(void)
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		memset(arr, 0, sizeof(int) * 100);
		memset(check, 0, sizeof(int) * 10001);

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		cout << "#" << tc << " " << solve() << endl;
	}

	return 0;
}