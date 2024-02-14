module top_module ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);
    wire [7:0]w1;
    wire [7:0]w2;
    wire [7:0]w3;
    
    my_dff8 my_dff8_1(
        .clk(clk),
        .d(d),
        .q(w1)
    );
    
    my_dff8 my_dff8_2(
        .clk(clk),
        .d(w1),
        .q(w2)
    );
    
    my_dff8 my_dff8_3(
        .clk(clk),
        .d(w2),
        .q(w3)
    );
    
    always@(*) begin
        case(sel)
            0 : q = d;
            1 : q = w1;
            2 : q = w2;
            3 : q = w3;
            default q = q;
        endcase
    end

endmodule
