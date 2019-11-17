//
// Created by zhc-2 on 2019/6/22.
//

#ifndef C99_KWM_H
#define C99_KWM_H

#include <stdio.h>
#include <stdlib.h>

#define ARR_len(x) sizeof(x) / sizeof(x)[0]
#define dl long long
#define usi unsigned int
#endif //C99_KWM_H
//#include "../zhc.h"

void PrintArr(const char arr[], int len);

long long getFileSize(FILE *fp);

int cmpCharArray(const char *a1, const int a1Len, const char *a2, const int a2Len);