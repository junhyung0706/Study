`timescale 1ns / 1ps

module nand4(a,y);
    input[3:0] a;
    output y;
    
    assign y = ~&a;
    
endmodule
