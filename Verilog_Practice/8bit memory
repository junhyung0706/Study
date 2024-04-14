module memory(
    output [7:0] out;
    input [7:0] in,
    input [7:0] addr,
    input wr, clk,rst
);

reg [7:0] mem [0:255];
reg [8:0] initaddr;

always @(posedge clk) begin
    if(rst) begin
        for(initaddr=0;initaddr<256;initaddr=initaddr+1) begin
            mem[initaddr] <= 8'd0;
        end
    end
    else if (wr) mem[addr] <= in;      
end

always @(posedge clk) out <= mem[addr];
endmodule
