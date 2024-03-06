//
// Created by duck on 2024/2/28.
//


#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(2, "Usage: sleep ...\n");
        exit(1);
    }

    int num = atoi(argv[1]);

    if (sleep(num) < 0) {
        fprintf(2, "sleep: cant sleep less than 0 s\n");
        exit(1);
    } else {
        fprintf(2, "sleep success\n");
    }

    exit(0);
}
