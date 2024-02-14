module top_module ( input clk, input d, output q );

    wire w1;
    wire w2;
    
    my_dff my_diff1(
        .clk(clk),
        .d(d),
        .q(w1)
    );
    
    my_dff _my_dff2(
        .clk(clk),
        .d(w1),
        .q(w2)
    );
    
    my_dff _my_dff3(
        .clk(clk),
        .d(w2),
        .q(q)
    );
    
endmodule
