# poker
Texas hold 'em poker game with a TUI.

## Building
To compile the code execute:
```
$ g++ -o poker main.cpp
```

## Running
An example execution of the program is:
```
$ ./poker --blind 10 --money 1000 Bob Alice
```

## Description
A fundamental proof-of-concept implementation of **Texas hold 'em poker** as a terminal application with a Text User Interface (TUI). Ideally executed on a terminal with the default size of 80 x 24.

## Future work
Most functionality is implemented, although it does not evaluate "kicker" cards as part of the best five card hand.

The core logic from this C++ program is to further develop it with the implementation a Graphical User Interface (GUI) and to extend the maximum number of players up to ten.

Furthermore, is to eventually implement networking between GUI applications of this **Texas hold 'em poker game**.
