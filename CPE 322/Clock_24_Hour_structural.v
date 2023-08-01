module Four_Bit_Mod_n_Counter #(parameter n = 16)
  (input clk, rst, enable,
   output reg [3:0] q);

  always @ (posedge clk) begin
    if (rst) begin
      q <= 4'b0000;
    end
    else if (enable) begin
      q <= q + 1;
      if (q == n-1) begin
        q <= 4'b0000;
      end
    end
  end
endmodule

module Clock_24_Hour_structural
  (input clk, rst,
   input [23:0] Time_in,
   input [23:0] Set_time,
   input [23:0] Reset_time,
   output reg [23:0] Time_out);

  // Define the moduli for each counter instance
  parameter MOD1 = 10;
  parameter MOD2 = 6;
  parameter MOD3 = 24;

  // Create instances of the four-bit counters with the specified moduli
  Four_Bit_Mod_n_Counter #(MOD1) counter1 (.clk(clk), .rst(rst), .enable(1'b1), .q(Time_out[3:0]));
  Four_Bit_Mod_n_Counter #(MOD2) counter2 (.clk(clk), .rst(rst), .enable(counter1.q == MOD1-1), .q(Time_out[9:6]));
  Four_Bit_Mod_n_Counter #(MOD3) counter3 (.clk(clk), .rst(rst), .enable(counter2.q == MOD2-1 && Time_in == Set_time && Time_in != Reset_time), .q(Time_out[23:10]));

  always @ (posedge clk) begin
    if (rst) begin
      Time_out <= 24'b000000000000000000000000;
    end
    else begin
      Time_out <= {counter3.q, counter2.q, counter1.q, Time_out[3:0]};
    end
  end

endmodule
