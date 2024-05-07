`timescale 1ns / 1ps

module Top(
    input [1:0] sw,
    input [3:0] btn,
    output led4_r, led4_g, led4_b, led5_r, led5_g, led5_b
    );
    
    wire [2:0] rgb_in;
    wire [5:0] rgb_out;
    
    RGB_Decoder DEC(
        .in(rgb_in),
        .out(rgb_out)
    );
    
    assign rgb_in[0] = btn[0];
    assign rgb_in[1] = sw[0];
    assign rgb_in[2] = sw[1];
    
    assign led4_r = rgb_out[5];
    assign led4_g = rgb_out[4];
    assign led4_b = rgb_out[3];
    assign led5_r = rgb_out[2];
    assign led5_g = rgb_out[1];
    assign led5_b = rgb_out[0];
    
endmodule
