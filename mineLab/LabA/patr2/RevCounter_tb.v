`timescale 1ns / 1ps

module labA_tb;

  reg clk,rst,s;
  wire [15:0] cnt = 0;
  wire Rc;
  reg [31:0] i;

RevCounter utt( 
clk,
rst,
s,
cnt,
Rc
);

  initial begin
        clk=1;
        for(i=0;i<16'hFFFFF;i=i+1) begin
             clk = ~clk;#1;
        end
    $finish;
  end

endmodule