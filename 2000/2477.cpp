//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#include <queue>
//
//using namespace std;
//
//int T, N, M, K, A, B;
//
//typedef struct
//{
//	int n;
//	int w;
//	int t;
//}center;
//center a[10], b[10];
//
//typedef struct
//{
//	int n, t;
//}person;
//queue<person> t;
//queue<person> t2;
//
//typedef struct
//{
//	int A, B;
//}AB;
//AB ab[1001];
//
//void init()
//{
//	memset(a, 0, sizeof(center) * 10);
//	memset(b, 0, sizeof(center) * 10);
//	memset(ab, 0, sizeof(AB) * 1001);
//	queue<person> empty;
//	swap(t2, empty);
//}
//
//int solve()
//{
//	int z = 0;
//	queue<person> wait1;
//	queue<person> wait2;
//	while (1)
//	{
//
//		for (; !t.empty() && t.front().t == z;)
//		{
//			wait1.push(t.front());
//			t.pop();
//		}
//
//		for (int i = 0; i < N; i++)
//		{
//			if (a[i].w > 1)
//				a[i].w--;
//			else if (a[i].w == 1)
//			{
//				person p;
//				p.n = a[i].n;
//				p.t = z;
//				wait2.push(p);
//				a[i].w--;
//				ab[p.n].A = i + 1;
//				if (!wait1.empty())
//				{
//					a[i].n = wait1.front().n;
//					a[i].w = a[i].t;
//					wait1.pop();
//				}
//			}
//			else
//				if (!wait1.empty())
//				{
//					a[i].n = wait1.front().n;
//					a[i].w = a[i].t;
//					wait1.pop();
//				}
//		}
//
//		for (int i = 0; i < M; i++)
//		{
//			if (b[i].w > 1)
//				b[i].w--;
//			else if (b[i].w == 1)
//			{
//				person p;
//				p.n = b[i].n;
//				p.t = z + 1;
//				t2.push(p);
//				b[i].w--;
//				ab[p.n].B = i + 1;
//				if (!wait2.empty())
//				{
//					b[i].n = wait2.front().n;
//					b[i].w = b[i].t;
//					wait2.pop();
//				}
//			}
//			else
//				if (!wait2.empty())
//				{
//					b[i].n = wait2.front().n;
//					b[i].w = b[i].t;
//					wait2.pop();
//				}
//		}
//
//		if (t2.size() == K)
//			break;
//
//		z++;
//	}
//
//	int ret = 0;
//
//	for (int i = 1; i <= K; i++)
//		if (ab[i].A == A && ab[i].B == B)
//			ret += i;
//	
//	if (ret)
//		return ret;
//	else
//		return -1;
//}
//
//int main(void)
//{
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//#endif
//
//	cin >> T;
//
//	for (int z = 1; z <= T; z++)
//	{
//		init();
//
//		cin >> N >> M >> K >> A >> B;
//		for (int i = 0; i < N; i++)
//			cin >> a[i].t;
//		for (int i = 0; i < M; i++)
//			cin >> b[i].t;
//		for (int i = 1; i <= K; i++)
//		{
//			person p;
//			p.n = i;
//			cin >> p.t;
//			t.push(p);
//		}
//
//		cout << "#" << z << " " << solve() << endl;
//	}
//	
//	return 0;
//}