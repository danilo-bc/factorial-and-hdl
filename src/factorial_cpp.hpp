#include <systemc.h>

#ifndef FACTORIAL_CPP_HPP
#define FACTORIAL_CPP_HPP

#define INIT 0
#define CALC 1
#define DONE 2

SC_MODULE (factorial_cpp){
    private:

    int curr_state;
    int next_state;

    int calc_buffer;
    int counter;

    public:
    sc_in<bool> clk;
    sc_in<bool> resetn;
    sc_in<int> in_data;
    sc_in<bool> in_valid;
    sc_out<int> out_data;
    sc_out<bool> out_valid;
    sc_out<bool> out_busy;

    void factorial_proc();

    SC_CTOR (factorial_cpp){
        SC_CTHREAD(factorial_proc, clk.pos());
        async_reset_signal_is(resetn, false);
    }
}; // end of SC_MODULE macro represeting a C++ class

#endif