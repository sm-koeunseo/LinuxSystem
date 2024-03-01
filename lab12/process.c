#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;
	int count = 0;
	
	printf("[%d] 프로세스 시작 \n", getpid());
	pid = fork();
	printf("[%d] %d 프로세스 : 반환값 %d \n", getpid(), count++, pid);
	pid = fork();
	printf("[%d] %d 프로세스 : 반환값 %d \n", getpid(), count++, pid);
}
