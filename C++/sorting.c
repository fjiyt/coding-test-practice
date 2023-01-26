int main()
{
    LARGE_INTEGER Frequency;
    LARGE_INTEGER BeginTime;
    LARGE_INTEGER Endtime;
    QueryPerformanceFrequency(&Frequency);

    //변수 생성 및 초기화
    srand(time(NULL));
    float sortNum[N] = {
        0,
    }; //생성된 번호를 저장할 배열
    //변수 생성부분
    printf("변수 생성\n");
    for (int i = 0; i < N; i++)
    {
        sortNum[i] = rand() % 100 / 100.0 + rand() % 2 - 1;
        printf("%.3f // ", sortNum[i]);
    }
    printf("\n");

    //교환정렬
    printf("교환정렬결과\n");
    float eNum[N] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        eNum[i] = sortNum[i];
    }
    QueryPerformanceCounter(&BeginTime); //시간 측정 시작
    exchangesort(N, eNum);
    QueryPerformanceCounter(&Endtime); //시간 측정 종료
    long long elapsed = Endtime.QuadPart - BeginTime.QuadPart;
    double duringtime = (double)elapsed / (double)Frequency.QuadPart;
    printf("시간 : %f\n", duringtime);
    Print(eNum);

    //삽입정렬
    printf("삽입정렬결과\n");
    float iNum[N] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        iNum[i] = sortNum[i];
    }
    QueryPerformanceCounter(&BeginTime); //시간 측정 시작
    insertionsort(N, iNum);
    QueryPerformanceCounter(&Endtime); //시간 측정 종료
    elapsed = Endtime.QuadPart - BeginTime.QuadPart;
    duringtime = (double)elapsed / (double)Frequency.QuadPart;
    printf("시간 : %f\n", duringtime);
    Print(iNum);

    //합병정렬
    printf("합병정렬결과\n");
    float mNum[N] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        mNum[i] = sortNum[i];
    }
    QueryPerformanceCounter(&BeginTime); //시간 측정 시작
    mergesort(mNum, 0, N - 1);
    QueryPerformanceCounter(&Endtime); //시간 측정 종료
    elapsed = Endtime.QuadPart - BeginTime.QuadPart;
    duringtime = (double)elapsed / (double)Frequency.QuadPart;
    printf("시간 : %f\n", duringtime);
    Print(mNum);

    //퀵정렬
    printf("퀵정렬결과\n");
    float qNum[N] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        qNum[i] = sortNum[i];
    }
    QueryPerformanceCounter(&BeginTime); //시간 측정 시작
    quicksort(qNum, 0, N - 1);
    QueryPerformanceCounter(&Endtime); //시간 측정 종료
    elapsed = Endtime.QuadPart - BeginTime.QuadPart;
    duringtime = (double)elapsed / (double)Frequency.QuadPart;
    printf("시간 : %f\n", duringtime);
    Print(qNum);

    return 0;
}