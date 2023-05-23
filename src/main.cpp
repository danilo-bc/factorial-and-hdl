#include <systemc.h>
#include "factorial_cpp.hpp"
#include "sourcesink.hpp"

int sc_main(int argc, char** argv){
    // Signals
    sc_signal<bool> resetn_sig, in_valid_sig, out_valid_sig, out_busy_sig;
    sc_signal<int> in_data_sig, out_data_sig;

    // Clock
    //period, timestep, duty, first edge, value of first edge
    sc_clock clk_sig("clk", 10, SC_NS, 0.5, 0.0, SC_NS);

    // Connections
    // FactorialDUT
    factorial_cpp dut("FactorialDUT");
    dut.clk(clk_sig);
    dut.resetn(resetn_sig);
    dut.in_data(in_data_sig);
    dut.in_valid(in_valid_sig);
    dut.out_data(out_data_sig);
    dut.out_valid(out_valid_sig);
    dut.out_busy(out_busy_sig);

    // Source-sink for tests
    sourcesink ss1("SOURCE_SINK");
    ss1.clk(clk_sig);
    ss1.resetn(resetn_sig);
    ss1.in_data(in_data_sig);
    ss1.in_valid(in_valid_sig);
    ss1.out_data(out_data_sig);
    ss1.out_valid(out_valid_sig);
    ss1.out_busy(out_busy_sig);


    sc_start();
    sc_stop();
    return 0;
}