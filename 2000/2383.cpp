#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int map[11][11];

typedef struct
{
	int y, x;
	int t[2];
	int left;
}P;

typedef struct
{
	int y, x, t;
}S;

vector<P> v;
vector<S> s;
int N;
int minN;

bool comp1(P a, P b)
{
	if(a.t[0] < b.t[0])
		return true;
	return false;
}

bool comp2(P a, P b)
{
	if (a.t[1] < b.t[1])
		return true;
	return false;
}

int down(vector<P> a, int sn)
{
	if (sn == 0)
		sort(a.begin(), a.end(), comp1);
	else
		sort(a.begin(), a.end(), comp2);

	int t = s[sn].t;

	for (int i = 0; i < a.size(); i++)
		if (i / 3 == 0)
			a[i].t[sn] += t + 1;
		else
			if (a[i - 3].t[sn] > a[i].t[sn])
				a[i].t[sn] = a[i - 3].t[sn] + t;
			else
				a[i].t[sn] += t + 1;

	return a[a.size() - 1].t[sn];
}

void solve(int idx, vector<P> a, vector<P> b)
{
	if (idx == v.size())
	{
		int TA = 0, TB = 0, minT = 9999999;
		if (a.size())
			TA = down(a, 0);
		if (b.size())
			TB = down(b, 1);
		minT = TA > TB ? TA : TB;
		if (minN > minT)
			minN = minT;
		return;
	}

	a.push_back(v[idx]);
	solve(idx + 1, a, b);
	a.pop_back();
	b.push_back(v[idx]);
	solve(idx + 1, a, b);
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

		vector<P> t;
		v = t;
		vector<S> tt;
		s = tt;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if(map[i][j])
					if (map[i][j] == 1)
					{
						P p;
						p.y = i;
						p.x = j;
						v.push_back(p);
					}
					else
					{
						S st;
						st.y = i;
						st.x = j;
						st.t = map[i][j];
						s.push_back(st);
					}
			}
		minN = 1000000;
		for(int i = 0; i < v.size(); i++)
			for (int j = 0; j < s.size(); j++)
				v[i].t[j] = abs(s[j].y - v[i].y) + abs(s[j].x - v[i].x);

		vector<P> a;
		vector<P> b;
		solve(0, a, b);

		cout << "#" << tc << " " << minN << endl;
	}

	return 0;
}