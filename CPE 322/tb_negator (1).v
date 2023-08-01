// Testbench for negator.v
`timescale 1ns/100ps


module tb_negator;

   reg x=0,clk=1,en=0,reset=0;
   wire n;

   initial
      begin
        
      // Not testing the en input in this example
      // setting it to 1 so it responds to each
      // positive edge
      en = 1;

      // negate 1100 to produce 0100 (-4 to produce +4) 
      // assuming 4 bit two's complement arithmetic        

      // reset back to state 0
      // time = 0ns
      reset = 1;
      x = 0;
        
      // time = 10ns
      #10
      reset = 0;
      x = 0;   // LSB input = 0
        
      // time = 20ns
      #10
      reset = 0;
      x = 0;   // next input = 0

      // time = 30ns
      #10
      reset = 0;
      x = 1;   // next input = 1

      // time =40ns
      #10 
      reset = 0;
      x = 1;   // MSB input = 1
       

      // negate 011010 to produce 100110 (26 to produce -26) 
      // assuming 6 bit two's complement arithmetic        

      // reset back to state 0
      // time = 50ns
      #10
      reset = 1;
      x = 0;
        
      // time = 60ns
      #10
      reset = 0;
      x = 0;   // LSB input = 0
        
      // time = 70ns
      #10
      reset = 0;
      x = 1;   // next input = 1

      // time = 80ns
      #10
      reset = 0;
      x = 0;   // next input = 0

      // time =90ns
      #10 
      reset = 0;
      x = 1;   // MSB input = 1
        
      // time = 100ns
      #10
      reset = 0;
      x = 1;   // next input = 1

      // time =110ns
      #10 
      reset = 0;
      x = 0;   // MSB input = 0
      end

   // set up a free running clock with period 10 ns
   always
      begin
      clk = #5 ~clk;
      end
        
   // instantiate the negator as the unit under test (uut)
   negator uut (.X(x),.CLK(clk),.En(en),.Reset(reset),.N(n)); 

endmodule
