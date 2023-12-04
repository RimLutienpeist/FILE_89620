/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : And2b1b4                                                     **
 **                                                                          **
 *****************************************************************************/

module And2b1b4( A,
                 S,
                 res );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input [3:0] A;
   input       S;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output [3:0] res;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire [3:0] s_logisimBus2;
   wire [3:0] s_logisimBus9;
   wire       s_logisimNet0;
   wire       s_logisimNet1;
   wire       s_logisimNet10;
   wire       s_logisimNet3;
   wire       s_logisimNet4;
   wire       s_logisimNet5;
   wire       s_logisimNet6;
   wire       s_logisimNet7;
   wire       s_logisimNet8;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimBus9[3:0] = A;
   assign s_logisimNet3      = S;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign res = s_logisimBus2[3:0];

   /*******************************************************************************
   ** Here all normal components are defined                                     **
   *******************************************************************************/
   AND_GATE #(.BubblesMask(2'b00))
      GATES_1 (.input1(s_logisimNet3),
               .input2(s_logisimBus9[0]),
               .result(s_logisimBus2[0]));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_2 (.input1(s_logisimNet3),
               .input2(s_logisimBus9[1]),
               .result(s_logisimBus2[1]));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_3 (.input1(s_logisimNet3),
               .input2(s_logisimBus9[2]),
               .result(s_logisimBus2[2]));

   AND_GATE #(.BubblesMask(2'b00))
      GATES_4 (.input1(s_logisimNet3),
               .input2(s_logisimBus9[3]),
               .result(s_logisimBus2[3]));


endmodule
