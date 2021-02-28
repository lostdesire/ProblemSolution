#include <iostream>
#include <string.h>
using namespace std;

#define SMALL_F 65
#define SMALL_L 91
#define LARGE_F 97
#define LARGE_L 123

char S[15001], R[81];
int count1[LARGE_L];
int count2[LARGE_L];
int Answer;

int main()
{
	ios::sync_with_stdio(false);
	int T;

	cin >> T;

	while(T--)
	{
		for (int i = 0; i < LARGE_L; i++)
		{
			count2[i] = 0;
		}
		cin >> S >> R;

		for (int j = 0; j < strlen(R); j++)
		{
			count2[(int)R[j]]++;
		}
		int left = 0;
		int right = strlen(S);
		while (left <= right)
		{
			for (int i = 0; i < LARGE_L; i++)
			{
				count1[i] = 0;
			}

			int mid = (left + right) / 2;

			for (int i = 0; i < mid; i++)
			{
				count1[(int)S[i]]++;
			}

			int iter = 0;

			bool success = true;

			while (iter + mid <= strlen(S))
			{
				success = true;
				for (int i = SMALL_F; i < SMALL_L; i++)
				{
					if (count1[i] < count2[i])
					{
						success = false;
					}
				}
				for (int i = LARGE_F; i < LARGE_L; i++)
				{
					if (count1[i] < count2[i])
					{
						success = false;
					}
				}
				if (success)
					break;
				count1[S[iter]]--;
				count1[S[iter + mid]]++;
				iter++;
			}

			if (success)
			{
				if (left == right)
				{
					Answer = left;
					break;
				}
				right = mid;
			}
			else
			{
				if (left == right)
				{
					Answer = 0;
					break;
				}
				left = mid + 1;
			}
		}
		cout << Answer << "\n";
	}

	return 0;
}