# 파일의 내용을 줄 단위 역순으로 출력

{
	lines[NR] = $0
}
END {
	for(i=NR;i>0;i--)
		print(lines[i])
}
