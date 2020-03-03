#!/bin/bash

wget -q --spider http://example.com

if [ $? -eq 0 ]; then
	echo "Internet OK"
else
	echo "No Internet"
	exit 1
fi
echo "#######################################"
echo "###             Hi laxz             ###"
echo "#######################################"
sudo apt update
echo "Updated ..."
sudo apt upgrade -y
echo "Upgraded ..."
sudo apt autoremove
echo -e "Removed ...\nALL Update Done ."


#echo -e "GET http://example.com HTTP/1.0\n\n" | nc google.com 80 > /dev/null 2>&1
# if [ $? -eq 0 ]; then
#	echo "OK"
#else
#	echo "NO"
#	exit 1
#fi


# if [ "$(ping -c 1 8.8.8.8 | grep '100% packet loss')" != "" ] ;then
# echo "NO"
# else
# echo "OK"
# fi

