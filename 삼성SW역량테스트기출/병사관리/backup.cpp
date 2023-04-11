#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAX_TEAM 6
#define MAX_SCORE 6
#define MAX_ID 100001

typedef struct Node
{
    int mID;
    int mTeam;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} List;

List heap[MAX_TEAM][MAX_SCORE];
Node* soldiers[MAX_ID];

Node* NodeInit(Node *tmp)
{
    tmp = new Node();
    tmp->prev = NULL;
    tmp->next = NULL;
    tmp->mID = 0;
    tmp->mTeam = 0;

    return tmp;
}

void LinkedListInit(List *list)
{
    list->head = NodeInit(list->head);
    list->tail = NodeInit(list->tail);
    list->head->next = list->tail;
    list->tail->prev = list->head;
}

void init(){ 
    for(int i=0; i<MAX_TEAM; i++)
    {
        for(int j=0; j<MAX_SCORE; j++)
        {
            LinkedListInit(&heap[i][j]);
        }
    }
}

void hire(int mID, int mTeam, int mScore){
    Node* add;
    add = NodeInit(add);

    // 링크드리스트에 추가
    add->mID=mID;
    add->mTeam=mTeam;
    add->next = heap[mTeam][mScore].tail;
    add->prev = heap[mTeam][mScore].tail->prev;
    heap[mTeam][mScore].tail->prev->next = add;
    heap[mTeam][mScore].tail->prev = add;
    
    // soldiers 배열에 추가
    soldiers[mID] = add;
}
void fire(int mID){
    Node* tmp = soldiers[mID];
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    NodeInit(tmp);
}
void updateSoldier(int mID, int mScore){
    Node* tmp = soldiers[mID];
    int team = tmp->mTeam;
    fire(mID);
    // 원래 team 구하기 -> hire()
    hire(mID, team, mScore);
}
void updateTeam(int mTeam, int mChangeScore){
    // 변화한 score 리스트에 head, tail 연결
    if(mChangeScore < 0)
    {
        for(int i=1; i<=5; i++)
        {
            int score = i+mChangeScore;
            if(score < 1) {
                score = 1;
            }

            if(i!=score)
            {
                // 링크드리스트 수정
                heap[mTeam][score].tail->prev->next = heap[mTeam][i].head->next;
                heap[mTeam][i].head->next->prev = heap[mTeam][score].tail->prev;
                heap[mTeam][i].tail->prev->next = heap[mTeam][score].tail;
                heap[mTeam][score].tail->prev = heap[mTeam][i].tail->prev;
                LinkedListInit(&heap[mTeam][i]);
            }
        }
    }
    else if(mChangeScore > 0)
    {
        for(int i=5; i>=1; i--)
        {
            int score = i+mChangeScore;
            if(score>5) {
                score = 5;
            }

            if(i!=score)
            {
                // 링크드리스트 수정
                heap[mTeam][score].tail->prev->next = heap[mTeam][i].head->next;
                heap[mTeam][i].head->next->prev = heap[mTeam][score].tail->prev;
                heap[mTeam][i].tail->prev->next = heap[mTeam][score].tail;
                heap[mTeam][score].tail->prev = heap[mTeam][i].tail->prev;
                LinkedListInit(&heap[mTeam][i]);
            }
        }
    }
    
}
int bestSoldier(int mTeam){
    int max_ID=0;
    for(int i=5; i>0; i--)
    {
        if(heap[mTeam][i].head->next == heap[mTeam][i].tail)
        {
            continue;
        }
        
        Node *tmp = heap[mTeam][i].head->next;
        while(tmp!=heap[mTeam][i].tail)
        {
            if(tmp->mID > max_ID) max_ID = tmp->mID;
            tmp=tmp->next;
        }
        if(max_ID!=0) return max_ID;
    }

    return max_ID;
}

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}