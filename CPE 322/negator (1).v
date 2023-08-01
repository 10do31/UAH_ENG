// mealy implementation of Negator -- Behavorial Description 
module negator(input CLK, X, En, Reset, output reg N);
    reg state, next_state;

    // combinational circuit portion
    always@(state,X)
        case (state)
            0 : if (X) begin N=1; next_state=1; end
                else   begin N=0; next_state=0; end
            1 : if (X) begin N=0; next_state=1; end
                else   begin N=1; next_state=1; end
        endcase
	
    // register portion
    always@(negedge CLK)
        if (Reset) state=0; // synchronous Reset
        else if (En) state=next_state;

endmodule
