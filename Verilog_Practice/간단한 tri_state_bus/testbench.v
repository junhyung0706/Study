`timescale 1ns / 1ps


module testbench;
    reg in;
    reg oe;
    wire out;
    
    tristate t0(
        .in(in),
        .oe(oe),
        .out(out)
    );
    
    initial begin
        oe <= 1'b0;
        in <= 1'b0;
        #10 in = 1'b1;
        #10 in = 1'b0;
        #10 oe = 1'b1;
        #10 in = 1'b1;
        #10 in = 1'b0;
        #10 oe = 1'b0;
        #10 in = 1'b1;
        #10 in = 1'b0;
    end
endmodule
