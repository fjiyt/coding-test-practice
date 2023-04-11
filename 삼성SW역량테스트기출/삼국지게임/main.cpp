// union-find 사용하기
// hashmap 이용?? -> 동맹을 하면 전부다 값을 변경을 해주게, hashmap을 써서 만약 동맹관계에서 같은 값을 넣어주면됨
// 한숫자로 구역을 나누어줌

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_ALLY 300
#define CMD_ATTACK 400
#define CMD_RECRUIT 500

/////////////////////////////////////////////////////////////////////////
extern void init(int N, int mSoldier[25][25], char mGeneral[25][25][11]);
extern void destroy();
extern int ally(char mMonarchA[11], char mMonarchB[11]);
extern int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11]);
extern int recruit(char mMonarch[11], int mNum, int mOption);
/////////////////////////////////////////////////////////////////////////

#define MAX_N 25
#define MAX_L 10

struct pos{
	int x = -1;
	int y = -1;
};

typedef struct Node
{
	int x;
	int y;
	char Monarch[MAX_L + 1];
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct
{ 
	Node* head;
	Node* tail;
} List;

static int Sol[MAX_N][MAX_N];
static char General[MAX_N][MAX_N][MAX_L + 1];
int Num;
// List Union[MAX_N][MAX_N];
// List Enemy[MAX_N][MAX_N];
// Node* soldiers[MAX_N][MAX_N];
vector <pos> Union[MAX_N][MAX_N];
vector <pos> Enemy[MAX_N][MAX_N];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

Node* NodeInit(Node *tmp)
{
    tmp = new Node();
    tmp->prev = NULL;
    tmp->next = NULL;
    tmp->x = -1;
    tmp->y = -1;

    return tmp;
}
void LinkedListInit(List *list)
{
    list->head = NodeInit(list->head);
    list->tail = NodeInit(list->tail);
    list->head->next = list->tail;
    list->tail->prev = list->head;
}

void init(int N, int mSoldier[25][25], char mGeneral[25][25][11])
{
	Num = N;
}

void destroy()
{
}
bool isUnion(pos A, pos B)
{
	for(int i=0; i<Union[A.x][A.y].size(); i++)
	{
		if(Union[A.x][A.y][i].x == B.x && Union[A.x][A.y][i].y == B.y)
		{
			return true;
		}
	}
	return false;
}
bool isEnemy(pos A, pos B)
{
	for(int i=0; i<Enemy[A.x][A.y].size(); i++)
	{
		if(Enemy[A.x][A.y][i].x == B.x && Enemy[A.x][A.y][i].y == B.y)
		{
			return true;
		}
	}
	return false;
}
int ally(char mMonarchA[11], char mMonarchB[11])
{
	pos A;
	pos B;
	if(mMonarchA == mMonarchB) return -1;
	for(int i=0; i<Num; i++)
	{
		for(int j=0; j<Num; j++)
		{
			if(General[i][j]==mMonarchA)
			{
				A.x = i;
				A.y = j;
			}
			if(General[i][j]==mMonarchB)
			{
				B.x = i;
				B.y = j;
			}
		}
	}
	// 이미 동맹 관계인지 확인
	if(isUnion(A, B)) return -1;
	if(isEnemy(A, B)) return -2;

	// 동맹맺기
	Union[A.x][A.y].push_back(B);
	Union[B.x][B.y].push_back(A);

	// 원래 있던 동맹도 맺기
	vector <pos> tmp;
	for(int i=0; i<Union[B.x][B.y].size(); i++)
	{
		tmp.push_back(Union[B.x][B.y][i]);
	}
	for(int i=0; i<Union[A.x][A.y].size(); i++)
	{
		Union[B.x][B.y].push_back(Union[A.x][A.y][i]);
	}
	for(int i=0; i<tmp.size(); i++)
	{
		Union[A.x][A.y].push_back(tmp[i]);
	}
	return 1;
}
int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11])
{
	// 동맹인지 확인
	if(mMonarchA == mMonarchB) return -1;
	pos A;
	pos B;
	for(int i=0; i<Num; i++)
	{
		for(int j=0; j<Num; j++)
		{
			if(General[i][j]==mMonarchA)
			{
				A.x = i;
				A.y = j;
			}
			if(General[i][j]==mMonarchB)
			{
				B.x = i;
				B.y = j;
			}
		}
	}
	if(isUnion(A,B)) return -1;

	// 인접한지 확인
	int attack_cnt = 0;
	for(int i=0; i<8; i++)
	{
		int nx = B.x + dx[i];
		int ny = B.y + dy[i];
		if(nx < 0 || ny < 0 || nx >= Num || ny >= Num) continue;
		if(nx==A.x && ny==A.y)
		{
			attack_cnt += Sol[nx][ny];
			Sol[nx][ny] = 0;
			continue;
		}
		for(int j=0; j<Union[nx][ny].size(); i++)
		{
			if(A.x == Union[nx][ny][j].x && A.y == Union[nx][ny][j].y)
			{
				attack_cnt += Sol[nx][ny]/2;
				Sol[nx][ny] -= Sol[nx][ny]/2;
			}
		}
	}
	if(attack_cnt==0) return -2;

	// 방어하는 군주 합
	int defence_cnt = Sol[B.x][B.y];
	Sol[B.x][B.y] = 0;
	for(int i=0; i<Union[B.x][B.y].size(); i++)
	{
		int nx = Union[B.x][B.y][i].x;
		int ny = Union[B.x][B.y][i].y;
		if(abs(nx-B.x) <=1 || abs(ny-B.y) <= 1)
		{
			defence_cnt += Sol[nx][ny]/2;
			Sol[nx][ny] -= Sol[nx][ny]/2;
		}
	}

	// 적대관계추가
	if(attack_cnt > defence_cnt)
	{
		// 기존 B의 관계 끊기
		memcpy(General[B.x][B.y], mGeneral, sizeof(mGeneral));
		Sol[B.x][B.y] = attack_cnt - defence_cnt;

		return 1;
	}
	else{
		Sol[B.x][B.y] = defence_cnt - attack_cnt;
		return 0;
	}
}
int recruit(char mMonarch[11], int mNum, int mOption)
{
	if(mOption==0)
	{
		pos P;
		for(int i=0; i<Num; i++)
		{
			for(int j=0; j<Num; j++)
			{
				if(General[i][j]==mMonarch)
				{
					P.x = i;
					P.y = j;
				}
			}
		}
		Sol[P.x][P.y] += mNum;
		return Sol[P.x][P.y];
	}
	else{
		pos P;
		for(int i=0; i<Num; i++)
		{
			for(int j=0; j<Num; j++)
			{
				if(General[i][j]==mMonarch)
				{
					P.x = i;
					P.y = j;
				}
			}
		}
		int total = Sol[P.x][P.y] + mNum;
		for(int i=0; i<Union[P.x][P.y].size(); i++)
		{
			int nx = Union[P.x][P.y][i].x;
			int ny = Union[P.x][P.y][i].y;

			if(nx==-1 || ny==-1) continue;
			Sol[nx][ny]+=mNum;
			total += Sol[nx][ny];
		}

		return total;
	}
}

static int run()
{
	int isOK = 0;

	int N;
	int cmd;
	int result;
	int check;

	int mN;
	char mMonarchA[11];
	char mMonarchB[11];
	char mGeneral[11];
	int mOption;
	int num;

	scanf("%d", &N);

	for (int c = 0; c < N; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &mN);
			for (int j = 0; j < mN; j++)
				for (int i = 0; i < mN; i++)
					scanf("%d", &Sol[j][i]);

			for (int j = 0; j < mN; j++)
				for (int i = 0; i < mN; i++)
					scanf("%s", General[j][i]);

			init(mN, Sol, General);
			isOK = 1;
			break;

		case CMD_ALLY:
			scanf("%s %s", mMonarchA, mMonarchB);
			result = ally(mMonarchA, mMonarchB);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		case CMD_ATTACK:
			scanf("%s %s %s", mMonarchA, mMonarchB, mGeneral);
			result = attack(mMonarchA, mMonarchB, mGeneral);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		case CMD_RECRUIT:
			scanf("%s %d %d", mMonarchA, &num, &mOption);
			result = recruit(mMonarchA, num, mOption);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		default:
			isOK = 0;
			break;
		}
	}

	destroy();

	return isOK;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}