<div align="center">
  <img src="download.png">
  <br>
</div>

Architecture Coursework
==========================

The code can be found  <a href="https://github.com/gioannides/EIE2-MIPS_SIMULATOR">here</a>.
-------------------------------------------------------------------------------------------

There are three central aims of this coursework:

- Solidify understanding of how an instruction
  processor actually functions. The overall functionality
  of how a processor works is relatively easy to grasp,
  but there is lots of interesting detail which gives
  some insight (both into CPUs, but also into
  software and digital design).
  
- Understand the importance of having good specifications,
  in terms of functionality, APIs, and requirements. This
  is fundamental to CPU design and implementation, but is
  also true in the wider world (again) of software and
  digital design.
 
- Develop skills in coding from scratch by creating a
  CPU simulator from scratch.

Specification
=============

The task was to develop a MIPS CPU simulator, which can accurately execute
MIPS-1 big-endian binaries. Also a testbench was developed which is able to 
test a MIPS simulator, and try to work out whether it is correct.

Terminology
-----------

For the sake of clarity, this document will use the following terms:

- *Simulator* : The MIPS CPU simulator being developed. This program
  is running natively under a Linux/Windows/OSX Environment and has direct access
  to your files, the keyboard (stdin), the screen (stdout), etc. The simulator
  will be responsible for implementing a register file, program counter, and
  memory, and then sequentially executing MIPS instructions according to the
  MIPS ISA.

- *Binary* : The MIPS binary/program/executable which is currently being
  executed/run/simulated by your _Simulator_. Each time the simulator is
  ran it will need to be given a binary, as by itself the simulator does
  nothing (just like a "real" CPU does nothing if you switch it on but don't
  give it instructions to execute). While a simulator can only execute one
  binary each time it is run, the set of binaries that it can run is
  unrestricted. Test binaries needed to be developed, as well as
  executing binaries from 3rd-party sources.

- *Environment* : This is the thing which is hosting and executing the
  Simulator. Part of it is the operating system, but it also contains
  elements of the C run-time library (e.g. libc), and also some elements of
  the compiler itself.
  
- *Testbench* : This is the testing framework, which can take a given
  Simulator, and through running tests attempt to ascertain what features of the
  Simulator work. The aim was that the Testbench should be able to check the
  functionality of a Simulator at an Instruction granularity.

The MIPS ISA acts as the boundary between the Simulator and the Binary,
so any correct Binary should run on any correct Simulator, and should
deterministically do exactly the same thing.

The target Evironment will be Ubuntu 16, with the standard GNU toolchain
installed (i.e. `g++`, `make`), standard command line utilities, and
bash.

Simulator Input/Output
----------------------

The Simulator is a single executable, and has the following behaviour:

- *Binary* : the Binary location is passed as a command-line parameter, and
  should be the path of a binary file containing MIPS-1 big-endian instructions.
  These instructions should be loaded into a fixed region of "RAM" with a known
  address, then execution should start at the first address in this region.

- *Input* : input to the simulated Binary will be passed in over the Simulator's
  standard input (`std::cin` or `stdin`), and mapped into a 32-bit memory location.
  If the Binary reads from the nominated memory location, it should be logically equivalent
  to calling `std::getchar` or `getchar` (and one approach would be for the Simulator
  to call these functions on behalf of the Binary).

- *Output* : output from the simulated Binary will be produced by
  writing to a mapped 32-bit memory location. Writing to the nominated memory
  location should be equivalent to calling `std::putchar` or `putchar` (and
  again, the Simulator could call these functions on behalf of the Binary).

- *Exit* : A Binary signals successful termination/completion by executing the
  instruction at address 0. This tells the Simulator that there are no more
  instructions to execute, and that it should exit. The return code of the
  Simulator is given by the low 8-bits of the value in register `$2`. These
  8-bits should be used as a non-negative value to pass to `std::exit` or `exit`.
  
