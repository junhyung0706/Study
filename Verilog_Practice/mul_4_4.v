module mul4_4(OUTPUT, INPUT1, INPUT2);
    output [7:0] OUTPUT,
    input [3:0] INPUT1, INPUT2

    wire [3:0] pp0, pp1, pp2, pp3;
    wire [7:0] sum0, sum1, sum2;

    assign pp0 = A & {4{B[0]}};
    assign pp1 = A & {4{B[1]}};
    assign pp2 = A & {4{B[2]}};
    assign pp3 = A & {4{B[3]}};

    assign sum0 = {4'b0000, pp0};
    assign sum1 = {3'b000, pp1, 1'b0};
    assign sum2 = {2'b00, pp2, 2'b00};
    assign sum3 = {1'b0, pp3, 3'b000};

    wire [7:0] temp1, temp2;

    assign temp1 = sum0 + sum1;
    assign temp2 = sum2 + sum3;
    assign OUTPUT = temp1 + temp2;

endmodule