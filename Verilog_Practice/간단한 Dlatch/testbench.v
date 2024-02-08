`timescale 1ns / 1ps

module testbench(
    
    );
    
    reg D;
    reg clk;
    wire Q;
    
    Dlatch Dlatch_(
        .d(D),
        .clk(clk),
        .q(Q)
    );
    
    always
        #10 clk = ~clk;
    
    initial begin
        clk = 1'b0;
        D = 1'b0;
    end
    
    always begin
        #15 D = 1'b1;
        #20 D = 1'b0;
        #10 D = 1'b1;
        #10 D = 1'b0;
        #10 D = 1'b1;
        #15 D = 1'b0;
    end
    
endmodule
