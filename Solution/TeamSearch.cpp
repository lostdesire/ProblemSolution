#include <iostream>
#include <string.h>
using namespace std;

int student[10001];
int steam[10001];
int total;
void team(int s, int num)
{
	if (steam[student[s]] == 0)
	{
		steam[student[s]]++;
		team(student[s], num);
	}
	else
	{
		if (steam[num] == 0)
			total++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	int N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		memset(student, 0, sizeof(student));
		total = 0;
		for (int i = 1; i < N + 1; i++)
		{
			cin >> student[i];
		}

		for (int i = 1; i < N + 1; i++)
		{
			memset(steam, 0, sizeof(steam));
			team(i, i);
		}

		cout << total << "\n";
	}

	return 0;
}