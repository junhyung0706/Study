module testbench;
	reg A,B,Cin;
	wire S, Cout;
top top(.A(A), .B(B), .Cin(Cin), .S(S), .Cout(Cout));

initial begin
	A <= 1'b0;
	B <= 1'b0;
	Cin <= 1'b0;
	#10
	B <= 1'b1;
	#10
	A <= 1'b1;
	B <= 1'b0;
	#10
	B <= 1'b1;
	#10
	A <= 1'b0;
	B <= 1'b0;
	Cin <= 1'b1;
	#10
	B <= 1'b1;
	#10
	A <= 1'b1;
	B <= 1'b0;
	#10
	B <= 1'b1;
end
endmodule
