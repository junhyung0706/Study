module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);

    wire w1;
    wire[31:0] b_xor;
    
    assign b_xor = {32{sub}}^b;
    
    add16 add16_1(
        .a(a[15:0]),
        .b(b_xor[15:0]),
        .cin(sub),
        .sum(sum[15:0]),
        .cout(w1)
    );
    
    add16 add16_2(
        .a(a[31:16]),
        .b(b_xor[31:16]),
        .cin(w1),
        .sum(sum[31:16])
    );
    
endmodule
