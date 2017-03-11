# mrYellow

A repository containing everything related to mrYellow robot.

##General Instructions
![Alt text](/documentation/figures/back.png?raw=true "mrYellow back")

1. Do NOT charge while the Raspberry pi (RPi) switch or the motors/speaker switch are ON. Before charging, shutdown down the RPi and switch it OFF, also switch OFF the motors/speaker power. After that you can plug the power cable into one of the charging slots. You should see a red light near the right arm shoulder.

1. Charging requires at least 7 hours.

1. After you shutdown RPi, after the screen goes black, wait 20 sec, and then switch OFF the power (to make sure RPi is completely shutdown).

1. After switching ON RPi, it will boot and start the following processes:

  1. Image sequance: the RPi changes a picture each 10 sec. images are located in "~/mrYellow/pic".
  
  2. Python script ("main.py"): main.py is a python script which is run at boot, it is located in "~/mrYellow/scripts".
  
1. Control the robot using the android app (listed below). When you open the app, press on "connect", choose "mrYellow". The bluetooth password is:
```
1234
```
##Updating the files



##Software

###Overview
mrYellow consists of a raspberry pi 3, and an Arduino Mega. The raspberry pi is responsible for running the face detection, and receiving bluetooth commands on its UART port. The two processes are running in parallel as a python script named "main.py".

The "main.py" script, receives bluetooth commands and passes them to the arduino as a serial message.
The arduino, recieves this message, and controlles the hardware accordingly.

On Arduino, the "mrYellow.h" header file contains constants defentions and functions that control everything in the robot.



###Android App

Android app used:  https://play.google.com/store/apps/details?id=com.heightdev.arduinobtjoysticklite&hl=en


Very important: **Inside the app, go to settings, and set the delay to a value higher than 100 ms**, (100 ms is perfect!)


![Alt text](/documentation/figures/buttons.png?raw=true "app for controlling mrYellow")


| buttons pressed        | action |
| ------------- |---------------|
|     fwd_button     |    move forward    | 
|     bwd_button     |    move backward    |
|     right_button     |    rotate to the right    |
|     left_button     |    rotate to the left    |
|     headCW     |    rotate head clockwise    |
|     headCCW     |    rotate head counter clockwise    |
|     leftArm_button + headCW     |    move leftArm motor 1 (shoulder joint) up     |
|     leftArm_button + headCCW     |    move leftArm motor 1 (shoulder joint) down    |
|     rightArm_button + headCW     |    move rightArm motor 1 (shoulder joint) up    |
|     rightArm_button + headCCW     |    move rightArm motor 1 (shoulder joint) down    |
|     leftArm_button + left_button     |    move leftArm motor 2 (elbow joint) up     |
|     leftArm_button + right_button     |    move leftArm motor 2 (elbow joint) down    |
|     rightArm_button + left_button     |    move rightArm motor 2 (elbow joint) up    |
|     rightArm_button + right_button     |    move rightArm motor 2 (elbow joint) down    |
|     select_button + any other button (except start_button)    |    play a sound file    |
|     start_button + headCW    |    left arm gripper (servo) open    |
|     start_button + headCCW    |    left arm gripper (servo) close    |
|     start_button + fwd_button    |    right arm gripper (servo) open    |
|     start_button + bwd_button    |    right arm gripper (servo) close    |
|     start_button + left_button    |    rotate face servo counter clock wise    |
|     start_button + left_button    |    rotate face servo clock wise    |




