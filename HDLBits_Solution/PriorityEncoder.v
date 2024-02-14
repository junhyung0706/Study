// synthesis verilog_input_version verilog_2001
module top_module (
    input [3:0] in,
    output reg [1:0] pos  );

    always@(*) begin
        if (in[0:0] == 1) pos = 2'd00;
        else if (in[1:1] == 1) pos = 2'd01;
        else if (in[2:2] == 1) pos = 2'd10;
        else if (in[3:3] == 1) pos = 2'd11;
        else pos = 2'd00;
    end
    
endmodule
