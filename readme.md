# Lab work 1: Comparing of productivity of different methods in c++
Authors (team):
- Roman Kulyk (https://github.com/kkulykk)
- Viktor Povazhuk (https://github.com/viktorpovazhuk)

Variant: 2
## Prerequisites

Tools to be installed:
- gcc
- cmake
- pip

### Compilation

To compile program:
```shell
[user@pc .]$ ./compile --optimize-build
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
Using stringstream: 118289
Using stod: 16781
Using sscanf: 30327

All results are the same.
```

### Important!

<mark>WHAT ELSE SHOULD WE KNOW ABOUT YOUR WORK? (E.G. KNOWN ISSUES, BUGS, SPECIAL BEHAVIOR ETC)</mark>

### Results

We learned in c++:
- time measuring
- working with simple classes
- string to double conversion

# Additional tasks

We provided 3 additional methods of conversion.

