# Pipelined Double Precision (fp64) Floating Point Multiplier
## Project Structure
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

These verilog files are then synthesized.
## Verification

## Usage

## Testing
