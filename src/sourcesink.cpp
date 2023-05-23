#include "sourcesink.hpp"

void sourcesink::sourcesink_proc(){
    while(true){
        // Attempt to copy FactorialBlk_TB's sequence
        resetn = 0;
        in_data = 0;
        in_valid = 0;

        wait();
        
        resetn = 1;
        wait();

        in_data = 3;
        in_valid = 1;
        wait();

        in_data = 5;
        int timeout_counter = 0;
        while(out_valid != 1 && timeout_counter < 64){
            timeout_counter++;
            wait();
        }
        cout<<"Factorial of 3: "<<out_data<<" out_valid: "<<out_valid<<" out_busy: "<<out_busy<<endl;
        wait();
        
        timeout_counter = 0;
        while(out_valid != 1 && timeout_counter < 64){
            timeout_counter++;
            wait();
        }
        cout<<"Factorial of 5: "<<out_data<<" out_valid: "<<out_valid<<" out_busy: "<<out_busy<<endl;
        wait();
        
        sc_stop();
    }
}