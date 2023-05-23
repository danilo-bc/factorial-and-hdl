#include <systemc.h>

#ifndef SOURCESINK_HPP
#define SOURCESINK_HPP

SC_MODULE(sourcesink){
    // interface opposite to FactorialDUT
    // "in/out" preffixes maintained for simplicity
    public:
    sc_in<bool> clk;
    sc_out<bool> resetn;
    sc_out<int> in_data;
    sc_out<bool> in_valid;
    sc_in<int>  out_data;
    sc_in<bool> out_valid;
    sc_in<bool> out_busy;

    void sourcesink_proc();

    SC_CTOR(sourcesink){
        SC_CTHREAD(sourcesink_proc, clk.pos());
    }

};

#endif