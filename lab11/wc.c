#include <stdio.h>
#include <string.h>

/* 텍스트 파일 내용을 표준출력에 프린트 */
int main(int argc, char *argv[])
{
	FILE *fp;
	int c, i, num_l = 0, num_w = 0, num_c = 0;
	
	if (argc < 2){
		fp = stdin;
		
		c = fgetc(fp);
		while (c != EOF) {
			num_c++;
			if (c == ' ')
				num_w++;
			if (c == '\n'){
				num_w++;
				num_l++;
			}
			c = fgetc(fp);
		}
		fclose(fp);
		printf("	%d	%d	%d\n", num_l, num_w, num_c);
	} else{
		fp = fopen(argv[1], "r");
		
		if (fp == NULL)
			printf("파일 열기 오류 %s\n", argv[1]);
		else {
			c = fgetc(fp);
			while (c != EOF) {
				num_c++;
				if (c == ' ')
					num_w++;
				if (c == '\n'){
					num_w++;
					num_l++;
				}
				c = fgetc(fp);
			}
			fclose(fp);
			printf("	%d	%d	%d %s\n", num_l, num_w, num_c, argv[1]);
		}
	}
	return 0;
}
