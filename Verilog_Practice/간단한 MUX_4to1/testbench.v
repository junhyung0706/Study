`timescale 1ns / 1ps


module testbench;
    reg[3:0] a,b,c,d;
    reg[1:0] sel;
    wire[3:0] y;
    
    mux4_1 m0(sel,a,b,c,d,y);
    
    initial begin
        a<=4'b0000;
        b<=4'b0001;
        c<=4'b0010;
        d<=4'b0011;
    
        sel <= 2'b00;
        #20 sel <= 2'b01;
        #20 sel <= 2'b10;
        #20 sel <= 2'b11;
    end 
endmodule
