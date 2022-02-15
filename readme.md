# Lab work 1: Comparing of productivity of different methods in c++

Authors (team):

- [Roman Kulyk](https://github.com/kkulykk)
- [Viktor Povazhuk](https://github.com/viktorpovazhuk)

Variant: 2 (string to double conversion)

## Prerequisites

Tools to be installed:

- gcc
- cmake
- pip
- Qt 5 or 6

### Compilation

To compile program:

```shell
[user@pc .] $ ./compile --optimize-build
```

### Installation

Compiled executable: automatically installed in ./bin during compilation.

Python environment for time measuring script:

```shell
[user@pc .]$ pip install virtualenv
[user@pc .]$ virtualenv venv
[user@pc .]$ source venv/bin/activate
[user@pc .]$ pip install -r ./dependencies/requirements.txt
```

To deactivate Python environment after using the script:

```shell
[user@pc .]$ deactivate
```

### Usage

1. Download data file from url in file data/url_to_data.txt.
2. Run the program or run the script.

Program console parameters:

```text
-h [ --help ]         Show help message
--method_number arg   Number of method to run
--input_file arg      File with input data
--output_file arg     File for result
```

You can specify each parameter with its flag in console or just enter them in appropriate order.

Example of program run:

```shell
[user@pc .]$ cd bin
[user@pc bin]$ ./converter 3 ../data/train.txt ../data/out.txt

31459
```

Example of script run:

```shell
[user@pc .]$ cd bin
[user@pc bin]$ python ../scripts/measure_methods.py 10 ../data/train.txt ../data/out.txt

String to double convertion, us:

Using stod: 57612
Using sscanf: 117025
Using stringstream: 156290
Using boost: 204908
Using Qt: 366567

All results are the same.
```

### Important!

Tested on macOS and Ubuntu. Works with Qt5 on Ubuntu and Qt6 on macOS (appropriate libraries are loading according to CMakeLists.txt condition).

### Results

We learned in C++:

- Time measuring
- Working with simple classes
- String to double conversion
- Working with Qt

# Additional tasks

We provided 2 additional methods of conversion (using Boost and Qt libraries).
