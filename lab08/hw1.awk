# 이름과 이메일만 출력

{
	for (i = length($0); i > 0; i--)
		printf "%s", substr($0, i, 1)
	printf "\n"
}
