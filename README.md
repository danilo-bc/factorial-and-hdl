# Factorial and HDL
Repository with various iterations of a factorial calculator to serve as example for people practicing Modeling or HDL concepts applied in Microelectronics

# Quick-start
Clone the repository and open a terminal in `src`

```bash
# Python
python factorial.py
python test_factorial.py
python factorial_blk.py
# pytest also works

# Icarus Verilog
make
# This runs the testbench and should display the factorials of 3 and 6

# SystemC
make sc
# Compiles a .syscexe and runs it to run a similar testbench, displaying the factorials of 3 and 6
```

# Requirements
- Python >= 3.7
    - For native `dataclass` support
- Icarus Verilog (tested with v12-branch, built from [source](https://github.com/steveicarus/iverilog))
- SystemC 2.x (tested with v.2.3.4 built from [source](https://www.accellera.org/downloads/standards/systemc) using C++14 flag)
    - Should be compatible with previous versions and the default C++ 98 flag
    - Configured using cmake-gui, following the instructions

