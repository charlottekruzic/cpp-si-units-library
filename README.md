# Units - Library for unit conversion and management
[![License: MIT](https://img.shields.io/badge/License-MIT-lightgrey.svg)](https://opensource.org/licenses/MIT)

Units is a C++ library designed to handle unit conversions and management. It provides functionalities for converting between various units of measurement, ensuring that the conversions are done with accuracy and efficiency.

## Features
- Conversion between multiple units of measurement
- Support for custom unit definitions and conversions
- Type-safe unit handling through templates
- Built-in test suite to ensure correctness of conversions

## Requirements
- C++17 compatible compiler
- CMake 3.10 or higher
- GoogleTest (included)

## Build Instructions
1. Clone the repository
    ```bash
    git clone https://github.com/charlottekruzic/cpp-units-library.git
    ```
2. Create build directory
    ```bash
    mkdir build && cd build
    ```
3. Configure and build
    ```bash
    cmake ..
    make
    ```

## Run tests
The Units library includes a test suite to validate all operations and conversions. To run the tests:
```bash
./testUnits
```

When all tests pass, you should see output similar to:
```bash
[----------] Global test environment tear-down
[==========] 91 tests from 16 test suites ran. (2 ms total)
[  PASSED  ] 91 tests.
```


## Project assignment
For more information about the purpose of this project, you can find the [complete project assignment file](./project-assignment-fr.pdf) (in french) within this repository. This project is part of the third-year Bachelor's degree in Computer Science at the University of Franche-Comté.
