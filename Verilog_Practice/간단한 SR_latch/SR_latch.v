`timescale 1ns / 1ps

module SR_latch(Q, Qbar, Sbar, Rbar);
    input wire Sbar, Rbar;
    output wire Q, Qbar;
    
    nand n1(Q, Sbar, Qbar);
    nand n2(Qbar, Rbar, Q);
    
endmodule
