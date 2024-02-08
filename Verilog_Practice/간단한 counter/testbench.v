`timescale 1ns / 1ps

module testbench();
    reg clk;
    reg rst;
    wire[7:0] cnt;
    
    counter_up count_up_(
        .clk(clk),
        .rst(rst),
        .cnt(cnt)
    );
    
    always
        #10 clk = ~clk;
        
    initial begin
        clk = 1'b0;
        rst = 1'b0;
        #20 rst = 1'b1;
    end
endmodule
