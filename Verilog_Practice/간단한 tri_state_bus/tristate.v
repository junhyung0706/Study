`timescale 1ns / 1ps


module tristate(
    input in,
    input oe,
    output out
    );
    
    assign out = oe ? in : 1'bz;
    
endmodule
