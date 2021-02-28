#include <iostream>
#include <string.h>
using namespace std;

int T;
int M, N;
int G[50][1000];
int cnt[4][1000];
int ans[1000];
string line;


int main()
{	
	ios::sync_with_stdio(false);

	int count;

	cin >> T;

	while (T--)
	{
		count = 0;
		memset(cnt, 0, sizeof(cnt));

		cin >> M >> N;

		for (int i = 0; i < M; i++)
		{
			cin >> line;

			for (int j = 0; j < N; j++)
			{
				switch (line[j])
				{
				case 'A':
					G[i][j] = 0;
					cnt[0][j]++;
					break;
				case 'C':
					G[i][j] = 1;
					cnt[1][j]++;
					break;
				case 'G':
					G[i][j] = 2;
					cnt[2][j]++;
					break;
				case 'T':
					G[i][j] = 3;
					cnt[3][j]++;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			int max1, max2;
			int a, b;
			if (cnt[0][i] >= cnt[1][i])
			{
				max1 = cnt[0][i];
				a = 0;
			}
			else
			{
				max1 = cnt[1][i];
				a = 1;
			}
			if (cnt[2][i] >= cnt[3][i])
			{
				max2 = cnt[2][i];
				b = 2;
			}
			else
			{
				max2 = cnt[3][i];
				b = 3;
			}

			if (max1 >= max2)
			{
				ans[i] = a;
			}
			else
				ans[i] = b;
		}
		for (int i = 0; i < N; i++)
		{
			switch (ans[i])
			{
			case 0:
				cout << "A";
				break;
			case 1:
				cout << "C";
				break;
			case 2:
				cout << "G";
				break;
			case 3:
				cout << "T";
				break;
			}
		}
		cout << "\n";
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (ans[j] != G[i][j])
					count++;
			}
		}
		cout << count << "\n";
	}
	
	return 0;
}