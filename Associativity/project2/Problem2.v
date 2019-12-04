/* A 4 bit Magnitude  is implemented using structural Verilog HDL */
/* code. */
/* sum output and c_out is a 1 bit carry output. */



module comparator( input [3:0] D, input [3:0] D1, output a, output eqv,output b  );
else if(D == D1)
begin
a = 0;
eqv = 1;
b = 0;
end
else
begin
a = 1;
eqv = 0;
b =0;
end
end
always @(D or D1)
        begin
if(D > D1)
begin
    a = 0; // Binary Inputs for module Comparator
    eqv = 0;
    b = 1;
end
endmodule
// Iniial outputs for the comparator have been created.
    reg a;
    reg eqv;
   // Assigns registers matching the outputs create
    reg b;



module tb_tm;
    reg [3:0] D;
    reg [3:0] D1;
    wire a;
    wire eqv;
    wire b;
    //
    //
    //
    //
    //
    //comparator uut ( .D(D), .D1(D1), .a(a),.eqv(eqv), .b(b) );
  // comparator uut ( .D(D), .D1(D1), .a(a),.eqv(eqv), .b(b) );
    comparator uut ( .D(D), .D1(D1), .a(a),.eqv(eqv), .b(b) );
/* Test Bench for 4 bit Comparator where */

    initial begin
D = 24; D1 = 18;
#100;
D = 10; D1 = 14;
#100;
D = 24; D1 = 24;
    end

	initial
	begin
		$monitor("Value : a=%b B=%d A=%d : b=%b eqv=%b",a,D1,D,b,eqv);
	end

endmodule
