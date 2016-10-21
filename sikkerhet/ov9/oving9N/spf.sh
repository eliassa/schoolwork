#!/bin/sh

# 
found=$(echo "$1" | grep -oE "[include]{7}\:([a-z]*\.){3}[a-z]* ") #!få ut include...
inc=$(echo "$1" | grep -oE "([include:])[^ ]*")
if [ ! -z "$inc" ]; then
	for word in $inc
	do
		#\b(?:(?!include:)\w|-|_|\.)+\b
		if [[ $word == *"include"* ]]; then
			
			search=$(echo ${word##*:}) # Henter ut det som kommer etter : 
			echo "$search" 
			s=$(nslookup -type=txt $search | grep $search)
			
			./$0 "$s"
		fi
	done	

fi

# 
# 	
#	if [ "include" = $(echo "$1" | grep -oE "[include]{7}") ]; then
#		newspf=$(echo "$found" | grep -oE "([a-z]*\.){3}[a-z]*" )
#		echo "$newspf"
#		s=$(nslookup -type=txt $newspf | grep $newspf)
#		./$0 "$s" # Noe blir feil her....
#	fi
# 
# 
# 
# 