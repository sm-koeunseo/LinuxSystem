#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAXARG 10
#define MAXCHAR 100
#define MAXJOBS 10

int main() {
    char command[MAXCHAR];
    char *args[MAXARG];
    int pid, status, isBackground;
    int jobCount = 0;
    
    struct {
    	int jobNumber;
    	int processID;
    } jobs[MAXJOBS];

    while (1) {
    	// 입력
        printf("[shell] ");
        fgets(command, sizeof(command), stdin);

        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }
        
        if (strcmp(command, "quit") == 0)
            break;

        // 명령줄 인수로 분리
        char *token;
        char *saveptr;
        token = strtok_r(command, " ", &saveptr);
        int i = 0;

        while (token != NULL && i < MAXARG - 1) {
            args[i++] = token;
            token = strtok_r(NULL, " ", &saveptr);
        }
        args[i] = NULL;
        
        // 전면 실행 여부 확인
        isBackground = (i > 0 && strcmp(args[i - 1], "&") == 0);
        if (isBackground) {
            args[i - 1] = NULL;  // & 제거
        }

        // 자식 프로세스 생성
        pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            fprintf(stderr, "실행 실패\n");
            exit(1);
        } else if (pid > 0) {
            // 전면 실행이면 기다림
            if (isBackground) {
                jobs[jobCount].jobNumber = jobCount + 1;
                jobs[jobCount].processID = pid;
                
                printf("[%d] %d\n", jobs[jobCount].jobNumber, jobs[jobCount].processID);
                jobCount++;
            } else
            	waitpid(pid, &status, 0);
        } else {
            perror("fork");
            exit(1);
        }
    }
    return 0;
}
