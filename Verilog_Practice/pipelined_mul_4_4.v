module pipelined_multiplier_4bit (
    input clk,
    input reset,
    input [3:0] A,  // 4-bit input A
    input [3:0] B,  // 4-bit input B
    output reg [7:0] P  // 8-bit output Product
);

    reg [3:0] A_reg1, B_reg1;
    reg [3:0] pp0_reg1, pp1_reg1, pp2_reg1, pp3_reg1;
    reg [7:0] sum0_reg2, sum1_reg2, sum2_reg2, sum3_reg2;
    reg [7:0] temp1_reg3, temp2_reg3;

    // Stage 1: Generate partial products
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            A_reg1 <= 4'b0;
            B_reg1 <= 4'b0;
            pp0_reg1 <= 4'b0;
            pp1_reg1 <= 4'b0;
            pp2_reg1 <= 4'b0;
            pp3_reg1 <= 4'b0;
        end else begin
            A_reg1 <= A;
            B_reg1 <= B;
            pp0_reg1 <= A & {4{B[0]}};
            pp1_reg1 <= A & {4{B[1]}};
            pp2_reg1 <= A & {4{B[2]}};
            pp3_reg1 <= A & {4{B[3]}};
        end
    end

    // Stage 2: Shift the partial products
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            sum0_reg2 <= 8'b0;
            sum1_reg2 <= 8'b0;
            sum2_reg2 <= 8'b0;
            sum3_reg2 <= 8'b0;
        end else begin
            sum0_reg2 <= {4'b0000, pp0_reg1};
            sum1_reg2 <= {3'b000, pp1_reg1, 1'b0};
            sum2_reg2 <= {2'b00, pp2_reg1, 2'b00};
            sum3_reg2 <= {1'b0, pp3_reg1, 3'b000};
        end
    end

    // Stage 3: Sum the partial products
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            temp1_reg3 <= 8'b0;
            temp2_reg3 <= 8'b0;
            P <= 8'b0;
        end else begin
            temp1_reg3 <= sum0_reg2 + sum1_reg2;
            temp2_reg3 <= sum2_reg2 + sum3_reg2;
            P <= temp1_reg3 + temp2_reg3;
        end
    end

endmodule
