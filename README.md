# mrYellow

A repository containing everything related to mrYellow robot.
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
1. Right arm motor 1

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

2. Right arm motor 2

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

3. Left arm motor 1

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

4. Left arm motor 2

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

4. Head Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  31 (Arduino) |



4. Face Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  33 (Arduino) |

4. Right Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  35 (Arduino) |


4. Left Servo

| wire          | functionality | pin # |
| ------------- |---------------| ------|
| Brown         |  GND      |  GND (Arduino, GND is common with the tetrix servo controller) |
| Red         |  5V      |  5V (tetrix servo controller (i.e. servo takes power from tetrix servo controller)  |
| Orane           |  servo signal  |  37 (Arduino) |




##Software
###Android App
Android app used:  https://play.google.com/store/apps/details?id=com.heightdev.arduinobtjoysticklite&hl=en
Inside the app, go to settings, and set the delay to a value higher than 100 ms


###Auto start python script at boot
The last line in the "crontab" has the commnad to start the python script at boot.
for more information on crontab, check the following link:  [More details about crontab](http://www.computerhope.com/unix/ucrontab.htm)

To change the crontab, type the following in the terminal (you can open a terminal by pressing CTRL+ALT+t):
```
sudo crontab -e
```
Scroll down to the last line, you should see the following line:
```

```
Comment/uncomment the last line to disable/enable running the python script at boot. For example, if the last line is not commented, as follows:

