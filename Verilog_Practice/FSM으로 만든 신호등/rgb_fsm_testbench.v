`timescale 1ns / 1ps


module rgb_fsm_testbench( );

    reg clk;
    reg resetn;
    reg [1:0] push_n;
    wire [1:0] state;
    wire [5:0] led_output;
    
initial begin
        clk <= 0;

    forever #10 clk <= ~clk;
end
    
      
    initial begin
    resetn <= 0;
    push_n <= 0; 
    #20
      
    #20 resetn <= 1;
    
		#40 push_n <= 1; // go to vehicle mode
		#40 push_n <= 0; 
                    
        #40 push_n <= 1; // go to pedestrian mode
		#40 push_n <= 0;
		
		#40 push_n <= 1; // go to vehicle mode
		#40 push_n <= 0;
		
		#40 push_n <= 2; // go to flasher mode
		#40 push_n <= 0; 

		#120 push_n <= 2; // exit flasher mode
		#40 push_n <= 0; 

		#40 resetn <= 0;
		#40 resetn <= 1;
	
    end
        
    rgb_fsm rgb_fsm_tb(clk,resetn,push_n,state,led_output);
endmodule
