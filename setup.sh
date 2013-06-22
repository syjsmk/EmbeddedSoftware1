#if nfs IP to linux, many pc can connect to /nfs ex) 192.168.0.172
mount -t nfs 192.168.100.100:/nfs /nfs -o nolock -o rsize=4096
mount /dev/mmc1 /mnt/sd
export LD_LIBRARY_PATH=/mnt/sd/lib:$LD_LIBRARY_PATH
export QWS_MOUSE_PROTO=tslib:$TSLIB_TSDEVICE
export QT_QWS_FONTDIR=/mnt/sd/lib/fonts

#ps all
#kill -9 937

# eth is ethernet for wireless. can search
ifconfig eth1 up
#bandihome is name for wireless machine
iwconfig eth1 essid bandihome
#use DHCP    DHCP client
dhclient eth1