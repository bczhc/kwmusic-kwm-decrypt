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


void PrintArr(const char arr[], int len) {
    int l_ = len - 1;
    printf("[\n");
    for (int i = 0; i < l_; ++i) {
        if (i == 16) printf("\n");
        printf("%i%c", (int) arr[i], 44);
    }
    printf("\n%i]___%u", (int) arr[l_ - 1], (l_ + 1));
}

long long getFileSize(FILE *fp) {
    long long sz;
    fseek(fp, 0L, SEEK_END);
    sz = (long long) ftell(fp);
    if (sz == -1) {
        sz = _ftelli64(fp);
        printf("Get file size error.\n");
    }
    fseek(fp, 0L, SEEK_SET);
    return sz;
}

/*int cmpIntArray(const int *a1, const int a1Len, const int *a2, const int a2Len) {
    if (a1Len != a2Len) return 0;
    else {
        for (int i = 0; i < a1Len; ++i) {
            if (a1[i] != a2[i]) return 0;
        }
    }
    return 1;
}*/
int cmpCharArray(const char *a1, const int a1Len, const char *a2, const int a2Len) {
    if (a1Len != a2Len) return 0;
    else {
        for (int i = 0; i < a1Len; ++i) {
            if (a1[i] != a2[i]) return 0;
        }
    }
    return 1;
}