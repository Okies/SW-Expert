#include <iostream>
#include <string>

using namespace std;

int mod(int n, string x)
{
	int sum = 0;

	for(auto a : x)
	{
		sum += a - '0';
	}

	return sum % (n - 1);
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
		int n;
		string x;

		cin >> n >> x;

		cout << "#" << tc << " " << mod(n, x) << endl;
	}

	return 0;
}