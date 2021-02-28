#include <iostream>
#include <string.h>
using namespace std;

int TC[200000], arr[201];
int T;
int n, d, count, total;

void reset()
{
	memset(TC, 0, sizeof(TC));
	memset(arr, 0, sizeof(arr));
}
int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		total = 0;
		reset();

		cin >> n >> d;

		for (int i = 0; i < n; i++)
			cin >> TC[i];
		for (int i = 0; i < d; i++)
			arr[TC[i]]++;
		for (int i = d; i < n; i++)
		{
			int mid1 = 0, mid2 = 0, ans;
			int count = 0;
			for (int j = 0; j < 201; j++)
			{
				count += arr[j];
				if (mid1 == 0 && count > d / 2)
					mid1 = j;
				if (mid2 == 0 && count > d / 2 - 1)
					mid2 = j;
			}

			if (d % 2 == 0)
				ans = mid1 + mid2;
			else
				ans = mid1 * 2;
			if (TC[i] >= ans)
				total++;
			arr[TC[i - d]]--;
			arr[TC[i]]++;

		}
		cout << total << "\n";
	}
	
	return 0;
}