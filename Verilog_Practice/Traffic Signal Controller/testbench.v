'include sig_control.v
module testbench;
    wire[i:0] MAIN_SIG, CNTRY_SIG;
    reg CAR_ON_CNTRY_RD;
    reg clk, clear;

    sig_control SC(MAIN_SIG, CNTRY_SIG, CAR_ON_CNTRY_RD, clk, clear);

    initial
        $monitor ($time, "Main Sig = %b Country Sig = %b Car_on_cntry = %b", MAIN_SIG, CNTRY_SIG, CAR_ON_CNTRY_RD);
    
    initial begin
        clk = 'FALSE;
        forever #5 clk = ~clk;
    end

    initial begin
        CLEAR = 'TRUE;
        repeat(5) @(negedge clk);
        clear = 'FALSE;
    end

    initial begin
        CAR_ON_CNTRY_RD = 'FALSE;
        repeat(20) @(negedge clk); CAR_ON_CNTRY_RD = 'TRUE;
        repeat(10) @(negedge CLOCK); CAR_ON_CNTRY_RD = ‘FALSE;
        repeat(20) @(negedge CLOCK); CAR_ON_CNTRY_RD = ‘TRUE;
        repeat(10) @(negedge CLOCK); CAR_ON_CNTRY_RD = ‘FALSE;
        repeat(20) @(negedge CLOCK); CAR_ON_CNTRY_RD = ‘TRUE;
        repeat(10) @(negedge CLOCK); CAR_ON_CNTRY_RD = ‘FALSE;
        repeat(10) @(negedge CLOCK); $stop;
    end
endmodule
