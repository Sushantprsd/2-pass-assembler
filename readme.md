# 2 Pass Assembler

C++ code for 2 Pass Assembler.

This is a simple C++ code for 2 pass assembler.


An assembler is a translator, that translates an assembler program into a conventional machine language program. Basically, the assembler goes through the program one line at a time, and generates machine code for that instruction. Then the assembler procedes to the next instruction. In this way, the entire machine code program is created. For most instructions this process works fine, for example for instructions that only reference registers, the assembler can compute the machine code easily, since the assembler knows where the registers are.

## Getting Started

Input will be taken from input.txt

Instruction without any label should have a $ at the starting then the opcode separated by space.

If there is a label don't put any $.

Address should be written after operand separated by space.

Opcode should be written in A,M only this manner.

$ MVI B 32H   //no label at starting so put $
LOOP MOV A,M  //Loop is a label 


SymbolTable.txt will store all the symbols with its address created in pass 1(fpass.cpp). 

opcode.txt contain all the opcodes.


### Instructions

First run fpass.cpp

Than run spass.cpp

spass.cpp will create machine code.

### Example
Input

```
example

$ START 2100H
$ LXI H 2000H
$ MVI B 32H
LOOP MOV A,M
$ CMP C
$ JZ STORE
$ INX H
$ DCR B
$ JNZ LOOP
$ LXI H 0000H
STORE SHLD 2200H
$ HLT

```
Output

```
example

Machine Code

2100    21
2103    06
2105    7E
2106    B9
2107    CA
2108    OR
2109    23
2110    05
2111    C2
2112    21
2113    05
2114    21
2117
2118    00
2119    76

```




