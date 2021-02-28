#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T, n, a, b;
	int count;
	string s;
	vector<pair<int, int>> item;
	cin >> T;

	while (T--)
	{
		item.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> a >> b;
			item.push_back(pair<int, int>(a, b));
		}
		sort(item.begin(), item.end());
		count = 1;
		int temp = n - 1;
		for(int i = n - 1;i>=0;i--)
		{
			if (item[temp].first >= item[i].second)
			{
				temp = i;
				count++;
				if (temp == n - 1)
					count--;
			}
			if (item[temp].first < item[i].first)
			{
				item[temp].first = item[i].first;
			}
		}
		cout << count << "\n";
	}

	return 0;
}