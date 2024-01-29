#include <stdio.h>
#include <string.h>

/* 텍스트 파일 내용을 표준출력에 프린트 */
int main(int argc, char *argv[])
{
	FILE *fp;
	int c, i, count, flag;
	
	if (argc < 2){
		fp = stdin;
		
		c = fgetc(fp);
		while (c != EOF) {
			fputc(c, stdout);
			c = fgetc(fp);
		}
		fclose(fp);
	} else{
		if (argv[1][0] == '-'){
			if (argv[1][1] == 'n'){
				if (argc == 2){
					count = 1;
					flag = 0;
					fp = stdin;
			
					c = fgetc(fp);
					
					printf("	%d ",count++); 
					while (c != EOF) {
						if (flag && c!='\n'){
							printf("	%d ",count++);
							flag = 0;
						}
						fputc(c, stdout);
						c = fgetc(fp);
						if (c=='\n')
							flag = 1; 
					}
					fclose(fp);
				}else
					for (i=2; i<argc; i++){
						count = 1;
						flag = 0;
						fp = fopen(argv[i], "r");
					
						if (fp == NULL)
							printf("파일 열기 오류 %s\n", argv[i]);
						else {
							c = fgetc(fp);
							printf("	%d ",count++);
							while (c != EOF) {
								if (flag && c!='\n'){
									printf("	%d ",count++);
									flag = 0;
								}
								fputc(c, stdout);
								c = fgetc(fp);
								if (c=='\n')
									flag = 1;
							}
							fclose(fp);
						}
					}
			} else
				printf("-n을 사용하세요.\n");
		} else
			for (i=1; i<argc; i++){
				fp = fopen(argv[i], "r");
				
				if (fp == NULL)
					printf("파일 열기 오류 %s\n", argv[i]);
				else {
					c = fgetc(fp);
					while (c != EOF) {
						fputc(c, stdout);
						c = fgetc(fp);
					}
					fclose(fp);
				}
			}
	}
	return 0;
}
