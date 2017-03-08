# mrYellow

A repository containing everything related to mrYellow robot.
## Hardware
A diagram for the robot is shown below:

![Alt text](/documentation/figures/diagram.png?raw=true "mrYellow diagram")



### Connections
1. Right arm motor 1

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

### Installing

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc

