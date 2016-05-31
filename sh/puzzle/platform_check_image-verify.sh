#!/bin/sh

#
# in openwrt do `sysupgrade /tmp/TZ'
#

platform_check_image() {
	local board="afi-a1"
	#local magic_long="4353542d"
	#local magic_long="1114111"
	local magic_long="13631488"

	case "$board" in
		afi-a1)
			echo "magic long1 = $magic_long"
			
			# line below is syntax error			
			# should be
			# [ "$magic_long" -lt "1114112" -o "$magic_long" -gt "13631488" ] && {
			[ "$magic_long" -lt "1114112" ] -o [ "$magic_long" -gt "13631488" ] && {
				echo "Invalid afi-a1 image type."
				return 1
			}
			return 0
			;;
		*)
			echo "bla bla bla"
			;;
	esac
	
	return 1
}

platform_check_image

# 
# fix version
# hexdump -v -n 4 bin/ar71xx/sysupgrade.bin 
# can get the kernel magic number, it should be digital.
# 
platform_check_image_fix() {
	local board="afi-a1"
	#local magic_long="4353542d"
	local magic_long="27051956"

	case "$board" in
		afi-a1)
			echo "magic long2 = $magic_long"

			[ "$magic_long" != "27051956" ] && {
				echo "Invalid image type."
				return 1
			}
			
			return 0
			;;
		*)
			echo "bla bla bla"
			;;
	esac
	
	return 1
}

platform_check_image_fix
