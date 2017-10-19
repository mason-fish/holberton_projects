#!/bin/bash
CONTENT=$1
VOICE=$2
IP_LOC=$3
FILENAME=$( echo $CONTENT | awk '{print $1}' )

# Can also use -F with awk: awk -F "|" '{ print > $NF }' file

# now select voice with switch

case $VOICE in
    "f" )
	VOICE="Sara";;
    "m" )
	VOICE="Bruce";;
    "x" )
	VOICE="Zarvox";;
esac

say -v $VOICE $CONTENT -o $FILENAME.m4a
scp $FILENAME.m4a admin@$IP_LOC:/var/www/html/$FILENAME.m4a
echo "Listen to the message on http://"$IP_LOC/$FILENAME.m4a
