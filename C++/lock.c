#include <stdio.h>
#include <stdlib.h>

#define M 1024

int encryption(char fname[])
{
    char data[M];
    char key[] = { "!@#$%^*()_><,." };
    FILE *fp;
    char *mode = "r+";
    long rpos, wpos; //읽기 위치, 쓰기 위치
    size_t rsize; //read size

    if(fopen(fname,mode)==NULL)
    {
        fprintf(stderr,"fopen error for %s\n",fname);
        exit(1);
    }

    while(!feof(fp))
    {
        wpos = ftell(fp); //작성 위치
        rsize = fread(data,1,1024,fp); //읽은 데이터 수
        
        if(rsize == 0) break;

        for(int i=0; i<rsize; i++)
        {
            data[i] ^= key[i%16];
        }

        rpos = ftell(fp); //읽을 위치
        fseek(fp, wpos, SEEK_SET);
        fwrite(data,1,rsize,fp);
        fseek(fp,rpos,SEEK_SET);
    }

    fclose(fp);
    return 1;
}
int main(int argc, char *argv[])
{
    char fname[100];
    printf("file name: ");
    scanf("%s",fname);
    encryption(fname);

    return 0;
}