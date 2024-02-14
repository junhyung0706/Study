module top_module( 
    input a, b, sel,
    output out ); 

    always@(*) begin
        case(sel)
            0 : out = a;
            1 : out = b;
            default : out = out;
        endcase
    end
endmodule
