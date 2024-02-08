`timescale 1ns / 1ps

module testbench;
    reg a,b,c,d,e;
    wire y;
    
    boolmodeling u0(a,b,c,d,e,y);

    initial begin
        a=0; b=1; c=0; d=1; e=0;
        #20 a=1; b=0; c=1; d=0; e=1;
        #20;
    end
endmodule
