package FPMul64;

interface FPMul64_ifc;
    method Action put_A(Bit#(64) a_in);
    method Action put_B(Bit#(64) b_in);
    method ActionValue#(Bit#(64)) get_res();
endinterface: FPMul64_ifc

(* synthesize *)
module mkFPMul64 (FPMul64_ifc);
    
    Reg#(Bit#(64)) input_1_64 <- mkReg(0);
    Reg#(Bit#(64)) input_2_64 <- mkReg(0);
    Reg#(Bit#(1)) sign_out <- mkReg(0);
    Reg#(Bit#(52)) mantissa_A <- mkReg(0);
    Reg#(Bit#(52)) mantissa_B <- mkReg(0);
    Reg#(Bit#(12)) exponent_res_overbiased_1 <- mkReg(0);
    Reg#(Bit#(12)) exponent_res_overbiased_2 <- mkReg(0);
    Reg#(Bit#(12)) exponent_res_normalised_1 <- mkReg(0);
    Reg#(Bit#(11)) exponent_res_normalised_2 <- mkReg(0);    
    Reg#(Bit#(11)) exponent_res_normalised_3 <- mkReg(0);        
    Reg#(Bit#(106)) mantissa_res_non_normalised <- mkReg(0);
    Reg#(Bit#(52)) mantissa_res_non_normalised_reduced <- mkReg(0);
    Reg#(Bit#(52)) mantissa_res_normalised <- mkReg(0);
    Reg#(Bit#(64)) answer <- mkReg(0);
    
    Reg#(Bool) got_A <- mkReg(False);
    Reg#(Bool) got_B <- mkReg(False);

    Reg#(Bool) stage1 <- mkReg(False);
    Reg#(Bool) stage2 <- mkReg(False);
    Reg#(Bool) stage3 <- mkReg(False);
    Reg#(Bool) got_final <- mkReg(False);


    // Rule for extracting sign and exponent
    rule preprocessing(got_A && got_B);
        sign_out <= input_1_64[63]^input_2_64[63];
        exponent_res_overbiased_1 <= {1'b0,input_1_64[62:52]} + {1'b0,input_2_64[62:52]}; 
        mantissa_A <= input_1_64[51:0];
        mantissa_B <= input_2_64[51:0];
	stage1 <= True;
	//$display("\nStage1 done mantissa_A - %b, mantissa_B - %b, sign_out - %b, exp - %b", mantissa_A,mantissa_B,sign_out,exponent_res_overbiased_1);
    endrule


    rule exponentNormalisation(stage1);
    	exponent_res_normalised_1 <= exponent_res_overbiased_1 - 12'b001111111111;
	mantissa_res_non_normalised <= {53'b0,1'b1,mantissa_A}*{53'b0,1'b1,mantissa_B};
	stage2 <= True;
	//$display("\nStage2 done exp - %b, man - %b",exponent_res_normalised_1,mantissa_res_non_normalised);	
    endrule
		
	function Integer leadingBitPosition(Bit#(106)value);
	Integer flag = 1;
	Integer position = 105;
	for(Integer i = 105; i >= 0; i = i-1) begin
		if(value[i] == 1'b1 && flag == 1) begin
			position = i;
			flag = 0;
		end
	end
	return position;
	endfunction
		

    rule mantissaNormalisation(stage2);
	Integer shiftvalue = 0;
	Integer temp = 0;

    	shiftvalue = leadingBitPosition(mantissa_res_non_normalised);
    	mantissa_res_non_normalised_reduced <= (mantissa_res_non_normalised << (105 - shiftvalue + 1))[105:54];
    	temp = 104-shiftvalue;
	Bit#(11) shif = fromInteger(temp);    	
    	exponent_res_normalised_2 <= exponent_res_normalised_1[10:0] - shif;

	//$display("\nStage5 done mantissa non normalised - %b normalised",mantissa_res_non_normalised_reduced,mantissa_res_normalised);
	stage3 <= True;
	//$display("\nStage3 done man_reduced - %b, shift - %d",mantissa_res_non_normalised_reduced,shiftvalue);		
    endrule
    
    rule finalResult(stage3);
    	if (input_1_64 == 64'b0 || input_2_64 == 64'b0) begin 
    	answer <= 64'b0;
    	got_final <= True;
    	end
    	else begin
    	answer <= {sign_out,exponent_res_normalised_2,mantissa_res_non_normalised_reduced};
    	//$display("Answer = %b",answer);
    	if(answer==64'b0) got_final <= False;
        else got_final <= True;
        end
    endrule

    // Input mapping to registers
    method Action put_A(Bit#(64) a_in) if (!got_A);
        input_1_64 <= a_in;
        got_A <= True;
    endmethod

    method Action put_B(Bit#(64) b_in) if (!got_B);
        input_2_64 <= b_in;
        got_B <= True;
    endmethod

    // Output mapping from registers
    method ActionValue#(Bit#(64)) get_res() if (got_final && got_A && got_B);
        return answer;
    endmethod

endmodule

endpackage
