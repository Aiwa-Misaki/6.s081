//#include "kernel/types.h"
//#include "kernel/stat.h"
//#include "user/user.h"
//#include <string.h>
//
//int main(int argc, char *argv[]) {
//    int pipefd1[2]; // child to parent
//    int pipefd2[2]; // parent to child
//    if (pipe(pipefd1) == -1) {
//        fprintf(stderr, "pipe creation failed\n");
//        exit(1);
//    }
//    if (pipe(pipefd2) == -1) {
//        fprintf(stderr, "pipe creation failed\n");
//        exit(1);
//    }
//    int pid = fork();
//
//    if (pid == -1) {
//        fprintf(stderr, "fork failed\n");
//        exit(1);
//    } else if (pid == 0) { // child
//        char buf[30];
//        int bytes_read = read(pipefd1[0], buf, 29);
//        if (bytes_read == -1) {
//            fprintf(stderr, "child process read failed\n");
//            exit(1);
//        }
//        buf[bytes_read] = '\0'; // 确保字符串正确终止
//        fprintf(stdout, "%d: received ping\n", getpid());
//        // 似乎您想发送进程ID回去，但是忘了定义和设置msg
//        char msg[30];
//        sprintf(msg, "%d", getpid());
//        if (write(pipefd2[1], msg, strlen(msg) + 1) == -1) {
//            fprintf(stderr, "write to pipe failed\n");
//            exit(1);
//        }
//    } else { // parent
//        char msg[30];
//        sprintf(msg, "ping from %d", getpid());
//        if (write(pipefd1[1], msg, strlen(msg) + 1) == -1) {
//            fprintf(stderr, "write to pipe failed\n");
//            exit(1);
//        }
//        wait((int *) 0); // 等待子进程完成
//        char buf[30];
//        int bytes_read = read(pipefd2[0], buf, 29);
//        if (bytes_read == -1) {
//            fprintf(stderr, "parent process read failed\n");
//            exit(1);
//        }
//        buf[bytes_read] = '\0';
//        fprintf(stdout, "%s: received pong\n", buf);
//    }
//    exit(0);
//}