###Auto start python script at boot
The last line in the "crontab" has the commnad to start the python script at boot.
for more information on crontab, check the following link:  [More details about crontab](http://www.computerhope.com/unix/ucrontab.htm)

To change the crontab, type the following in the terminal (you can open a terminal by pressing CTRL+ALT+t):
```
sudo crontab -e
```
Scroll down to the last line, you should see the following line:
```
@reboot /home/pi/.virtualenvs/cv/bin/python /home/pi/mrYellow/scripts/main.py > /home/pi/logs.log 2>&1
```
Comment/uncomment (by adding '#')the last line to disable/enable running the python script at boot.





## Hardware
A diagram for the robot is shown below:

![Alt text](/documentation/figures/diagram.png?raw=true "mrYellow diagram")

### RPi Connections

| Bluetooth module          | RPi |
| ------------- |---------------|
| red(5V)         |  5V      |  
|black(GND)|GND|
|white(RX)			 |UART0 TX|
|Green(TX)|UART0 RX|

### Arduino Connections

* Right arm motor 1

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| black         |  power +      |  B01 (1st motor driver TB6612FNG) |
| white         |  power -      |  B02 (1st motor driver TB6612FNG)  |
| red           |  Encoder GND  |  GND (Arduino) |
| Green         |  Encoder 4.5V |  5v  (Arduino)|
| Yellow        |  Encoder 1    |  18  (Arduino, interrupt) |
| Blue          |  Encoder 2    |  30  (Arduino) |
| BIN1 (1st motor driver TB6612FNG)              |  motor black wire input   |  32  (Arduino) |
| BIN2 (1st motor driver TB6612FNG)              |  motor white wire input   |  34  (Arduino) |
| PWMB (1st motor driver TB6612FNG)              |  motor PWM   |  12  (Arduino) |

* Right arm motor 2

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| black         |  power +      |  A01 (1st motor driver TB6612FNG) |
| white         |  power -      |  A02 (1st motor driver TB6612FNG)  |
| red           |  Encoder GND  |  GND (Arduino) |
| Green         |  Encoder 4.5V |  5v  (Arduino)|
| Yellow        |  Encoder 1    |  19  (Arduino, interrupt) |
| Blue          |  Encoder 2    |  22  (Arduino) |
| AIN1 (1st motor driver TB6612FNG)              |  motor black wire input   |  26  (Arduino) |
| AIN2 (1st motor driver TB6612FNG)              |  motor white wire input   |  28  (Arduino) |
| PWMA (1st motor driver TB6612FNG)              |  motor PWM   |  13  (Arduino) |

* Left arm motor 1

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| black         |  power +      |  B01 (2nd motor driver TB6612FNG) |
| white         |  power -      |  B02 (2nd motor driver TB6612FNG)  |
| red           |  Encoder GND  |  GND (Arduino) |
| Green         |  Encoder 4.5V |  5v  (Arduino)|
| Yellow        |  Encoder 1    |  3  (Arduino, interrupt) |
| Blue          |  Encoder 2    |  36  (Arduino) |
| BIN1 (2nd motor driver TB6612FNG)              |  motor black wire input   |  38  (Arduino) |
| BIN2 (2nd motor driver TB6612FNG)              |  motor white wire input   |  40  (Arduino) |
| PWMB (2nd motor driver TB6612FNG)              |  motor PWM   |  11  (Arduino) |

* Left arm motor 2

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| black         |  power +      |  A01 (2nd motor driver TB6612FNG) |
| white         |  power -      |  A02 (2nd motor driver TB6612FNG)  |
| red           |  Encoder GND  |  GND (Arduino) |
| Green         |  Encoder 4.5V |  5v  (Arduino)|
| Yellow        |  Encoder 1    |  2  (Arduino, interrupt) |
| Blue          |  Encoder 2    |  42  (Arduino) |
| AIN1 (2nd motor driver TB6612FNG)              |  motor black wire input   |  44  (Arduino) |
| AIN2 (2nd motor driver TB6612FNG)              |  motor white wire input   |  46  (Arduino) |
| PWMA (2nd motor driver TB6612FNG)              |  motor PWM   |  10  (Arduino) |

* Head Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  31 (Arduino) |



* Face Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  33 (Arduino) |

* Right Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  35 (Arduino) |


* Left Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  37 (Arduino) |
