#!/bin/bash

echo -n "계속 하시겠습니까? "
read reply
if [ $reply == "Y" ]
then
	echo "계속합니다"
else
	echo "중지합니다"
fi
