#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int T;
	int N;
	int circle[10000], count[10001];

	cin >> T;

	while (T--)
	{
		cin >> N;
		int total = 0;
		memset(count, 0, sizeof(count));
		memset(circle, 0, sizeof(circle));

		for (int i = 0; i < N; i++)
		{
			cin >> circle[i];
		}

	
		for (int i = 0; i < N; i++)
		{
			count[circle[i]]++;
			if (count[circle[i] + 1] == 0)
				total++;	
		}
		

		cout << total << "\n";
	}


	return 0;
}