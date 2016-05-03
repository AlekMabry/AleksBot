sleep 6
while true
do
        read var1 var2
        cd /sys/devices/ocp.3/pwm_test_P8_34.*/
        echo $var1 > duty
        cd /sys/devices/ocp.3/pwm_test_P9_22.*/
        echo $var2 > duty
done
