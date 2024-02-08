`timescale 1ns / 1ps

module segment_test();

    reg[7:0] seg_print_out;
    integer i;
    initial begin
        for(i=0; i<10; i=i+1)
        begin
            seg_print_out = seg_print(i);
            #10
            $display("A: %d", i);
        end
        $finish;
    end
    function[7:0] seg_print;
         input integer seg_in;
         begin
            case(seg_in)
                0 : seg_print = 8'b1111_1100;
                1 : seg_print = 8'b0110_0000;
                2 : seg_print = 8'b1101_1010;
                3 : seg_print = 8'b1111_0010;
                4 : seg_print = 8'b0110_0110;
                5 : seg_print = 8'b1011_0110;
                6 : seg_print = 8'b1011_1110;
                7 : seg_print = 8'b1110_0000;
                8 : seg_print = 8'b1111_1110;
                9 : seg_print = 8'b1111_0110;
            endcase
        end
    endfunction
endmodule
