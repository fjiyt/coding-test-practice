#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define MAX_TEAM 6
#define MAX_SCORE 6
#define MAX_ID 100001

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int mID;
    struct Node* next;
} Node;

typedef struct List{
    Node* head;
    Node* tail;
    int size;
} List;

List *heap[MAX_TEAM][MAX_SCORE];
int team[MAX_ID];

void init(){ 
    for(int i=0; i<MAX_TEAM; i++)
    {
        for(int j=0; j<MAX_SCORE; j++)
        {
            LinkedListInit(heap[i][j]);
        }
    }
}

int isLinkedListEmpty(int mTeam, int mScore)
{
    int result;

    if(heap[mTeam][mScore]->size==0)
    {
        result = 1;
    }
    else{
        result = 0;
    }

    return result;
}

void LinkedListInit(List* list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}
void LinkedListDelete(int mTeam, int mScore)
{
    Node *del;

    for(int i=0; i<heap[mTeam][mScore]->size; i++)
    {
        del = heap[mTeam][mScore]->head;
        heap[mTeam][mScore]->head = heap[mTeam][mScore]->head->next;
        free(del);
    }

    LinkedListInit(heap[mTeam][mScore]);
}

void hire(int mID, int mTeam, int mScore){
    Node* add;
    add = (Node*)malloc(sizeof(Node));
    if(add==NULL) {
        return;
    }
    else{
        add-> mID = mID;
        add->next = heap[mTeam][mScore]->head;
        heap[mTeam][mScore]->head = add;

        if(isLinkedListEmpty(mTeam, mScore)==1)
        {
            heap[mTeam][mScore]->tail = add;
        }

        heap[mTeam][mScore]->size++;
        team[mID]=mTeam;
    }
}
void fire(int mID){
    int t = team[mID];
    for(int i=1; i<=5; i++)
    {
        int s = heap[t][i]->size;
        Node* cur = heap[t][i]->head;

        if(s==0) return;
        else if(s==1) {
            heap[t][i]->size--;
            heap[t][i]->head = NULL;
            heap[t][i]->tail = NULL;
            free(cur);
        }
        else{
            Node* next = cur->next;
            Node* del;
            for(int j=1; j<s; j++)
            {
                if(next==NULL) break;
                if(next->mID==mID)
                {
                    del = next;
                    cur->next = next->next;
                    free(del);
                    heap[t][i]->size--;
                }
                else{
                    cur = next;
                    next = next->next;
                }
            }
        }
        
    }
}
void updateSoldier(int mID, int mScore){
    int t = team[mID];
    Node* cur;

    for(int i=1; i<=5; i++)
    {
        cur = heap[t][i]->head;
        for(int j=0; j<heap[t][i]->size; j++)
        {
            if(cur->mID==mID)
            {
                // 제거

            }
        }
    }
}
void updateTeam(int mTeam, int mChangeScore){
}
int bestSoldier(int mTeam){
    int result = 0;
    for(int i=5; i>=1; i--)
    {
        int s = heap[mTeam][i]->size;
        if(s==0) continue;
        // 가장 mID 큰 경우
        Node* cur = heap[mTeam][i]->head;
        for(int j=0; j<s; j++)
        {
            if(result < cur->mID){
                result = cur->mID;
            }
        }
    }

    return result;
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