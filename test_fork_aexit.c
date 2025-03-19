#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 定义一个函数指针类型
typedef void (*exit_callback_t)(void);

// 需要在子进程退出时调用的函数
void on_child_exit(void) {
    printf("Child process (PID: %d) is exiting.\n", getpid());
}

int main() {
    // 在 fork 之前注册回调函数
    exit_callback_t callback = on_child_exit;
    atexit(callback);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    
    if (pid == 0) { // 子进程
        printf("Child process started (PID: %d).\n", getpid());
        // 在子进程中注册退出回调
        exit(0); // 触发 atexit 注册的回调
    } else { // 父进程
        printf("Parent process (PID: %d) waiting for child.\n", getpid());
        wait(NULL); // 等待子进程退出
        printf("Parent process detected child exit.\n");
    }
    
    return 0;
}
