# State Pattern in C
This repository is a very simple attempt to implement the state pattern in C. Where each of the states is represented by a set (contained in structures) of interfaces that manipulate the "Context" data and is shared accross states.

## Description
This example implements a countdown timer, where a timeout is configured, and using the "tick" function, the count decreases (actually increases in implementation) until the timeout expires. The "Stopwatch" automatically transitions between stop & start state according to the interfaces called. For example, the Stopwatch is initialized in the Stop state. Once a timeout is configured and the "tick" function is called, it automatically transitions to the Start state. Once the timeout expires, it automatically transitions back to the Stop state and the "IsExpired" flag is set.

To execute this example, just run the "build.sh" file.

## Conclusion
For such a simple state-machine example, a switch-case based approach is better. However, the State Pattern becomes useful in more complex implementations. This is just an example to illustrate the approach and is based off  "Patterns in C" by Adam Petersen.
