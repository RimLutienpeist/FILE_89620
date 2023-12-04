/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : AddSub4b                                                     **
 **                                                                          **
 *****************************************************************************/

module AddSub4b( A,
                 B,
                 Cout,
                 Ctrl,
                 S );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input [3:0] A;
   input [3:0] B;
   input       Ctrl;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output       Cout;
   output [3:0] S;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire [3:0] s_logisimBus18;
   wire [3:0] s_logisimBus19;
   wire [3:0] s_logisimBus22;
   wire       s_logisimNet0;
   wire       s_logisimNet1;
   wire       s_logisimNet10;
   wire       s_logisimNet11;
   wire       s_logisimNet12;
   wire       s_logisimNet13;
   wire       s_logisimNet14;
   wire       s_logisimNet15;
   wire       s_logisimNet16;
   wire       s_logisimNet17;
   wire       s_logisimNet2;
   wire       s_logisimNet20;
   wire       s_logisimNet21;
   wire       s_logisimNet23;
   wire       s_logisimNet24;
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
   assign s_logisimBus18[3:0] = B;
   assign s_logisimBus22[3:0] = A;
   assign s_logisimNet4       = Ctrl;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign Cout = s_logisimNet17;
   assign S    = s_logisimBus19[3:0];

   /*******************************************************************************
   ** Here all normal components are defined                                     **
   *******************************************************************************/
   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_1 (.input1(s_logisimBus18[2]),
               .input2(s_logisimNet4),
               .result(s_logisimNet13));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_2 (.input1(s_logisimBus18[3]),
               .input2(s_logisimNet4),
               .result(s_logisimNet14));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_3 (.input1(s_logisimBus18[0]),
               .input2(s_logisimNet4),
               .result(s_logisimNet24));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_4 (.input1(s_logisimBus18[1]),
               .input2(s_logisimNet4),
               .result(s_logisimNet15));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_5 (.input1(s_logisimNet23),
               .input2(s_logisimNet4),
               .result(s_logisimNet17));


   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   Adder1b   a2 (.A(s_logisimBus22[2]),
                 .B(s_logisimNet13),
                 .Cin(s_logisimNet0),
                 .Cout(s_logisimNet8),
                 .S(s_logisimBus19[2]));

   Adder1b   a3 (.A(s_logisimBus22[3]),
                 .B(s_logisimNet14),
                 .Cin(s_logisimNet8),
                 .Cout(s_logisimNet23),
                 .S(s_logisimBus19[3]));

   Adder1b   a1 (.A(s_logisimBus22[1]),
                 .B(s_logisimNet15),
                 .Cin(s_logisimNet1),
                 .Cout(s_logisimNet0),
                 .S(s_logisimBus19[1]));

   Adder1b   a0 (.A(s_logisimBus22[0]),
                 .B(s_logisimNet24),
                 .Cin(s_logisimNet4),
                 .Cout(s_logisimNet1),
                 .S(s_logisimBus19[0]));

endmodule
