
package Testbench;
import FPMul64 ::*;
(* synthesize *)
 module mkTestbench (Empty);
    FPMul64_ifc m <- mkFPMul64;
    real x = -1366.738;
    real y = -3.58983;
    real ans = 0;
    
    rule rl_go;
        m.put_A ($realtobits(x));
        m.put_B ($realtobits(y));
    endrule
    
    ans = x*y;
    
    rule rl_finish;
        let res = m.get_res();
        $display("\ntime at which it completed - ",$time);
        //if(res == ans) begin
        //$display("Passed");
        //end
    	$display("Correct value - %0h \nObtained value - %0h",$realtobits(ans),res);     
        $finish ();
    endrule


endmodule: mkTestbench
endpackage
