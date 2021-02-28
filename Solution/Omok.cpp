#include <iostream>
#include <string.h>
using namespace std;

int Pan[16][16];
int check(int x, int y, int color, int _x, int _y)
{
	if (x == 0 || y == 0 || x == 16 || y == 16)
		return 0;
	if (Pan[x][y] == color)
		return check(x + _x, y + _y, color, _x, _y) + 1;
	else
		return 0;
}
int win(int x, int y, int color)
{
	int upleft = check(x, y, color, -1, -1);
	int downright = check(x, y, color, 1, 1);
	if (upleft + downright - 1 == 5) return 1;

	int up = check(x, y, color, 0, -1);
	int down = check(x, y, color, 0, 1);
	if (up + down - 1 == 5) return 1;

	int upright = check(x, y, color, 1, -1);
	int downleft = check(x, y, color, -1, 1);
	if (upright + downleft - 1 == 5) return 1;

	int right = check(x, y, color, 1, 0);
	int left = check(x, y, color, -1, 0);
	if (right + left - 1 == 5) return 1;

	return 0;
}
void set()
{
	memset(Pan, 0, sizeof(Pan));
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	int a, b;
	int test = 0;
	int ans;

	cin >> T;

	while (T--)
	{
		ans = 0;
		test = 1;
		set();
		for (int i = 0; i < 225; i++)
		{
			cin >> a >> b;
			if (test % 2 == 1)
				Pan[a][b] = 1;
			else
				Pan[a][b] = 2;
			if (ans == 0)
			{
				if (win(a, b, 1) != 0)
				{
					cout << test << " B \n";
					ans++;
				}
				else if (win(a, b, 2) != 0)
				{
					cout << test << " W \n";
					ans++;
				}
			}
			test++;
		}
	}


	return 0;
}