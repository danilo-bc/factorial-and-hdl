module FactorialBlk_TB();

logic clk;
logic resetn;
logic [3:0] in_data;
logic in_valid;
logic [45:0] out_data;
logic out_valid;
logic out_busy;

FactorialBlk dut (
    .clk(clk),
    .resetn(resetn),
    .in_data(in_data),
    .in_valid(in_valid),
    .out_data(out_data),
    .out_valid(out_valid),
    .out_busy(out_busy)
);

always begin
    #5 clk = ~clk;
end

initial begin
    clk = 0;
    resetn = 0;
    in_data = 0;
    in_valid = 0;

    // Reset
    #5 resetn = 1;

    // Calculate factorial for input 3
    #5 in_data = 3;
    in_valid = 1;

    @(posedge out_valid);
    $display("Factorial of 3: %0d, out_valid: %0d, out_busy: %0d", out_data, out_valid, out_busy);
    // Calculate factorial for input 5
    in_data = 5;
    #5

    @(posedge out_valid);    
    $display("Factorial of 5: %0d, out_valid: %0d, out_busy: %0d", out_data, out_valid, out_busy);

    #5 $finish;
end

endmodule
