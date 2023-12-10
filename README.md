# Pipelined Double Precision (fp64) Floating Point Multiplier
## Project Structure
In this design, the floating point multiplier is designed using pipelining so the throughput of operation can be increased. The highlevel outline of the code looks like:
The design is divided into three stages. They aree:
**Pre-normalize:** The operands are sign (1-bit),exponent (11-bits) and manitssa (52-bits). This makes the operands easy and efficient to handle internally.
**Arithmetic core:** The basic arithmetic operation is done here.
Sign bit: S = S_1^S_2
Exponent part: E = E_1 + E_2 - bias
Mantissa part: M = M_1*M_2
**Post-normalize:** The result (both exponent and mantissa) will be normalized if possible and then transformed into the format specified by the IEEE standard.
## Implementation
### Alogrithm - Booth's Algo
## Design

## Verification

## Usage

## Testing
