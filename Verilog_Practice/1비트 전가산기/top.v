module top(A,B,Cin,S,Cout);
	input A,B,Cin;
	output S,Cout;

	wire w1, s2, w3;

Xor Xor_1(.a(A), .b(B), .c(w1));
Xor Xor_2(.a(w1), .b(Cin), .c(S));
And And_1(.a(Cin), .b(w1), .c(w2));
And And_2(.a(A), .b(B), .c(w3));
Or Or_1(.a(w2), .b(w3), .c(Cout));

endmodule
