module Clock_24_Hour_structural (
    input CLK, Reset_time, Set_time, 
    input [23:0] Time_in, 
    output reg [23:0] Time_out
);

parameter MOD_1 = 10; // modulus for the first counter
parameter MOD_2 = 6;  // modulus for the second counter
parameter MOD_3 = 24; // modulus for the third counter

wire [3:0] cnt1_out, cnt2_out, cnt3_out;

Four_Bit_Mod_n_Counter #(.MOD(MOD_1)) counter1 (.CLK(CLK), .Reset(Reset_time), .Q(cnt1_out));
Four_Bit_Mod_n_Counter #(.MOD(MOD_2)) counter2 (.CLK(CLK), .Reset(Reset_time), .Q(cnt2_out));
Four_Bit_Mod_n_Counter #(.MOD(MOD_3)) counter3 (.CLK(CLK), .Reset(Reset_time), .Q(cnt3_out));

always @ (posedge CLK) begin
    if (Reset_time) begin
        Time_out <= Set_time;
    end
    else begin
        Time_out <= {cnt3_out, cnt2_out, cnt1_out, Time_in[3:0]};
    end
end

endmodule

module Four_Bit_Mod_n_Counter #(.MOD(16)) (
    input CLK, Reset, 
    output reg [3:0] Q
);

always @(posedge CLK or posedge Reset) begin
    if (Reset) begin
        Q <= 4'b0000;
    end
    else begin
        Q <= Q + 1;
        if (Q == MOD-1) begin
            Q <= 4'b0000;
        end
    end
end

endmodule




//TESTBENCH:
// Copy this and paste in separate testbench file:
module Clock_24_Hour_structural_tb();

reg CLK, Reset_time, Set_time;
reg [23:0] Time_in;
wire [23:0] Time_out;

Clock_24_Hour_structural clock(.CLK(CLK), .Reset_time(Reset_time), .Set_time(Set_time), .Time_in(Time_in), .Time_out(Time_out));

initial begin
    CLK = 0;
    Reset_time = 1;
    Set_time = 24'b000000000000000000000000;
    Time_in = 24'b000000000000000000000000;
    #10 Reset_time = 0;
    #10 Set_time = 24'b000000000000000000000101;
    #10 Time_in = 24'b000000000000000000000010;
    #100 $finish;
end

always #5 CLK = ~CLK;

endmodule
