#!/bin/bash

#echo "Do you want to make a backup? [Yes:y , No:n]"
#read check
#if [ $check == 'y' ] ; then
#read -sp 'Name: ' user
#echo "OK Yes $user"
#else
#echo "No"
#fi

if [ $# -lt 1 ]
then
	echo ""
        echo "Usage: laxz [command]       ### Developed by Min Latt ###"
        echo ""
	echo "     open - open any file type."
	echo ""
	echo "     internet - to check internet connection."
	echo ""
        echo "     shutdown - shutdown the whole system."
        echo ""
        echo "     backup - to backup laxz-backup folder to Google Drive."
        echo ""
        echo "     update - to update and upgrade and auto clean."
        echo ""
        echo "     password - to initiate online password manager."
        echo ""
        echo "     passwordsql - to open offline password manager."
        echo ""
        exit 1
fi


check_internet()
{
    echo -e "[INFO]: Requestd internet connection by system! \n[INFO]: Checking internet connection ..."
    wget -q --spider http://example.com
    if [ $? -eq 0 ] ; then
            internet='OK'
    else
            echo -e "[INFO Warning]: Cannot make online stuff!\nExiting ..."
            exit 1
    fi
}
system_update()
{

echo "[INFO]: system update initiated..."
sudo apt update
echo -e "[INFO]: package list updated.\n upgrading updates ..."
sudo apt upgrade -y
echo -e "[INFO]: upgraded with no error.\n removing installed raw files and cleaning ..."
sudo apt autoclean || apt autoremove
echo "[INFO]: Done update and upgrade processes."
}

system_backup()
{
echo "OK backup ..."
}

open_file()
{
gvfs-open
#gio open
#gcfs-open
}

if [ $1 == 'shutdown' ] ;  then
        echo "Request system $1 now"
        exit 1
elif [ $1 == 'backup' ]  ; then
        check_internet
	echo "Internet connection is : " $internet
	system_backup

elif [ $1 == 'update' ] ; then
        check_internet
        echo "Internet connection is : " $internet
	system_update

elif [ $1 == 'internet' ]; then
	check_internet
	echo '[INFO]: Internet connection is : ' $internet

elif [ $1 == 'open' ]; then
         open_file

else
        echo "[INFO ERROR]: Invalid command option(s)"

fi
