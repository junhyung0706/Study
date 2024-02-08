`timescale 1ns / 1ps


module comparator(
    input[3:0] a,
    input[3:0] b,
    output astb,
    output altb,
    output aeqb
    );
    
    assign astb = (a < b);
    assign altb = (a > b);
    assign aeqb = (a == b);
    
endmodule
