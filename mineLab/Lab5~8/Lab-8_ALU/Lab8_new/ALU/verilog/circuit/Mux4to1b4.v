/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : Mux4to1b4                                                    **
 **                                                                          **
 *****************************************************************************/

module Mux4to1b4( D0,
                  D1,
                  D2,
                  D3,
                  S,
                  Y );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input [3:0] D0;
   input [3:0] D1;
   input [3:0] D2;
   input [3:0] D3;
   input [1:0] S;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output [3:0] Y;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire [3:0] s_logisimBus0;
   wire [3:0] s_logisimBus1;
   wire [3:0] s_logisimBus10;
   wire [3:0] s_logisimBus14;
   wire [3:0] s_logisimBus15;
   wire [1:0] s_logisimBus17;
   wire [3:0] s_logisimBus2;
   wire [3:0] s_logisimBus3;
   wire [3:0] s_logisimBus6;
   wire [3:0] s_logisimBus9;
   wire       s_logisimNet11;
   wire       s_logisimNet12;
   wire       s_logisimNet13;
   wire       s_logisimNet16;
   wire       s_logisimNet4;
   wire       s_logisimNet5;
   wire       s_logisimNet7;
   wire       s_logisimNet8;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimBus0[3:0]  = D0;
   assign s_logisimBus10[3:0] = D1;
   assign s_logisimBus17[1:0] = S;
   assign s_logisimBus2[3:0]  = D3;
   assign s_logisimBus9[3:0]  = D2;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign Y = s_logisimBus6[3:0];

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // NOT Gate
   assign s_logisimNet8 = ~s_logisimBus17[0];

   // NOT Gate
   assign s_logisimNet5 = ~s_logisimBus17[1];

   /*******************************************************************************
   ** Here all normal components are defined                                     **
   *******************************************************************************/
   AND_GATE #(.BubblesMask(2'b00))
      GATES_1 (.input1(s_logisimNet8),
               .input2(s_logisimNet5),
               .result(s_logisimNet16));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_2 (.input1(s_logisimNet5),
               .input2(s_logisimBus17[0]),
               .result(s_logisimNet11));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_3 (.input1(s_logisimNet8),
               .input2(s_logisimBus17[1]),
               .result(s_logisimNet12));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_4 (.input1(s_logisimBus17[1]),
               .input2(s_logisimBus17[0]),
               .result(s_logisimNet13));

   OR_GATE_BUS_4_INPUTS #(.BubblesMask(4'h0),
                          .NrOfBits(4))
      GATES_5 (.input1(s_logisimBus1[3:0]),
               .input2(s_logisimBus15[3:0]),
               .input3(s_logisimBus3[3:0]),
               .input4(s_logisimBus14[3:0]),
               .result(s_logisimBus6[3:0]));


   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   And2b1b4   n0 (.A(s_logisimBus0[3:0]),
                  .S(s_logisimNet16),
                  .res(s_logisimBus1[3:0]));

   And2b1b4   n1 (.A(s_logisimBus10[3:0]),
                  .S(s_logisimNet11),
                  .res(s_logisimBus15[3:0]));

   And2b1b4   n2 (.A(s_logisimBus9[3:0]),
                  .S(s_logisimNet12),
                  .res(s_logisimBus3[3:0]));

   And2b1b4   n3 (.A(s_logisimBus2[3:0]),
                  .S(s_logisimNet13),
                  .res(s_logisimBus14[3:0]));

endmodule
