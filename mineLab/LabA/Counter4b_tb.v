`timescale 1ns / 1ps

module labA_tb;

  reg clk;
  wire Qa,Qb,Qc,Qd,Rc;
  reg [6:0] i;

  Counter4b uut ( Qa,
                  Qb,
                  Qc,
                  Qd,
                  Rc,
                  clk
  );

  initial begin
clk=1;
        for(i=0;i<32;i=i+1) begin
             clk = ~clk;#5;
        end

    $finish;
  end

endmodule