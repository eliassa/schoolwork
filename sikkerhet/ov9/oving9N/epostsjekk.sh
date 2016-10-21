#!/bin/sh

echo "Sjekker domene: " $1
nslookup -type=mx $1 > server.txt
server=`cat server.txt` 

echo "$server"

i=$(echo "$server" | grep 'internet address')
ip=$(echo "$i" | grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b")

echo ""
echo "IP-adresser for revers oppslag"
echo "$ip"

# ip=(${ip[@]})

echo ""
echo "SPF Records: "


s=$(nslookup -type=txt $1 | grep $1)
( ./spf.sh "$s" ) # kjører spf lookup

