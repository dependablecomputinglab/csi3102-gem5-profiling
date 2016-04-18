#Profiling with _gem5_
##Read
- [Before Project: *gem5* Tutorial](https://github.com/dependablecomputinglab/csi3102-tutorial)
##Reference
- [gem5 CPU Models - SimpleCPU](http://www.m5sim.org/SimpleCPU)
- [Running gem5](http://www.gem5.org/Running_gem5)
- [MiBench: A free, commercially representative embedded benchmark suite](http://dl.acm.org/citation.cfm?id=1128563)

##Before Start
####Notation
We denote all shell command start with '$'. We denote essential argument in '<...>', optional argument in '[...]'. <br />
We don't show working directory, so you have to find it yourself. (We believe your maturity!)

####Compile _vs._ Build _vs._ Install
- **Compile**: Source code -> Object file. (ex) hello.c -> hello.o
- **Build**: Given source codes and libraries -> (one or more) Binary file
- **Install**: Place binary file to install path.

####(Optional) We recommend install...
We recommend you to install _vim_. It is improved version of _vi_. If you are using Ubuntu, just execute:
```sh
$ sudo apt-get install vim
```

##Overview
####What is benchmark? What does simulator do?
![benchmark&simulator-concept](http://dclab.yonsei.ac.kr/csi3102/benchmark&simulator-concept.png)

####Profiling with gem5 and mibench
![profiling-with-gem5-and-mibench](http://dclab.yonsei.ac.kr/csi3102/profiling-with-gem5-and-mibench-ver4.png)

####Simulation Process
1. Get benchmark to simulate
2. Do simulation
3. Analyze simulation statistics

##STEP1: Get Benchmark
You can get benchmark by:
- Making your own benchmark yourself
- Download binary
- Download source code & build binary

In our case, we will download _MiBench_, then cross-compile to get benchmark.

####Download ___MiBench___
```sh
$ git clone https://github.com/embecosm/mibench.git
```

####Install Cross-compiler
```sh
$ sudo apt-get install gcc-arm-linux-gnueabi
```

####Cross-compile to build binary
Initially, you can see _Makefile_ in directory '_mibench/automotive/qsort_' looks like:
```make
...
gcc -static qsort_large.c -O3 -o qsort_large -lm 
...
```

Replace __all__ '_gcc_' to '_arm-linux-gnueabi-gcc_', so the _Makefile_ looks like:
```make
...
arm-linux-gnueabi-gcc -static qsort_large.c -O3 -o qsort_large -lm 
...
```

To build, execute
```sh
$ make
```

__NOTE__ When you cross-compile, you must use '__-static__' option. If there is no '__-static__' option in _Makefile_, you have to insert it. <br />
For example, if your _Makefile_ looks like:
```make
...
arm-linux-gnueabi-gcc qsort_large.c -O3 -o qsort_large -lm
...
```

You have to insert '__-static__' option. Then, _Makefile_ will look like:
```make
...
arm-linux-gnueabi-gcc -static qsort_large.c -O3 -o qsort_large -lm 
...
```

##STEP2: Perform Simulation
$ <_gem5 binary_> [_gem5 options_] <_gem5 script_> [_gem5 script options_] <br />

####Useful _gem5_ script options
- '-c <_binary to simulate_>'
- '-o <_input set of benchmark_>'

For example, if you want to simulate *qsort_large*, 
```sh
$ ./build/ARM/gem5.opt -re configs/example/se.py --cpu-type=atomic -c <path to qsort_large> -o <path to input_large.dat>
```

**NOTE** <br />
If you want to put multiple input to binary, you have to use quotation marks(") and white spaces. <br />
For example, if your _fft_ binary is in _~/mibench/telecom/FFT_, 
```sh
$ ./build/ARM/gem5.opt -re configs/example/se.py --cpu-type=timing -c ~/mibench/telecom/FFT/fft -o "100 64"
```

##STEP3: Analyzing Simulation Statistics
####Find difference between two files with _diff_
The _diff_ is a program in linux. <br />
The _diff_ compares two files, **line by line**. <br />
You can use _diff_ by executing: **$ diff [_options_] <_file1_> <_file2_>** <br />

For example, clone this repository and execute:
```sh
$ diff goodbye1.txt goodbye2.txt
```

If you use '__-u__' option like this:
```sh
$ diff -u goodbye1.txt goodbye2.txt
```

Redirection may make you happy! Try this:
```sh
$ diff -u goodbye1.txt goodbye2.txt > goodbye.diff
```

You can see the file _goodbye.diff_.
