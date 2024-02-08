`timescale 1ns / 1ps


module Dlatch(
    input d,
    input clk,
    output reg q
    );
    
    always@(*) begin
        if (clk)
            q = d;
    end
endmodule
