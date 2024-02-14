module top_module (input [3:0] x,input [3:0] y,output [4:0] sum);
    wire w1,w2,w3;
    FA FA0(x[0],y[0],0,w1,sum[0]);
    FA FA1(x[1],y[1],w1,w2,sum[1]);
    FA FA2(x[2],y[2],w2,w3,sum[2]);
    FA FA3(x[3],y[3],w3,sum[4],sum[3]);
endmodule

module FA(input x,input y,input cin,output cout,output sum);
    assign sum = x^y^cin;
    assign cout = (x&y)|(y&cin)|(cin&x);
endmodule