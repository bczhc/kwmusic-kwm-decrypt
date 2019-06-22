//
// Created by zhc-2 on 2019/6/22.
//

#include "kwm.h"

#define MAX_FIND_KEY_TIME 468

int main(const int argc, char **argv) {
    if (argc != 3) {
        printf("Command [filePath] [destFilePath]\n");
        return 1;
    } else {
        int haveFoundKey = 0;
        char *fN = argv[1];
        char *dFN = argv[2];
        FILE *fp = NULL, *fpO = NULL;
        if ((fp = fopen(fN, "rb")) == NULL) {
            printf("fopen error.");
            return -1;
        }
        if ((fpO = fopen(dFN, "wb")) == NULL) {
            printf("fopen error.");
            return -1;
        }
        char key[32] = {0}, old_key[32] = {0};
        dl fS = getFileSize(fp), a = fS / 1024;
        usi b = (usi) fS % 1024;
        fseek(fp, 1024L, SEEK_SET);
        for (int i = 0; i < MAX_FIND_KEY_TIME; ++i) {
            fread(key, 32, 1, fp);
            int cmpR = cmpCharArray(key, 32, old_key, 32);
            if (cmpR) {
                haveFoundKey = 1;
                break;
            }
            for (int j = 0; j < 32; ++j) {
                old_key[j] = key[j];
            }
        }
        if (!haveFoundKey) {
            char *newKey = NULL;
            newKey = (char *) malloc(32);
            for (int i = 0; i < 16; ++i) {
                newKey[i] = key[i + 16];
            }
            for (int j = 16; j < 32; ++j) {
                newKey[j] = key[j - 16];
            }
            for (int k = 0; k < 32; ++k) {
                key[k] = newKey[k];
            }
            free(newKey);
        }
        fseek(fp, 1024L, SEEK_SET);
        printf("key: ");
        PrintArr(key, ARR_len(key));
        printf("\n");
        char buf[1024] = {0};
        for (int l = 1; l < a; ++l) {
            fread(buf, 1024, 1, fp);
            for (int i = 0; i < 1024; ++i) {
                buf[i] ^= key[i & 31];
            }
            fwrite(buf, 1024, 1, fpO);
        }
        if (b) {
            fread(buf, b, 1, fp);
            for (int i = 0; i < b; ++i) {
                buf[i] ^= key[i & 31];
            }
            fwrite(buf, b, 1, fpO);
        }
    }
    return 0;
}