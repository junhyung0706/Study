module top_module (
    input clk,
    input reset,        // Synchronous active-high reset
    output [3:0] q);

    integer count = 4'd1;
    always@(posedge clk)begin
        if(reset) begin
        	count = 4'd1;
            q=count;
        end 
        else begin
        	count=count+1;
            if(count==11) begin
            	count = 4'b1;
            end
            q=count;
        end
    end
endmodule

