#include <iostream>
#include <math.h>

using namespace std;

int T;
long long n;

int main(void)
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;

		cout << "#" << tc << " ";

		int level = (int)log2(n);

		if (n == 1)
			cout << "Bob";
		else if (n == 2 || n == 3)
			cout << "Alice";
		else
		{
			long long num = 1;
			if (level % 2)
			{
				for (int i = 0; i < level; i++)
					if (i % 2)
						num = num * 2 + 1;
					else
						num *= 2;
				if (n < num)
					cout << "Bob";
				else
					cout << "Alice";
			}
			else
			{
				for (int i = 0; i < level; i++)
					if (i % 2)
						num *= 2;
					else
						num = num * 2 + 1;
				if (n < num)
					cout << "Alice";
				else
					cout << "Bob";
			}
		}
		cout << endl;
	}

	return 0;
}