`timescale 1ns / 1ps


module testbench;
    reg[3:0] A,B;
    wire AstB, AltB, AeqB;

    comparator com0(
        .a(A),
        .b(B),
        .astb(AstB),
        .altb(AltB),
        .aeqb(AeqB)
    );
    
    initial begin
        A <= 4'b0001;
        B <= 4'b0001;
        #20
        A <= 4'b0010;
        B <= 4'b0001;
        #20
        A <= 4'b1100;
        B <= 4'b1101;
        #20
        A <= 4'b0110;
        B <= 4'b0110;
    end
endmodule
