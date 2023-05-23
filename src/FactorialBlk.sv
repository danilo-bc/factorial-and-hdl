module FactorialBlk(
    input logic clk,
    input logic resetn,
    input logic [3:0] in_data,
    input logic in_valid,
    output logic [45:0] out_data,
    output logic out_valid,
    output logic out_busy
    );

    localparam INIT = 2'b00;
    localparam CALC = 2'b01;
    localparam DONE = 2'b10;

    logic [1:0] curr_state;
    logic [1:0] next_state;

    logic [45:0] calc_buffer;
    logic [3:0] counter;

    always_comb begin
        case (curr_state)
            INIT: begin
                if (in_valid) next_state = CALC;
                else next_state = INIT;
            end
            CALC: begin
                if (counter == 1) next_state = DONE;
                else next_state = CALC;
            end
            DONE: begin
                next_state = INIT;
            end
        endcase
    end

    always_ff @(posedge clk or negedge resetn) begin
        if(!resetn) begin
            curr_state <= INIT;
        end
        else begin
            curr_state <= next_state;
        end
    end

    always_ff @(posedge clk or negedge resetn) begin
        if (!resetn) begin
            calc_buffer <= 46'b1;
            counter <= 4'b0;
            out_valid <= 1'b0;
            out_busy <= 1'b0;
        end
        else begin
            case (curr_state)
                INIT: begin
                    out_valid <= 1'b0;
                    if (in_valid) begin
                        counter <= in_data;
                        out_busy <= 1'b1;
                    end
                end
                CALC: begin
                    calc_buffer <= calc_buffer * counter;
                    counter <= counter - 1;
                end
                DONE: begin
                    out_data <= calc_buffer;
                    calc_buffer <= 46'b1;
                    out_valid <= 1'b1;
                    out_busy <= 1'b0;
                end
            endcase
        end
    end
endmodule
