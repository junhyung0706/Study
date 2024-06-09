module M(out,a,b,c,d);
output out;
input a,b,c,d;
wire e,f;
specify
    if(a) (a=>out)=9;
    if(~a) (a=>out)=10;
    if(b&c)(b=>out)=9;
    if(~(b&c)) (b=>out)=13;
    if({c,d}==2'b01) (c,d*>out)=11;
    if({c,d}!=2'b01) (c,d*>out)=13;
endspecify
and a1(e,a,b);
and a2(f,c,d);
and a3(out,e,f);
endmodule