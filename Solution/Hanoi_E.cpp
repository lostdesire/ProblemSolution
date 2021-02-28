#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int T;
	int N;
	int circle[10000];

	cin >> T;

	while(T--)
	{
		cin >> N;
		int count = N;
		int total = 0;
		memset(circle, 0, sizeof(circle));

		for (int i = 0; i < N; i++)
		{
			cin >> circle[i];
		}

		while (count != 0)
		{
			for (int i = 0; i < N; i++)
			{
				if (count == 0)
					break;
				if (circle[i] == count)
				{
					circle[i] = -1;
					count--;
				}
			}
			total++;
		}

		cout << total << "\n";
	}


	return 0;
}