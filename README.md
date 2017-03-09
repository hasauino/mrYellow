# mrYellow

A repository containing everything related to mrYellow robot.
## Hardware
A diagram for the robot is shown below:

![Alt text](/documentation/figures/diagram.png?raw=true "mrYellow diagram")



### Connections
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



```
Give examples
```



