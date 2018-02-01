#!/bin/bash 

make
arm-linux-gcc -o inter_poll_test inter_test.c
cp inter_botton_poll.ko inter_poll_test ../../linuxkernel/myfs1/ 
