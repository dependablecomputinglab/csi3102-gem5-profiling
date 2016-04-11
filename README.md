#Overview
##Profiling with gem5 and mibench
[](http://dclab.yonsei.ac.kr/csi3102/profiling_with_gem5_and_mibench.png)

##Simulation Process
1. Get benchmark to simulate
2. Do simulation
3. Analyze simulation statistics

#Get Benchmark
You can get benchmark by:
- Making your own benchmark yourself
- Download binary
- Download source code & build binary

In our case, we will download _MiBench_, then cross-compile to get benchmark.

##Download _**MiBench **_
```sh
$ git clone https://github.com/embecosm/mibench.git
```

##Install ARM Cross-compiler
```sh
$ sudo apt-get install gcc-arm-linux-gnueabi
```

##Cross-compile to build binary
**CAUTION** You must use option '-static', or simulation in gem5 ends with run-time linking error. <br />

$ <_your cross-compiler_> -static [_other options_] <_target_>

```sh
$ arm-linux-gnueabi-gcc -static -o hellocsi3102 hellocsi3102.c 
```
#Perform Simulation
$ <_gem5 binary_> [_gem5 options_] <_gem5 script_> [_gem5 script options_]


#Analyzing Simulation Statistics
##Find difference between two files with 'diff'
$ diff [_options_] <_file1_> <_file2_>

```sh
$ diff goodbye1.txt goodbye2.txt
```

You can use redirection.
```sh
$ diff -u goodbye1.txt goodbye2.txt > goodbye.diff
```
