/* A 4 bit ripple carry adder is implemented using structural Verilog HDL */
/* code. a and b are 4 bit inputs and s and c_out are outputs. s is a 4 bit */
/* sum output and c_out is a 1 bit carry output. */

/*module adder16 ();
reg[15:0] c,d;
wire[15:0] e;
wire c16_out;
wire c1,c2,c3,cout;

adder FBA0(c1, e[3:0], c[3:0], d[3:0], 1'b0);
adder FBA1(c2, e[7:4], c[7:4], d[7:4], c1);
adder FBA2(c3, e[11:8], c[11:8], d[11:8], c2);
adder FBA3(c16_out, e[15:12], c[15:12], d[15:12], c3);

endmodule
*/
module adder ();

        reg[12:0] a, b; /* declare data types of inputs a and b */
		wire cin; 
        wire[12:0] s;    /* declare data type of output s */
        wire c_out;     /* declare data type of output c_out */

/* Instantiate the 1 bit full adder module defined below to form the */
/* 4 blocks of ripple carry adder. The input carry is assumed to be zero. */

        fulladder FA00(c1, s[0], a[0], b[0], 1'b0);
        fulladder FA01(c2, s[1], a[1], b[1], c1);
        fulladder FA02(c3, s[2], a[2], b[2], c2);
        fulladder FA03(c4, s[3], a[3], b[3], c3);
		fulladder FA04(c5, s[4], a[4], b[4], c4);
		fulladder FA05(c6, s[5], a[5], b[5], c5);
		fulladder FA06(c7, s[6], a[6], b[6], c6);
		fulladder FA07(c8, s[7], a[7], b[7], c7);
		fulladder FA08(c9, s[8], a[8], b[8], c8);
		fulladder FA09(c10, s[9], a[9], b[9], c9);
		fulladder FA10(c11, s[10], a[10], b[10], c10);
		fulladder FA11(c12, s[11], a[11], b[11], c11);
		fulladder FA12(c13, s[12], a[12], b[12], c12);
		//fulladder FA13(c14, s[13], a[13], b[13], c13);
	//	fulladder FA14(c15, s[14], a[14], b[14], c14);
	//	fulladder FA15(c_out, s[15], a[15], b[15], c15);


/* Testbench to give the inputs and check the output values. The time */
/* variable, inputs and outputs are displayed. */

        initial begin                   /* Beginning of initial block */

/* The monitor statement monitors the value of variables at all instants */
/*  and displays the result whenever there is any change. */
$monitor ($time, "a=%b, b=%b, s=%b, cout=%b, c1=%b, c2=%b, c3=%b, c4=%b, c5=%b, c6=%b, c7=%b, c8=%b, c9=%b, c10=%b, c11=%b, c12=%b ", a, b, s, c_out, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12);
//                $monitor ($time, "a=%b, b=%b, s=%b, cout=%b, c1=%b, c2=%b, c3=%b, c4=%b, c5=%b, c6=%b, c7=%b, c8=%b, c9=%b, c10=%b, c11=%b, c12=%b, c13=%b, c14=%b, c15=%b ", a, b, s, c_out, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15);
                a=-10; b=100;               /* give specific input values */
                #100 $display ($time);  /* display the time variable */

                #900 a=63; b=127;
                #100 $display ($time);

                #900 a=15; b=95;
                #100 $display ($time);

                #900 a=-32; b=79;
                #100 $display ($time);

                #900 a=-59; b=-16;
                #100 $display ($time);
				
				#900 a=1000; b=2001;
				#100 $display ($time);
				
				#900 a=-3210; b=15;
				#100 $display ($time);

        end                                     /* end of the initial block */

endmodule                                       /* end of the adder module */



/* 1 Bit Full adder module */

module fulladder (cout, si, ai, bi, cin);

        parameter delay2=1, delay3=2, delay4=3;
                                        /* variables defined as parameter */

        input ai, bi, cin;                      /* declaring inputs */
        output cout, si;                        /* declaring outputs */

        and #delay3 (si1, ~ai, ~bi, cin),       /* si1=~ai.~bi.cin */
                    (si2, ~ai, bi, ~cin),       /* si2=~ai.bi.~cin */
                    (si3, ai, ~bi, ~cin),       /* si3=ai.~bi.~cin */
                    (si4, ai, bi, cin);         /* si4=ai.bi.cin */
        or #delay3 (si, si1, si2, si3, si4);    /* si=si1+si2+si3+si4 */

        and #delay2 (ci1, ai, bi),              /* ci1=ai.bi */
                    (ci2, ai, cin),             /* ci2=ai.cin */
                    (ci3, bi, cin);             /* ci3=bi.cin */
        or #delay3 (cout, ci1, ci2, ci3);       /* cout=ci1+ci2+ci3 */

endmodule

