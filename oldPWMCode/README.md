# AleksBot

This repo contains code for a tank-drive style robot to track a ball. The robot is controlled by Victor 888 motor controllers, which are controlled with a 1-2 ms pwm pulse. 1 is all the way backwards, while 2 is all the way forwards. No movement is 1.5 ms pulse.

To enable pwm, run:
    `chmod +x preparePWM.sh`
    `./preparePWM.sh`

You may have to run the second command twice (if you get 'echo ### > some/pwm/pin' errors the first time).

Next compile tracker.cpp:
    `g++ `pkg-config --static --libs opencv` -O3 -o tracker tracker.cpp`
  
And then finally:
    `./tracker | pipe.sh`
  
The pipe.sh program is a bash file that takes input through stdin from tracker.cpp, and then outputs PWM signals from the BBB by editing the PWM values in files!
