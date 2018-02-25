#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG

	cin >> T;

	for (int z = 1; z <= T; z++)
	{
		vector<int> v;

		cin >> N;

		v.resize(N);

		for (int i = 0; i < N; i++)
			cin >> v[i];

		sort(v.begin(), v.end());

		vector<int> v2;

		for (int i = 0; i < N; i += 2)
			v2.push_back(v[i]);
		if (N % 2)
			for (int i = N - 2; i > 0; i -= 2)
				v2.push_back(v[i]);
		else
			for (int i = N - 1; i > 0; i -= 2)
				v2.push_back(v[i]);

		int m = 0;
		for (int i = 0; i < N - 1; i++)
		{
			int n = abs(v2[i] - v2[i + 1]);
			
			if (m < n)
				m = n;
		}

		cout << "#" << z << " " << m << endl;
	}

	return 0;
}