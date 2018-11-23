#!/bin/sh

aantal=`wc -w $1 | cut -d " " -f 1`


if [[ $? != 0 ]];

then echo wc heeft gefaald.

else

	if [[ $aantal == 0 ]];
	then	echo File is leeg.
	else	echo Het bestand bevat $aantal woorden.
	fi
fi
