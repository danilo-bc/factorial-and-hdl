from dataclasses import dataclass

STATE_DICT = {"INIT":0, "CALC":1, "DONE":2}

@dataclass
class factorial_blk:
# Remember that these are type hints, developer has to enforce them
    curr_state: int = STATE_DICT["INIT"]
    next_state: int = STATE_DICT["INIT"]
    calc_buffer: int = 1
    counter: int = 0
    in_data: int = 0
    in_valid: bool = False
    out_data: int = 0
    out_valid: bool = False
    out_busy: bool = False

def reset(blk):
    return factorial_blk()

# Copy of SystemC's factorial_cpp::factorial_proc, excluding reset
# The general rule of thumb is that terms on the right come from blk, unless they're inputs
# Terms on the left are newly assigned depending on current blk variables (general state)
def factorial_clk(blk, in_data, in_valid):
    # Section not needed if regular Python class + methods were used
    # Left here as an experiment, but probably better done with the regular methodology
    # Since SystemC is already class-based OOP
    curr_state = blk.curr_state
    next_state = blk.next_state
    calc_buffer = blk.calc_buffer
    counter = blk.counter
    out_data = blk.out_data
    out_valid = blk.out_valid
    out_busy = blk.out_busy
    
    if blk.curr_state == STATE_DICT["INIT"]:
        if(in_valid):
            next_state = STATE_DICT["CALC"]
        else:
            next_state = STATE_DICT["INIT"]
    elif blk.curr_state == STATE_DICT["CALC"]:
        if(counter == 1):
            next_state = STATE_DICT["DONE"]
        else:
            next_state = STATE_DICT["CALC"]
    elif blk.curr_state == STATE_DICT["DONE"]:
        next_state = STATE_DICT["INIT"]

    if blk.curr_state == STATE_DICT["INIT"]:
        out_valid = False
        if(in_valid):
            counter = in_data
            out_busy = True
    elif blk.curr_state == STATE_DICT["CALC"]:
        calc_buffer = blk.calc_buffer * blk.counter
        counter = blk.counter - 1
    elif blk.curr_state == STATE_DICT["DONE"]:
        out_data = blk.calc_buffer
        calc_buffer = 1
        out_valid = True
        out_busy = False

    curr_state = next_state
    return factorial_blk(curr_state, next_state, calc_buffer, counter, in_data, in_valid, out_data, out_valid, out_busy)

    
if __name__ == '__main__':
    dut = factorial_blk()
    # Copy of sourcesink::sourcesink_proc behavior
    # 'Wait' becomes a factorial_clk call
    in_data = 0
    in_valid = 0
    dut = reset(dut)

    in_data = 3
    in_valid = 1
    dut = factorial_clk(dut, in_data, in_valid)

    in_data = 5
    timeout_counter = 0
    while(dut.out_valid != True and timeout_counter < 64):
        timeout_counter += 1
        dut = factorial_clk(dut, in_data, in_valid)
    print(f"Factorial of 3 {dut.out_data}, out_valid: {dut.out_valid}, out_busy: {dut.out_busy}")
    dut = factorial_clk(dut, in_data, in_valid)

    timeout_counter = 0
    while(dut.out_valid != True and timeout_counter < 64):
        timeout_counter += 1
        dut = factorial_clk(dut, in_data, in_valid)
    print(f"Factorial of 5 {dut.out_data}, out_valid: {dut.out_valid}, out_busy: {dut.out_busy}")
    dut = factorial_clk(dut, in_data, in_valid)

