Attention: For your testing convenience, if you need to change X or K (that is, the number of times the program is executed at once) when you test, please change it in the header of the source code, where you will see "#define K xxx" and "#define X xxx", only change here to change K or X.

Note:
1.Every.c file is a complete executable file. 
2.I put the timing code in each.c file, so there's no separate program for calling. 
3.After the execution of each.c file, the power operation of the corresponding algorithm can be realized, and the total ticks and time consumed by the execution of K programs will be measured.

About all .C file:
algo-1.c is the code of algorithm 1,
algo-2_res.c is the code of the recursive version of algorithm 2, 
algo-2_ite.c is the code of the iterative version of algorithm 2.

Other:
I embedded the time calculation code into each.c file, which is equivalent to each.c file has its own testing program, which is why there is no separate testing program. I also asked the teacher anonymously whether this is OK, but the teacher did not reply after reading it, QWQ