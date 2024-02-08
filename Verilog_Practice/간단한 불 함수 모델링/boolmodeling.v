`timescale 1ns / 1ps

module boolmodeling(a,b,c,d,e,y);
    input a,b,c,d,e;
    output y;
    
    assign y = ~((a|b)&(c|d)&e);
endmodule
