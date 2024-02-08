`timescale 1ns / 1ps

module rgb_fsm_2(
    input clk,
    input rst,
    input[1:0] push,
    output reg[2:0] state,
    output reg[5:0] led_output
    );
    reg[1:0] push_reg;
    wire[1:0] push_button;
    
    parameter S0 = 3'b000;
    parameter S1 = 3'b001;
    parameter S2 = 3'b010;
    parameter S3 = 3'b011;
    parameter S4 = 3'b100;
    
    reg[31:0] clkcnt1 = 0;
    reg[31:0] clkcnt2 = 0;
    reg[31:0] clkcnt3 = 0;
    
    always@(posedge clk) begin
        push_reg <= push;
    end 
    
    assign push_button[0] = push[0] & ~push_reg[0];
    assign push_button[1] = push[1] & ~push_reg[1];
    
    //state transition
    always@(posedge clk or negedge rst) begin
        if(!rst) state <= S0;
        else if(push_button == 2'b01) begin
            case(state)
                S0 : state <= S1;
                S1 : state <= S4;
                default : state <= state;
            endcase
        end
        else if(push_button == 2'b10) begin
            case(state)
                S0 : state <= S3;
                S1 : state <= S3;
                S2 : begin
                        state <= S3;
                        clkcnt1 <= 0;
                     end
                S3 : state <= S1;
                default : state <= state;
            endcase
        end
        else if (state == S2) begin
            clkcnt1 <= clkcnt1 + 1;
            if (clkcnt1 >= 32'd4) begin
                clkcnt1 <= 0;
                state <= S1;
            end
        end
        else if (state == S4) begin
            clkcnt2 <= clkcnt2 + 1;
            if(clkcnt2 >= 32'd0) begin
                clkcnt2 <= 0;
                state <= S2;
            end
        end
        else
            state <= state;
    end
    
    //output operation
    always@(posedge clk) begin
        clkcnt3 <= clkcnt3 + 1;
        if (clkcnt3 >= 32'd1) clkcnt3 <= 0;
        case (state)
            S0 : led_output <= 6'b111_111;
            S1 : led_output <= 6'b100_010;
            S2 : led_output <= 6'b010_100;
            S3 : begin
                    if(clkcnt3 >= 32'd1) led_output <= 6'b000_000;
                    else led_output <= 6'b110_110;
                 end
            S4 : led_output <= 6'b100_110;
            default : led_output = 6'b000_000;
        endcase
    end
endmodule