- *Exceptions* : The Binary may execute instructions which are illegal, and
  so result in exceptions which should terminate execution of the Binary. To
  indicate this, the Simulator should return one of the negative exit codes
  detailed later on.
  
- *Errors* : Errors may occur within the Simulator (as opposed to exceptions
  which are due to part of the Binary's logic). Examples might include instructions
  which aren't implemented (limited functionality in the Simulator), or IO failures
  (problems which occur due to run-time interactions between the Simulator and the Environment).

- *Logging* : A Simulator may choose to emit diagnostic/debugging messages at various
  points, in order to record what is going on. This is completely fine,
  but any diagnostic information _must_ be written to `std::cerr` / `stderr`.
  Any output written to `std::cout` / `stdout` will be interpreted as
  output from the Binary.
  

Simulator build and execution
-----------------------------

The compiler is buildable by using the command:
```
make simulator
```
in the root of the respository. This results
in a binary called `bin/mips_simulator`. An artificial requirement of
this coursework for assessment purposes (i.e. it isn't really
required for API reasons) is that the simulator is:
- A binary compiled from C++ sources.
- It can be compiled in the target Environment.
This means that if the following sequence is executed:
```
rm bin/mips_simulator
make simulator
```
Then a new binary will be compiled from C++ sources.

If we assume the existence of a Binary called `x.bin`, we would
simulate it using:
```
bin/mips_simulator x.bin
```
On startup all MIPS registers will be zero, any uninitialised
memory will be zero, and the program counter will point at the
first instruction in memory.

The Simulator does not assume it is being executed from any particular
directory, so it does not try to open any data files. It also does
not create or write to any other files.

Testbench Input/Output
----------------------

A Testbench takes a single command-line parameter,
which is the path of the Simulator to be tested.

As output, the Testbench should print a CSV file, where each row of
the file corresponds to exactly one execution of the Simulator under test.
Each row has the following fields:
```
TestId , Instruction , Status , Author [, Message]
```

The meaning of the fields is as follows:

- `TestId` : A unique identifier for the particular test. This can be composed
  of the characters `0-9`, `a-z`, `A-Z`, `-`, or `_`. So for example, ascending
  integers would be fine, or combinations of words and integers, as long as there
  are no spaces. Running the test-bench twice should produce the same set of
  test identifiers in the same order, and this reflects the order in which
  tests are executed.

- `Instruction` : This identifies the instruction which is the _primary_
  instruction being tested. Note that many (actually, most) instructions are
  impossible to test in isolation, so a given test may fail either because
  the instruction under test doesn't work, or because some other instruction
  necessary for the tests is broken. The test should be written to be particularly
  sensitive to the instruction under test, so it looks for a failure mode of
  that particular instruction.

- `Status` : This will either be `Pass` or `Fail`. Note that a given test can
  only test so much, so it is entirely possible that a test might pass even
  if an instruction is broken. However, a `Fail` should be only be returned
  if the instruction under test (or another instruction) has clearly done
  something wrong.
  
- `Author` : The login of the person who created the test.

- `Message` : This is an optional field which gives more details about what
  exactly went wrong. This field is free-form text, but it must not contain
  any commas, and should only be a single line.
  
All fields are case insensitive, including `TestId`.
  
Testbench build and executable
------------------------------

The Testbench is built (or otherwise setup) using:
```
make testbench
```

This results in an executable called:
```
bin/mips_testbench
```
_Note: this is only an executable file; so unlike the Simulator
it does not need to be binary built from C++, and could be a bash script._


An example of running the Testbench on it's own Simulator would be:
```
bin/mips_testbench  bin/mips_simulator
```
corresponding output might be:
```
0, ADDU, Pass, dt10
1, ADD, Pass, dt10
2, ADDI, Pass, dt10
```

If we assume a different Testbench, and have a Simulator at the
path `../other-simulator/bin/mips_simulator`, then we could execute with:
```
bin/mips_testbench   ../other-simulator/bin/mips_simulator
```
and the corresponding output might be:
```
jr1 ,   jr,   Pass, gi316,   Single JR statement back to NULL
addi1 , addi, Pass, hes2,   Add 5 to $0
addi2 , addi, Fail, hes2,   Add -5 to $0
jr2 ,   jr,   Pass, hes2,   JR->NOP->JR->NOP
```

Memory-Map
----------

The memory map of the simulated process is as follows:

```
Offset     |  Length     | Name       | R | W | X | Cached |
-----------|-------------|------------|---|---|---|--------|--------------------------------------------------------------------
0x00000000 |        0x4  | ADDR_NULL  |   |   | Y |        | Jumping to this address means the Binary has finished execution.
0x00000004 |  0xFFFFFFC  | ....       |   |   |   |        |
0x10000000 |  0x1000000  | ADDR_INSTR | Y |   | Y |      Y | Executable memory. The Binary should be loaded here.
0x11000000 |  0xF000000  | ....       |   |   |   |        |
0x20000000 |  0x4000000  | ADDR_DATA  | Y | Y |   |      Y | Read-write data area. Should be zero-initialised.
0x24000000 |  0xC000000  | ....       |   |   |   |        |
0x30000000 |        0x4  | ADDR_GETC  | Y |   |   |        | Location of memory mapped input. Read-only.
0x30000004 |        0x4  | ADDR_PUTC  |   | Y |   |        | Location of memory mapped output. Write-only.
0x30000008 | 0xCFFFFFF8  | ....       |   |   |   |        |
-----------|-------------|------------|---|---|---|--------|--------------------------------------------------------------------
```

The Binary is not allowed to modify it's own code, nor should it attempt to execute code outside the executable memory.

When a simulated program reads from address `ADDR_GETC`, the simulator will
- Block until a character is available (e.g. if a key needs to be pressed)
- Return the 8-bit extended to 32-bits as the result of the memory read.
- If there are no more characters (EOF), the memory read should return -1.

When a simulated program writes to address `ADDR_PUTC`, the simulator will
write the character to stdout. If the write fails, the appropriate Error
will be signalled.

Exceptions and Errors
---------------------

*Exceptions* are due to instructions which the Binary wants to execute which result
in some kind of exceptional or abnormal situation. Exceptions do not occurr
due to bugs or errors within the Simulator. All exceptions are classified into
three types, each of which has a numeric code:

- Arithmetic exception (-10) : Any kind of arithmetic problem, such as overflow, divide by zero, ...

- Memory exception     (-11) : Any problem relating to memory, such as address out of range, writing to
  read-only memory, reading from an address that cannot be read, executing an address that cannot be executed ...

- Invalid instruction  (-12) : The Binary tries to execute a memory location that does not contain a valid
  instruction (this is not the same as trying to read a value that cannot be executed).

If any of these exceptions are encountered, the Simulator will immediately terminate
with the exit code given using `std::exit`. Please note than an exception does
not automatically mean that a Binary must be incorrect or buggy. For example,
there are very well-defined situations where arithmetic overflow occurs, and a
Binary may choose to rely on this behaviour for performance reasons, rather than
explicitly checking for overflow all the time. Indeed, this performance argument
is a big reason for hardware overflow exceptions, so a Binary _must_ be able to
rely on them being correctly reported.

*Errors* are due to problems occuring within the simulator, rather than something
that the Binary did wrong. As with exceptions, an error may indicate a genuine problem
with the Simulator, or it may be due to an interaction between the Simulator and
the Environment. An example of the former is where a Simulator doesn't support
a particular op-code (yet), so cannot execute a correct Binary.

An example of an error which is _not_ the Simulator's fault is where the Binary has tried
to output a character, but the request to the Environment has failed in some way. You
may never have worried about it, but `std::cin >> x` can fail in various ways, and this
would not be the fault of the Binary (so is not an exception).

Error codes are:

- Internal error (-20) : the simulator has failed due to some unknown error
- IO error (-21) : the simulator encountered an error reading/writing input/output

Instructions
------------

Instructions of interest are:

Code    |   Meaning                                   | Complexity  
--------|---------------------------------------------|-----------
ADD     |  Add (with overflow)                        | 2  XX       
ADDI    |  Add immediate (with overflow)              | 2  XX       
ADDIU   |  Add immediate unsigned (no overflow)       | 2  XX       
ADDU    |  Add unsigned (no overflow)                 | 1  X        
AND     |  Bitwise and                                | 1  X         
ANDI    |  Bitwise and immediate                      | 2  XX       
BEQ     |  Branch on equal                            | 3  XXX      
BGEZ    |  Branch on greater than or equal to zero    | 3  XXX      
BGEZAL  |  Branch on non-negative (>=0) and link      | 4  XXXX     
BGTZ    |  Branch on greater than zero                | 3  XXX      
BLEZ    |  Branch on less than or equal to zero       | 3  XXX      
BLTZ    |  Branch on less than zero                   | 3  XXX      
BLTZAL  |  Branch on less than zero and link          | 4  XXXX     
BNE     |  Branch on not equal                        | 3  XXX      
DIV     |  Divide                                     | 4  XXXX     
DIVU    |  Divide unsigned                            | 4  XXXX     
J       |  Jump                                       | 3  XXX      
JALR    |  Jump and link register                     | 4  XXXX     
JAL     |  Jump and link                              | 4  XXXX     
JR      |  Jump register                              | 1  X      
LB      |  Load byte                                  | 3  XXX       
LBU     |  Load byte unsigned                         | 3  XXX      
LH      |  Load half-word                             | 3  XXX       
LHU     |  Load half-word unsigned                    | 3  XXX       
LUI     |  Load upper immediate                       | 2  XX       
LW      |  Load word                                  | 2  XX       
LWL     |  Load word left                             | 5  XXXXX    
LWR     |  Load word right                            | 5  XXXXX    
MFHI    |  Move from HI                               | 3  XXX     
MFLO    |  Move from LO                               | 3  XXX     
MTHI    |  Move to HI                                 | 3  XXX     
MTLO    |  Move to LO                                 | 3  XXX     
MULT    |  Multiply                                   | 4  XXXX     
MULTU   |  Multiply unsigned                          | 4  XXXX     
OR      |  Bitwise or                                 | 1  X        
ORI     |  Bitwise or immediate                       | 2  XX       
SB      |  Store byte                                 | 3  XXX      
SH      |  Store half-word                            | 3  XXX      
SLL     |  Shift left logical                         | 2  XX       
SLLV    |  Shift left logical variable                | 3  XXX       
SLT     |  Set on less than (signed)                  | 2  XX       
SLTI    |  Set on less than immediate (signed)        | 3  XXX       
SLTIU   |  Set on less than immediate unsigned        | 3  XXX      
SLTU    |  Set on less than unsigned                  | 1  X        
SRA     |  Shift right arithmetic                     | 2  XX       
SRAV    |  Shift right arithmetic                     | 2  XX       
SRL     |  Shift right logical                        | 2  XX       
SRLV    |  Shift right logical variable               | 3  XXX       
SUB     |  Subtract                                   | 2  XX       
SUBU    |  Subtract unsigned                          | 1  X        
SW      |  Store word                                 | 2  XX       
XOR     |  Bitwise exclusive or                       | 1  X        
XORI    |  Bitwise exclusive or immediate             | 2  XX       
--------|---------------------------------------------|---------
INTERNAL|  Not associated with a specific instruction |
FUNCTION|  Testing the ability to support functions   |
STACK   |  Testing for functions using the stack      |

The final instructions are pseudo-instructions, for cases where they don't map to
a single instruction.


Simulator Grade Outcome - 98.7%

Testbench Grade Outcome - 100%


References: Dr. David Thomas - EIE Course Director
