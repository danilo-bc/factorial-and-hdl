# Factorial and HDL
Repository with various iterations of a factorial calculator to serve as example for people practicing Modeling or HDL concepts applied in Microelectronics

# Quick-start
Clone the repository and open a terminal in `src`

```bash
# Python
python factorial.py
python test_factorial.py
# pytest also works

# Icarus Verilog
make
# This runs the testbench and should display the factorials of 3 and 6

# SystemC
# TODO
```

# Requirements
- Python 3
- Icarus Verilog (tested with v12-branch, built from [source](https://github.com/steveicarus/iverilog))
- SystemC 2.x (tested with v.2.3.4 built from [source](https://www.accellera.org/downloads/standards/systemc))

