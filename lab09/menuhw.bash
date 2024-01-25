#!/bin/bash

echo -------------------------------------------------------
echo 나의 명령어 메뉴에 오신 것을 환영합니다!
MENU=$(cat << MENU
1. 파일 리스트.
2. 파일 삭제.
3. 에디터 시작.
4. 파일 내용 보기.
5. 컴파일
6. 실행
7. 종료
MENU
)
stop=0

while (( $stop == 0 ))
do
	echo -------------------------------------------------------
	echo "$MENU"
	echo -------------------------------------------------------
	echo -n "메뉴 번호 입력: "
	read reply
	case $reply in
		"1")	echo -n "리스트할 디렉터리 입력: "
			read path
			echo -------------------------------------------------------
			if [ -d "$path" ]
			then 
				echo $path
				echo -------------------------------------------------------
				ls $path
			else
				echo "$path 은(는) 디렉터리가 아닙니다."
			fi;;
		"2")	echo -n "삭제할 파일 이름 입력: "
			read path
			echo -------------------------------------------------------
			if [ -e "$path" ]
			then 
				if [ -d "$path" ]
				then
					echo "$path: 디렉터리입니다. 삭제 불가."
				else
					rm $path
					echo "$path 삭제 완료."
				fi
			else
				echo "존재하지 않는 파일입니다."
			fi;;
		"3")	echo -n "편집할 파일 이름 입력: "
			read path
			gedit $path;;
		"4")	echo -n "파일 이름 입력: "
			read path
			echo -------------------------------------------------------
			if [ -e "$path" ]
			then 
				if [ -d "$path" ]
				then
					echo "$path: 디렉터리입니다."
				else
					more $path
				fi
			else
				echo "해당 파일 없음."
			fi;;
		"5")	echo -n "컴파일할 c 파일 이름 입력: "
			read path
			if [ -e "$path" ]
			then 
				echo -n "컴파일 후 생성할 실행파일 파일 이름 입력: "
				read path2
				gcc -o $path2 $path
			else
				echo "존재하지 않는 파일입니다."
			fi;;
		"6")	echo -n "실행파일 이름 입력: "
			read path
			./$path;;
		"7") stop=1;;
		*) echo 잘못된 선택;;
	esac
done
