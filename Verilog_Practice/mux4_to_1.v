module mux4_to_1(out, i0, i1, i2, i3, s1, s0);
output out;
input i1, i2, i3;
input s1, s0;
reg out;

always @(s1 or s0 or i0, i1, i2, i3)
    case({s1,s0})
       2'd0 : out = i0;
       2'd1 : out = i1;
       2'd2 : out = i2;
       2'd3 : out = i3;
       default : $display("invalid control signals"); 
    endcase
endmodule
