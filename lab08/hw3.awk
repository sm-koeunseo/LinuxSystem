# 각 부처별 급여액과 전체 급여액을 계산하여 출력

{
	salary[$4] += $5
	total += $5
}
END{
	for (dept in salary){
		printf "부서: %s, 월급: %s\n", dept, salary[dept]
	}
	printf "전체 급여액: %s\n", total
}
