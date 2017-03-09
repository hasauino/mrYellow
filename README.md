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

1. Right arm motor 2

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



```
Give examples
```



