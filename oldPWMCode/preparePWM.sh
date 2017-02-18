echo "Turning on Clocks"
g++ enable_clock.cpp -o enable_clock
./enable_clock -e 1 2

echo "Adding PWM to /sys/devices/bone_capemgr*/slots"
echo bone_pwm_P9_22 > /sys/devices/bone_capemgr*/slots
echo bone_pwm_P8_34 > /sys/devices/bone_capemgr*/slots
echo am33xx_pwm >  /sys/devices/bone_capemgr.*/slots

echo "Turning on PWM"
sleep 2

cd /sys/devices/ocp.3/pwm_test_P9_22.*
echo 0 > polarity
echo 20000000 > period 
echo 1500000 > duty
echo 1 > run 

cd /sys/devices/ocp.3/pwm_test_P8_34.*
echo 0 > polarity
echo 20000000 > period 
echo 1500000 > duty 
echo 1 > run 
