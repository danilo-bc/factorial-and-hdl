#include "factorial_cpp.hpp"

void factorial_cpp::factorial_proc(){
    if(!resetn){
        curr_state = INIT;
        calc_buffer = 1;
        counter = 0;
        out_valid = 0;
        out_busy = 0;
    }
    while(true){
        switch(curr_state){
            case INIT:
                if(in_valid) next_state = CALC;
                else next_state = INIT;
                break;
            case CALC:
                if(counter == 1) next_state = DONE;
                else next_state = CALC;
                break;
            case DONE:
                next_state = INIT;
                break;
            default:
                next_state = INIT;
        }

        switch(curr_state){
            case INIT:
                out_valid = 0;
                if(in_valid){
                    counter = in_data;
                    out_busy = 1;
                }
                break;
            case CALC:
                calc_buffer = calc_buffer * counter;
                counter = counter - 1;
                break;
            case DONE:
                out_data = calc_buffer;
                calc_buffer = 1;
                out_valid = 1;
                out_busy = 0;
                break;
            default:
                break;
        }

        curr_state = next_state;
        wait();
    }
}