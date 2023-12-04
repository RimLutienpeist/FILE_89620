`timescale 1ns / 1ps

module ALUsimu;
  reg  [3:0] A, B;
  reg  [1:0] op;
  wire Cout;
  wire [3:0] res;// 0 when AND & OR
/////// op: 0 for ADD; 1 for SUB; 2 for AND; 3 for OR ///////
  ALU aulF (
    .A(A),
    .B(B),
    .op(op),
    .res(res),
    .Cout(Cout)
  );

  initial begin
    op=2'b00; A=4'b0110; B=4'b0100; #5;
    op=2'b00; A=4'b1010; B=4'b0010; #5;
    op=2'b00; A=4'b0000; B=4'b0000; #5;
    op=2'b01; A=4'b1000; B=4'b0100; #5;
    op=2'b01; A=4'b0100; B=4'b0001; #5;
    op=2'b01; A=4'b0100; B=4'b0011; #5;
    op=2'b01; A=4'b0100; B=4'b0010; #5;   
    op=2'b01; A=4'b0000; B=4'b0000; #5;
    op=2'b01; A=4'b0111; B=4'b0011; #5;
    op=2'b01; A=4'b0011; B=4'b0010; #5;
    op=2'b10; A=4'b0110; B=4'b0100; #5;
    op=2'b10; A=4'b0110; B=4'b0000; #5;
    op=2'b10; A=4'b0000; B=4'b0000; #5;
    op=2'b11; A=4'b0110; B=4'b0100; #5;
    op=2'b11; A=4'b0110; B=4'b0000; #5;
    op=2'b11; A=4'b0000; B=4'b0000; #5;
     $finish;
  end

endmodule