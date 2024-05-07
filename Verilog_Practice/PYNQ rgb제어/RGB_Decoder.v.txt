`timescale 1ns / 1ps

module RGB_Decoder(
    input [2:0] in,
    output reg [5:0] out
    );
    
    always @(*) begin
        case(in)
            3'b000 : out <= 6'b100_100;
            3'b001 : out <= 6'b101_101;
            3'b010 : out <= 6'b110_110;
            3'b011 : out <= 6'b010_010;
            3'b100 : out <= 6'b011_011;
            3'b101 : out <= 6'b001_001;
            3'b110 : out <= 6'b111_111;
            3'b111 : out <= 6'b000_000;
            default : out <= 6'b000_000;
        endcase
    end
    
    
endmodule
