`timescale 1ns / 1ps


module top(xin, y, y2,neg);
    input[2:0] xin;
    output y, y2, neg;

    reg[2:0] tmp;
    assign y = tmp[2];
    assign y2 = tmp[1];
    assign neg = tmp[0];
    
    always@(xin) begin
        case(xin)
            0 : tmp = 3'b000;
            1, 2 : tmp = 3'b100;
            3 : tmp = 3'b010;
            4 : tmp = 3'b011;
            5, 6 : tmp = 3'b101;
            7 : tmp = 3'b001;
        endcase
    end
endmodule
