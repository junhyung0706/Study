`timescale 1ns / 1ps


module testbench(

    );
    
    reg clk;
    reg rst;
    reg s_in;
    wire s_out;
    integer i;
    
    shift_reg shift_reg_1(
        .clk(clk),
        .rst(rst),
        .sin(s_in),
        .sout(s_out)
    );
    
    always
        #10 clk = ~clk;
    
    initial begin
        clk = 1'b0;
        rst = 1'b1;
        s_in = 1'b0;
    end
    
    always begin
        for (i = 0; i < 32; i=i+1) begin
            #20 s_in = i;
        end
    end
endmodule
