module top_module(
    input a,
    input b,
    input c,
    output out  ); 

    always@(a,b,c) begin
        if (a==0 && b==0 && c==0) out=0;
        else out=1;
    end
    
endmodule
