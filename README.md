#Profiling with gem5 and mibench
##Before Start
We denote all shell command start with '$'. We denote essential argument in '<...>', optional argument in '[...]'. <br />
We don't show working directory, so you have to find it yourself. (We believe your maturity!)

##Overview
####Profiling with gem5 and mibench
![profiling-with-gem5-and-mibench](http://dclab.yonsei.ac.kr/csi3102/profiling_with_gem5_and_mibench.png)

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
**CAUTION** You must use option '-static', or simulation in gem5 ends with run-time linking error. <br />

$ <_your cross-compiler_> -static [_other options_] <_target_>

```sh
$ arm-linux-gnueabi-gcc -static -O3 -o hellocsi3102_arm hellocsi3102.c 
```
##STEP2: Perform Simulation
$ <_gem5 binary_> [_gem5 options_] <_gem5 script_> [_gem5 script options_]
```sh
$ ./build/ARM/gem5.opt config/example/se.py -c hellocsi3102_arm
```

```sh
$ ./build/ARM/gem5.opt -re config/example/se.py -c goodbye_arm -o "Kyoungwoo Jongho CSI3102"
```


##STEP3: Analyzing Simulation Statistics
####Find difference between two files with 'diff'
$ diff [_options_] <_file1_> <_file2_>

```sh
$ diff goodbye1.txt goodbye2.txt
```

You can use redirection.
```sh
$ diff -u goodbye1.txt goodbye2.txt > goodbye.diff
```
