﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
    free(time1);
    free(time2);
}

//파일 1의 정보를 가져오는 함수 작성 - 이민재
void filestat1(){
    stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성 - 이민재
void filestat2(){
    stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성 - 임강호
void filetime1(){
    time1 = (struct tm*)malloc(sizeof(struct tm));
    *time1 = *localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성 - 임강호
void filetime2(){
    time2 = (struct tm*)malloc(sizeof(struct tm));
    *time2 = *localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성 - 이민재
void sizecmp(){
    printf("size compare\n");
    int text1Size = stat1.st_size;
    int text2Size = stat2.st_size;
    if(text2Size - text1Size > 0){
        printf("text2 is bigger\n\n");
    }
    else if(text2Size - text1Size == 0){
        printf("sizes are equal\n\n");
    }
    else{
        printf("text1 is bigger\n\n");
    }
}

//두 개의 파일 블락 수를 비교하는 함수 작성 - 임강호
void blockcmp(){
    printf("block compare\n");
    int text1Size = stat1.st_blocks;
    int text2Size = stat2.st_blocks;
    if(text1Size > text2Size){
        printf("text1 is bigger\n\n");
    }
    else if(text1Size < text2Size){
        printf("tetx2 is bigger\n\n");
    }
    else{
        printf("blocksize is equal\n\n");
    }	
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성 - 박지원
void datecmp(){
    printf("date compare\n");
    if(time1->tm_mon == time2->tm_mon){
        if(time1->tm_mday == time2->tm_mday) printf("same date\n\n");
        else if(time1->tm_mday > time2->tm_mday) printf("text2 is early\n\n");
        else printf("text1 is early\n\n");
    }
    else if(time1->tm_mon > time2->tm_mon) printf("text2 is early\n\n");
    else printf("text1 is early\n\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성 - 박지원
void timecmp(){
    printf("time compare\n");
    if(time1->tm_hour == time2->tm_hour){
        if(time1->tm_min == time2->tm_min) printf("same time\n\n");
        else if(time1->tm_min > time2->tm_min) printf("text2 is early\n\n");
        else printf("text1 is early\n\n");
    }
    else if(time1->tm_hour > time2->tm_hour) printf("text2 is early\n\n");
    else printf("text1 is early\n\n");
}
