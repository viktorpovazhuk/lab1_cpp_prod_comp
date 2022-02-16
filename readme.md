# Lab work 1: Comparing of productivity of different methods in c++

Authors (team):

- [Roman Kulyk](https://github.com/kkulykk)
- [Viktor Povazhuk](https://github.com/viktorpovazhuk)

Variant: 2 (string to double conversion)

## Prerequisites

Tools to be installed:

* on each OS:
  - pip
* on Windows:
  - MinGW
  - gcc (in MinGW)
  - cmake (in MinGW)
  - boost (in MinGW)
  - Qt 5 (in MinGW)
* on Linux:
  - gcc
  - cmake
  - Qt 5
  - boost
* on Apple:
  - gcc
  - cmake
  - Qt 6
  - boost

### Compilation

To compile program:

On Windows run MinGW and cd to repository directory.
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

In Windows either run from MinGW (recommended).
Or run cmd as Admin and add path to mingw64 libraries to your PATH.
```shell
> setx path "%PATH%;%replace\with\path\to\msys64\directory\%mingw64\bin\"
```

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

After running each method 10 times on datafile with 15000000 stingified doubles, we got the following least working times for each of the methods below.

<html>
<table style="border-collapse:collapse;border-spacing:" class="tg"><thead><tr><th style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">№</th><th style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px px;text-align:left;vertical-align:top;word-break:normal">Method</th><th style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">Time, us</th></tr></thead><tbody><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">1</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:400;font-style:normal">stod</span></td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">7797084</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">2</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:400;font-style:normal">sscanf</span></td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">11312367</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">4</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:400;font-style:normal">boost</span></td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">19408251</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">3</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:400;font-style:normal">stringstream</span></td><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">19963339</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">5</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal"><span style="font-weight:400;font-style:normal">Qt</span></td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">38394637</td></tr></tbody></table>
</html>

So, we see that the slowest method is converting string to double via Qt (`QString.toDouble()`) and the fastest is by using standart `std::stod`.

We learned in C++:

- Time measuring
- Working with simple classes
- String to double conversion
- Working with Qt

# Additional tasks

We provided 2 additional methods of conversion (using Boost and Qt libraries).
