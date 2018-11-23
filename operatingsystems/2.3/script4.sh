#!/bin/sh

for((i = 100; i > 0; i--));
do
	if [ $i == 1 ]; then
		echo "One bottle of beer on the wall, one bottle of beer. If that bottle would happen to fall, there'd be no bottles of beer on the wall."
	else
		let j="$i - 1"
		echo "$i bottles of beer on the wall, $i bottles of beer. If one of those bottles would happen to fall, there'd be $j bottles of beer on the wall."
	fi
done
