`timescale 1ns / 1ps

module encoder_4to2(a,y);
    input[3:0] a;
    output reg[1:0] y;
    
    always@(*) begin
        case(a)
            1 : y <= 2'b00;
            2 : y <= 2'b01;
            4 : y <= 2'b10;
            8 : y <= 2'b11;
            default y <= y;
        endcase
    end
endmodule
