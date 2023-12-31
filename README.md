# Pipelined Double Precision (fp64) Floating Point Multiplier
## Project Structure  
This github repository contains the source code for **Pipelined Double Precision Floating Point Multiplier** written in Bluespec system verilog. Given below is the description of files:<br />
* **FPMul64.bsv**: Main design file for the pipelined double-precision floating-point Multiplier.<br />
* **Testbench.bsv:** Test bench file for validating the functionality of the adder.<br />
## Design

In this design, the floating point multiplier is designed using pipelining so the throughput of operation can be increased.<br /> The highlevel outline of the code looks like this.<br />
The design is divided into the following three stages: <br />  
* **Pre-normalize:** The operands are sign (1-bit),exponent (11-bits) and manitssa (52-bits). This makes the operands easy and efficient to handle internally.  
* **Arithmetic core:** The basic arithmetic operation is done here.  
  Sign bit: S = S<sub>1</sub>^S<sub>2</sub>  
  Exponent part: E = E<sub>1</sub> + E<sub>2</sub> - bias  
  Mantissa part: M = M<sub>1</sub>*M<sub>2</sub>  
* **Post-normalize:** The result (both exponent and mantissa) will be normalized if possible and then transformed into the format specified by the IEEE standard.
## Tools

There is a **Makefile** in the same directory as the code. By making necessary changes in the file, you can invoke the following commands  
### COMPILE

Compiles the bsv file and creates a seperate module **build_bsim**
```console
make compile
```
### LINK

Links for bluesim simulator and creates a executable file **mkTestbench_bsim**
```console
make link
```
### SIMULATE

Runs the executable file and the output is displayed
```console
make simulate
```
### VERILOG
To use a verilog simulator, you can follow these commands
```console
make verilog
make v_link
make v_simulate
```
These generated verilog files are then synthesized.
## Openlane Results
### Synthesis
=== mkFPMul64 === <br />

 Number of wires:              19193<br />
 Number of wire bits:          19382<br />
 Number of public wires:         441<br />
 Number of public wire bits:     630<br />
 Number of memories:               0<br />
 Number of memory bits:            0<br />
 Number of processes:              0<br />
 Number of cells:              19249<br />
Chip area for module '\mkFPMul64': 181470.294400(in um^2)<br />

### Floorplan
Initial Floorplan core area : **5.52 10.88 607.66 612.0** <br />
Initial Floorplan die area : **0.0 0.0 613.485 624.205** <br />
