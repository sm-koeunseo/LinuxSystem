# 가장 많은 급여를 받는 직원의 이름과 급여만 출력

BEGIN{
	salary=0
}
$5>salary{
	name=$2
	salary=$5
}
END{
	printf "name: %s, sal: %s\n", name, salary
}
