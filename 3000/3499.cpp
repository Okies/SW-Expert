#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N;

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;

	for (int z = 1; z <= T; z++)
	{
		cin >> N;

		vector<string> v;
		v.resize(N);

		for (int i = 0; i < N; i++)
			cin >> v[i];

		cout << "#" << z << " ";
		
		int i = 0, j = 0;
		if (N % 2)
			j++;

		for (i = 0, j = j + N / 2; i < N && j < N; i++, j++)
			cout << v[i] << " " << v[j] << " ";

		if (N % 2)
			cout << v[i];
		cout << endl;
	}

	return 0;
}