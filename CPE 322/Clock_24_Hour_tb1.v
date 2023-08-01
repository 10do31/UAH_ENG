//Common testbench for both structural and behavioral models.


`timescale 1ns / 1ps

module Clock_24_Hour_tb1;

	// Inputs
	reg CLK;
	reg Reset_time;
	reg Set_time;
	reg [23:0] Time_in;
	
	// Outputs
	wire [23:0] Time_out;
	
	// Instantiate the Unit Under Test (UUT)
	// Uncomment one of the following to use behavioral or structural model
	//Clock_24_Hour_behavioral uut(.CLK(CLK), .Reset_time(Reset_time), .Set_time(Set_time), .Time_in(Time_in), .Time_out(Time_out));
	Clock_24_Hour_structural uut(.CLK(CLK), .Reset_time(Reset_time), .Set_time(Set_time), .Time_in(Time_in), .Time_out(Time_out));
	
	// Clock period definitions
	parameter PERIOD = 10;
	
	// Clock generation
	always #5 CLK = ~CLK;
	
	initial begin
		// Initialize Inputs
		CLK = 0;
		Reset_time = 0;
		Set_time = 0;
		Time_in = 24'h000000;
		
		// Wait for 100 ns to allow initialization to complete
		#100;
		
		// Test Reset_time
		Reset_time = 1;
		#20;
		Reset_time = 0;
		
		// Test Set_time
		Set_time = 1;
		#20;
		Set_time = 0;
		
		// Test Time_in
		Time_in = 24'h001234;
		#20;
		Time_in = 24'h002345;
		#20;
		Time_in = 24'h003456;
		
		// Add additional test cases here...
		
		// Wait for simulation to complete
		#100;
		
		// End simulation
		$finish;
		
	end
	
endmodule
