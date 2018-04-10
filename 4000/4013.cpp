#include <iostream>

using namespace std;

int arr[4][8];
int top[4];

int TL(int top, int n)
{
	if (top - n < 0)
		return 8 - (n - top);
	return top - n;
}

int TR(int top, int n)
{
	return (top + n) % 8;
}

void rotate(int n, int r, int d)
{
	int fl = 0, fr = 0;

	if (n > 0 && d != -1 && arr[n - 1][TR(top[n - 1], 2)] != arr[n][TL(top[n], 2)]) //왼쪽 같으면 회전 X
		fl = 1;
	if (n < 3 && d != 1 && arr[n][TR(top[n], 2)] != arr[n + 1][TL(top[n + 1], 2)]) // 오른쪽 같으면 회전 X
		fr = 1;

	if (n > 0 && d != -1 && fl) rotate(n - 1, r * (-1), 1);
	if (n < 3 && d != 1 && fr) rotate(n + 1, r * (-1), -1);

	top[n] = r == 1 ? TL(top[n], 1) : TR(top[n], 1);
}

int print_sum()
{
	int sum = 0;
	for (int i = 0, j = 1; i < 4; i++, j *= 2)
		sum += arr[i][top[i]] * j;

	return sum;
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
		int K;

		cin >> K;

		for (int i = 0; i < 4; i++)
		{
			top[i] = 0;
			for (int j = 0; j < 8; j++)
				cin >> arr[i][j];
		}

		for (int i = 0; i < K; i++)
		{
			int n, r;
			cin >> n >> r;

			rotate(n - 1, r, 0);
		}

		cout << "#" << tc << " " << print_sum() << endl;
	}

	return 0;
}