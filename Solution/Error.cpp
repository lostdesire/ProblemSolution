#include <iostream>
#include <string.h>

using namespace std;

char word[26][128], encoding[1024];
int T;
int M, N, E, L;
int temp_count, dis;
char ans;
void set()
{
	memset(word, 0, sizeof(word));
	memset(encoding, 0, sizeof(encoding));
}

int main()
{
	ios::sync_with_stdio(false);

	int count[26];
	string line;
	
	cin >> T;

	while (T--)
	{
		set();
		line = "";
		cin >> M >> N;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> word[i][j];
			}
		}

		cin >> E;

		for (int i = 0; i < E; i++)
		{
			cin >> encoding[i];
		}

		for (int i = 0; i < E / N; i++)
		{
			dis = 0;
			temp_count = 128;
			memset(count, 0, sizeof(count));
			for (int j = 0; j < M; j++)
			{
				for (int k = 0; k < N; k++)
				{
					if (word[j][k] != encoding[k + i * N])
						count[j]++;
				}
				if (count[j] < temp_count)
				{
					dis = j;
					temp_count = count[j];
				}
			}
			ans = 'A' + dis;
			line += ans;
		}

		cout << line << "\n";
	}

	return 0;
}