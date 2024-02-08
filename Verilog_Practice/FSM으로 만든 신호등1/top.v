`timescale 1ns / 1ps


module top(
    input clk,
    input resetn,
    input [1:0] push_n, // GPIO PUSHBUTTON
	output [1:0] state,
	output [5:0] led_output
    );
    
    wire [1:0] push;
    assign push = ~push_n;
    
   	rgb_fsm rgb_fsm( // your fsm design
	.clk(clk),
	.resetn(resetn),
	.push(push), // pedestrian button
	.state(state), // state output showed in 3 LEDs
	.led_output(led_output) // RGB led outputs
	);
    
endmodule

