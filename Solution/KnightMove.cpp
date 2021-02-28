#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int dirx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int diry[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int visited[500][500];
int cnt[500][500];
int x, y, _x, _y;

void init()
{
	memset(visited, 0, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	queue<pair<int, int>> empty;
	swap(q, empty);
}
void BFS(int x, int y, int L)
{
	q.push(make_pair(x, y));
	visited[x][y]++;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == _x && y == _y)
		{
			cout << cnt[x][y] << "\n";
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			int dx = x + dirx[i];
			int dy = y + diry[i];
			if (dx >= 0 && dx <= L && dy >= 0 && dy <= L)
			{
				if (visited[dx][dy] == 0)
				{
					visited[dx][dy]++;
					q.push(make_pair(dx, dy));
					cnt[dx][dy] = cnt[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	int T;
	int L;

	cin >> T;

	while (T--)
	{
		init();

		cin >> L;
		cin >> x >> y;
		cin >> _x >> _y;
		
		BFS(x, y, L);
	}

	return 0;
}