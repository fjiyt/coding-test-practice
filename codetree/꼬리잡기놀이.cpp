#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 21
#define EMPTY 0
#define HEAD 1
#define MID 2
#define TAIL 3
#define LINE 4
using namespace std;

struct PATH {
	int y, x, d;
};
vector<PATH> path; // 매 라운드마다 공이 날아오는 정보

struct POS {
	int y, x;
};
vector<POS> header; // 머리 사람 

int ans = 0;
int N, M, K;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == HEAD) header.push_back({ i,j });
		}
	}
}

void print_map() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		} cout << "\n";
	}
}

void make_round() {

	// round 1 ~ n
	for (int row = 0; row < N; row++) path.push_back({ row, 0, 3 }); // 좌 -> 우

	// round n+1 ~ 2n
	for (int col = 0; col < N; col++) path.push_back({ N - 1, col, 0 }); // 하 -> 상

	// round 2n+1 ~ 3n
	for (int row = N - 1; row >= 0; row--) path.push_back({ row, N - 1, 2 }); // 우 -> 좌

	// round 3n+1 ~ 4n
	for (int col = N - 1; col >= 0; col--) path.push_back({ 0, col, 1 }); // 상 -> 하
}

void move_team() { // 각 팀은 머리사람을 따라서 한 칸 이동

	memset(visited, false, sizeof(visited));

	for (int team = 0; team < M; team++) {

		int y = header[team].y;
		int x = header[team].x;

		bool flag = true;
		while (flag) {

			for (int d = 0; d < 4; d++) { // 자신의 위치를 기준으로 상하좌우 탐색
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || !map[ny][nx]) continue; // 범위를 벗어나는 경우, EMPTY인 경우
				if (map[y][x] == HEAD && !visited[y][x]) {
					if (map[ny][nx] == LINE || map[ny][nx] == TAIL) { // HEAD가 가야할 방향
						header[team].y = ny;
						header[team].x = nx;
						visited[y][x] = true;
						tmp_map[ny][nx] = HEAD;
					}
				}
				else if (map[ny][nx]!=EMPTY && !visited[ny][nx]) { // 앞으로 한 칸 이동
					tmp_map[y][x] = map[ny][nx];
					visited[ny][nx] = true;
					y = ny; x = nx;
					if (tmp_map[ny][nx] == HEAD) flag = false;
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp_map[i][j];
			tmp_map[i][j] = 0; // 초기화
		}
	}
}

void get_ball(int i, int j) { // 공을 획득한 사람의 좌표

	//cout << i << " " << j << "- 공 맞은 사람 \n";

	memset(dist, 0, sizeof(dist));

	// 1. 머리 사람으로부터 몇번 째 사람인지 구함
	int k = 0;
	POS h = { 0,0 }, t = { 0,0 };
	queue<pair<int, int>> q;
	q.push({ i, j });
	dist[i][j] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == HEAD) {
			h = { y, x };
			k = dist[y][x]; // HEAD 까지의 거리
		}
		else if (map[y][x] == TAIL) t = { y,x };

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || dist[ny][nx] || map[ny][nx] == EMPTY) continue; // 경계를 벗어나는 경우, 이미 방문한 경우, EMPTY인 경우
			if (map[y][x] == TAIL && map[ny][nx] == HEAD || map[y][x] == HEAD && map[ny][nx] == TAIL) continue; // 거리를 반대 방향으로 계산하는 경우
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny,nx });
		}
	}

	// 2. 점수를 획득함 (K^2)
	ans += k * k;

	// 3. 머리 사람과 꼬리 사람이 바뀜 (방향이 바뀜)
	map[h.y][h.x] = TAIL;
	map[t.y][t.x] = HEAD;
	for (int team = 0; team < M; team++) {
		if (header[team].y == h.y && header[team].x == h.x) {
			header[team].y = t.y;
			header[team].x = t.x;
		}
	}
}

void throw_ball(int round) {

	int y = path[round].y;
	int x = path[round].x;
	int d = path[round].d;

	y -= dy[d]; x -= dx[d]; // 시작점부터 체크하기 위해

	for (int i = 0; i < N; i++) { // 공이 던져짐
		y += dy[d];
		x += dx[d];
		if (map[y][x] == EMPTY || map[y][x] == LINE) continue; // 사람이 없는 경우
		get_ball(y, x);
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	make_round();

	int round = 0;
	for (int k = 1; k <= K; k++) {
		move_team(); 
		//print_map();
		throw_ball(round); 
		//print_map();
		//cout << ans << " is ans \n";
		round = (round + 1) % (4 * N);
	}
	cout << ans;
}
