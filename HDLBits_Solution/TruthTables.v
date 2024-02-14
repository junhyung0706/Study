module top_module( 
    input x3,
    input x2,
    input x1,  // three inputs
    output f   // one output
);
    
    always@(*) begin
        if(x3==0 && x2==0 && x1==0) f=0;
        else if(x3==0 && x2==0 && x1==1) f=0;
        else if (x3==0 && x2==1 && x1==0) f=1;
        else if (x3==0 && x2==1 && x1==1) f=1;
        else if (x3==1 && x2==0 && x1==0) f=0;
        else if (x3==1 && x2==0 && x1==1) f=1;
        else if (x3==1 && x2==1 && x1==0) f=0;
        else if (x3==1 && x2==1 && x1==1) f=1;
    end
    

endmodule
