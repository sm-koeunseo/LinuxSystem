#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[10][MAXLINE];
char temp[MAXLINE];

int main()
{
	int len, max = 0, num = 0, i, j;
	
	while (fgets(line[num], MAXLINE, stdin) != NULL) {
		num++;
	}
	
	for (i = num - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strlen(line[j]) > strlen(line[j+1])) {
				copy(line[j], temp);
				copy(line[j+1], line[j]);
				copy(temp, line[j+1]);
			}
		}
	}
	
	printf("-----정렬 완료-----\n");
	
	for (i = 0; i < num; i++) {
		printf("%s", line[i]);
	}
	
	return 0;
}
