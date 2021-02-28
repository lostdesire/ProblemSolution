#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
char Maze[20][20];
int visited[20][20][64];
int mask;
int key, newkey;
int level;
int T, M, N, x, y;
queue<pair<pair<int, int>, int>> q;

void init()
{
	queue<pair<pair<int, int>, int>> empty;
	swap(q, empty);
	memset(visited, 0, sizeof(visited));
	mask = 0;
	key = 0;
	level = 0;
}
int MazeMinimumMoves(char Maze[20][20], int M, int N)
{
	init();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			switch (Maze[i][j])
			{
			case 'a':
				mask += 1;
				break;
			case 'b':
				mask += 2;
				break;
			case 'c':
				mask += 4;
				break;
			case 'd':
				mask += 8;
				break;
			case 'e':
				mask += 16;
				break;
			case 'f':
				mask += 32;
				break;
			case '@':
				x = i;
				y = j;
				break;
			default:
				break;
			}
		}
	}
	q.push(make_pair(make_pair(x, y), 0));
	visited[x][y][0]++;
	while (!q.empty())
	{
		int Qsize = q.size();
		for (int i = 0; i < Qsize; i++)
		{
			x = q.front().first.first;
			y = q.front().first.second;
			key = q.front().second;
			q.pop();
			if (key == mask)
				return level;
			for (int j = 0; j < 4; j++)
			{
				int tempX = x + dx[j];
				int tempY = y + dy[j];
				if (tempX >= 0 && tempY >= 0 && tempX < N && tempY < M)
				{
					if ((Maze[tempX][tempY] == '*' || Maze[tempX][tempY] == '@')
						&& visited[tempX][tempY][key] == 0)
					{
						q.push(make_pair(make_pair(tempX, tempY), key));
						visited[tempX][tempY][key]++;
					}
					if ((Maze[tempX][tempY] == 'a' ||
						Maze[tempX][tempY] == 'b' ||
						Maze[tempX][tempY] == 'c' ||
						Maze[tempX][tempY] == 'd' ||
						Maze[tempX][tempY] == 'e' ||
						Maze[tempX][tempY] == 'f') &&
						visited[tempX][tempY][key] == 0)
					{
						switch (Maze[tempX][tempY])
						{
						case 'a':
							newkey = key + 1;
							break;
						case 'b':
							newkey = key + 2;
							break;
						case 'c':
							newkey = key + 4;
							break;
						case 'd':
							newkey = key + 8;
							break;
						case 'e':
							newkey = key + 16;
							break;
						case 'f':
							newkey = key + 32;
							break;
						default:
							break;
						}
						if (!visited[tempX][tempY][newkey])
						{
							q.push(make_pair(make_pair(tempX, tempY), newkey));
							visited[tempX][tempY][newkey]++;
						}
					}
					if (((Maze[tempX][tempY] == 'A' && key % 2 == 1) ||
						(Maze[tempX][tempY] == 'B' && (key / 2) % 2 == 1) ||
						(Maze[tempX][tempY] == 'C' && ((key / 2) / 2) % 2 == 1) ||
						(Maze[tempX][tempY] == 'D' && (((key / 2) / 2) / 2) % 2 == 1) ||
						(Maze[tempX][tempY] == 'E' && ((((key / 2) / 2) / 2) / 2) % 2 == 1) ||
						(Maze[tempX][tempY] == 'F' && (((((key / 2) / 2) / 2) / 2) / 2) % 2 == 1)) &&
						visited[tempX][tempY][key] == 0)
					{
						q.push(make_pair(make_pair(tempX, tempY), key));
						visited[tempX][tempY][key]++;
					}
				}
			}
		}
		level++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> M >> N;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Maze[j][i];
			}
		}

		cout << MazeMinimumMoves(Maze, M, N) << "\n";
	}

	return 0;
}