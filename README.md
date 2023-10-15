# Tic Tac Toe - Programming Assignment

A simple command-line implementation of the classic Tic Tac Toe game. This project not only showcases the game logic but also integrates testing, debugging, and code coverage functionalities.

<p align="center">
  <img src="https://i.ibb.co/PrKB0bZ/Screenshot-2023-10-15-at-8-54-26-PM.png" alt="Screenshot 1"  style="margin: 0 10px;">
</p>

## Table of Contents
- [How to Play](#how-to-play)
- [Testing](#testing)
- [Debugging](#debugging)
- [License](#license)

## How to Play

### Compile
```bash
gcc main.c -o main
```

### Run
```bash
./main
```

Follow the on-screen instructions to input your moves. Enter positions as numbers from 1 to 9, following the grid format displayed.

## Testing

Ensure you have the CUnit library installed for unit testing.

### Compile
```bash
gcc -fprofile-arcs -ftest-coverage tests.c -lcunit -o tic_tac_toe_tests
```

### Execute
```bash
./tic_tac_toe_tests
```

### See Code Coverage
```bash
gcov tests.c 
```

This will provide you with details on lines executed and overall test coverage.

## Debugging

### Compile with Debug Information
```bash
gcc -g -o main main.c
```

### Start Debugger
```bash
lldb main
```

### Set Breakpoints
For the winning scenario:
```bash
breakpoint set --file main.c --line 38
```

For the draw scenario:
```bash
breakpoint set --file main.c --line 44
```

### Run Program Inside Debugger
```bash
Run
```

### Print the Board/Grid Status
```bash
print board
```

### Continue Code Execution
```bash
c
```

### Quit Debugger
```bash
q
```

## License

This project is open source. Feel free to fork, modify, and use in your projects.

---

