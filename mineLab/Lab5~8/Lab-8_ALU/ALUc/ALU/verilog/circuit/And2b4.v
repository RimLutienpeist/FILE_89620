/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : And2b4                                                       **
 **                                                                          **
 *****************************************************************************/

module And2b4( A,
               B,
               res );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input [3:0] A;
   input [3:0] B;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output [3:0] res;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire [3:0] s_logisimBus10;
   wire [3:0] s_logisimBus13;
   wire [3:0] s_logisimBus2;
   wire       s_logisimNet0;
   wire       s_logisimNet1;
   wire       s_logisimNet11;
   wire       s_logisimNet12;
   wire       s_logisimNet14;
   wire       s_logisimNet3;
   wire       s_logisimNet4;
   wire       s_logisimNet5;
   wire       s_logisimNet6;
   wire       s_logisimNet7;
   wire       s_logisimNet8;
   wire       s_logisimNet9;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimBus10[3:0] = A;
   assign s_logisimBus13[3:0] = B;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign res = s_logisimBus2[3:0];

   /*******************************************************************************
   ** Here all normal components are defined                                     **
   *******************************************************************************/
   AND_GATE #(.BubblesMask(2'b00))
      GATES_1 (.input1(s_logisimBus10[0]),
               .input2(s_logisimBus13[0]),
               .result(s_logisimBus2[0]));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_2 (.input1(s_logisimBus10[1]),
               .input2(s_logisimBus13[1]),
               .result(s_logisimBus2[1]));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_3 (.input1(s_logisimBus10[2]),
               .input2(s_logisimBus13[2]),
               .result(s_logisimBus2[2]));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_4 (.input1(s_logisimBus10[3]),
               .input2(s_logisimBus13[3]),
               .result(s_logisimBus2[3]));


endmodule
