`timescale 1ns / 1ps


module shift_reg(
    input clk,
    input rst,
    input sin,
    output sout
    );
    
    reg[7:0] q;
    assign sout = q[7];
    
    always@(posedge clk) begin
        if(!rst) q = 8'b0;
        else begin
            q[0] <= sin;
            q[7:1] <= q[6:0];
        end
   end 
endmodule
