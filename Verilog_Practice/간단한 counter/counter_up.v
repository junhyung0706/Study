`timescale 1ns / 1ps


module counter_up(
    input clk,
    input rst,
    output reg[7:0] cnt
    );
    
    always@(posedge clk or negedge rst) begin
        if(!rst) cnt <= 0;
        else cnt <= cnt + 1;
    end
endmodule
