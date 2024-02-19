`timescale 1ns / 1ps


module rgb_fsm(
        input clk,
	input resetn,
	input [1:0] push,
	output reg [1:0] state,
	output reg [5:0] led_output
    );
    
        reg [1:0] push_reg;
        wire [1:0] push_button;
     
	parameter S0 = 2'b00;
	parameter S1 = 2'b01;
	parameter S2 = 2'b10;
	parameter S3 = 2'b11;
        reg [31:0] clkcnt=0;
        
        always @(posedge clk) begin
            push_reg <= push;
        end
        
        assign push_button[0] = push[0] & ~push_reg[0];
        assign push_button[1] = push[1] & ~push_reg[1];

    //State Transition
	always @(negedge resetn or posedge clk) begin
		if ( !resetn )
			state <= S0;
		else if ( push_button == 2'b01 ) begin
		case ( state )
	S0 : state <= S1;
	S1 : state <= S2;
	S2 : state <= S1;
			default : state <= state;
		endcase
		end
		else if ( push_button == 2'b10 ) begin
		case ( state )
	   S0 : state <= S3;
	   S1 : state <= S3;
	   S2 : state <= S3;
	   S3 : state <= S1;
			default : state <= state;
		endcase
		end
		else
			state <= state;
	end

	//Output Operation
	always @(posedge clk) begin
	    clkcnt <= clkcnt + 1;
	    if (clkcnt > 32'd130_000_000 * 2 - 1) begin
		clkcnt <= 0;
	    end
		case ( state )
	   S0 : led_output <= 6'b111_111;
	   S1 : led_output <= 6'b010_100;
	   S2 : led_output <= 6'b100_010;
	   S3 : begin
	       if (clkcnt < 32'd130_000_000) begin
		   led_output <= 6'd000_000;
	   end
	   else begin
	       led_output <= 6'd110_110;
	   end
       end
			default : led_output <= 6'b000000;
		endcase
	end
		
endmodule
