module top_module (
    input clk,
    input reset,
    output [9:0] q);

    integer count = 0;
    always@(posedge clk) begin
        if(!reset) begin
            if(count < 1000) begin
            	q=count;
            	count = count + 1;
            end
            else begin
                count = 0;
                q=count;
                count = count + 1;
            end
        end
        else begin
        	count = 0;
            q=count;
            count = count + 1;
        end
    end
endmodule
