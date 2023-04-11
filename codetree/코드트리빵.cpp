#include <iostream>
#include <climits>
#include <queue>
#include <tuple>

#define MAX_N 15
#define MAX_M 30
#define DIR_NUM 4
#define EMPTY make_pair(-1,-1)

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
pair <int, int> people[MAX_M];
pair <int, int> cvs_list[MAX_M];
int Time = 0;

bool isVisited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

int dx[DIR_NUM] = {-1,0,0,1};
int dy[DIR_NUM] = {0,-1,1,0};

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
bool CanGo(int x, int y)
{
	return InRange(x, y) && grid[x][y] != 2 && !isVisited[x][y];
}
void BFS(pair <int,int> s)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			isVisited[i][j] = false;
			step[i][j] = 0;
		}
	}

	queue <pair<int, int> > que;
	que.push(s);
	isVisited[s.first][s.second] = true;
	step[s.first][s.second] = 0;

	while (!que.empty())
	{
		pair <int, int> cur = que.front();
		que.pop();
		int x = cur.first;
		int y = cur.second;

		for (int i = 0; i < DIR_NUM; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (CanGo(nx, ny))
			{
				que.push({ nx,ny });
				isVisited[nx][ny] = true;
				step[nx][ny] = step[x][y] + 1;
			}
		}
	}
}
void Simulate()
{
	//이동
	for (int i = 0; i < m; i++)
	{
		if (people[i] == EMPTY || people[i] == cvs_list[i])
		{
			continue;
		}

		BFS(cvs_list[i]);

		int px, py;
		tie(px, py) = people[i];

		int min_dst = INT_MAX;
		int min_x=-1, min_y=-1;
		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (InRange(nx, ny) && isVisited[nx][ny] && min_dst > step[nx][ny] && grid[nx][ny]!=2)
			{
				min_dst = step[nx][ny];
				min_x = nx;
				min_y = ny;
			}
		}

		people[i] = make_pair(min_x, min_y);
	}
	// 편의점에 도착했는지 확인
	for (int i = 0; i < m; i++)
	{
		if (people[i] == cvs_list[i]) {
			int px, py;
			tie(px, py) = people[i];
			grid[px][py] = 2;
		}
	}
	//베캠으로 이동
	if (Time <= m)
	{
		BFS(cvs_list[Time-1]);
		
		int min_dst = INT_MAX;
		int min_x = -1, min_y = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1 && isVisited[i][j] && min_dst > step[i][j])
				{
					min_dst = step[i][j];
					min_x = i, min_y = j;
				}
			}
		}

		people[Time-1] = make_pair(min_x, min_y);
		grid[min_x][min_y] = 2;
	}
}

bool End()
{
	for (int i = 0; i < m; i++)
	{
		if (people[i] != cvs_list[i])
			return false;
	}

	return true;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		cvs_list[i] = make_pair(x - 1, y - 1);
	}

	for (int i = 0; i < m; i++)
	{
		people[i] = make_pair(-1, -1);
	}

	while (1)
	{
		Time++;
		Simulate();
		if (End()) break;
	}

	cout << Time << "\n";
}