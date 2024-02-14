module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);

    wire[15:0] con;
    wire[15:0] alt_sum1;
    wire[15:0] alt_sum2;
    wire sel;
    
    add16 add16_1(
        .a(a[15:0]),
        .b(b[15:0]),
        .cin(1'b0),
        .cout(sel),
        .sum(sum[15:0])
    );
    
    add16 add16_2(
        .a(a[31:16]),
        .b(b[31:16]),
        .cin(1'b0),
        .sum(alt_sum1)
    );
    
    add16 add16_3(
        .a(a[31:16]),
        .b(b[31:16]),
        .cin(1'b1),
        .sum(alt_sum2)
    );
    
    always@(sel,alt_sum1,alt_sum2) begin
        case(sel)
            0 : sum[31:16] = alt_sum1;
            1 : sum[31:16] = alt_sum2;
            default : sum[31:16] = sum[31:16];
        endcase
    end
    
endmodule
