`timescale 1ns / 1ps


module testbench;
    reg[2:0] xin;
    wire y, y2, neg;
    integer i;
    
    top top_1(xin, y, y2, neg);
    
    initial begin
        xin = 0;
        for(i=1;i<16;i=i+1) begin
            #20 xin = i;
        end
    end
endmodule
