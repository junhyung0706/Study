`timescale 1ns / 1ps


module testbench;
    reg[3:0] a;
    wire y;
    integer i;
    
    nand4 u0(a,y);
    
    initial begin
        a=0;
        for(i=1;i<32;i=i+1) begin
            #20 a = i;
        end
    end
endmodule
