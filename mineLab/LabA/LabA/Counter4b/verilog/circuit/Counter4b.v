/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : Counter4b                                                    **
 **                                                                          **
 *****************************************************************************/

module Counter4b( Qa,
                  Qb,
                  Qc,
                  Qd,
                  Rc,
                  clk );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input clk;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output Qa;
   output Qb;
   output Qc;
   output Qd;
   output Rc;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire s_logisimNet0;
   wire s_logisimNet1;
   wire s_logisimNet10;
   wire s_logisimNet11;
   wire s_logisimNet12;
   wire s_logisimNet13;
   wire s_logisimNet14;
   wire s_logisimNet15;
   wire s_logisimNet16;
   wire s_logisimNet17;
   wire s_logisimNet18;
   wire s_logisimNet2;
   wire s_logisimNet3;
   wire s_logisimNet4;
   wire s_logisimNet5;
   wire s_logisimNet6;
   wire s_logisimNet7;
   wire s_logisimNet8;
   wire s_logisimNet9;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimNet0 = clk;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign Qa = s_logisimNet15;
   assign Qb = s_logisimNet1;
   assign Qc = s_logisimNet2;
   assign Qd = s_logisimNet3;
   assign Rc = s_logisimNet18;

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // NOT Gate
   assign s_logisimNet11 = ~s_logisimNet7;

   // NOT Gate
   assign s_logisimNet12 = ~s_logisimNet9;

   // NOT Gate
   assign s_logisimNet13 = ~s_logisimNet8;

   // NOT Gate
   assign s_logisimNet14 = ~s_logisimNet5;

   /*******************************************************************************
   ** Here all normal components are defined                                     **
   *******************************************************************************/
   NOR_GATE_3_INPUTS #(.BubblesMask(3'b000))
      GATES_1 (.input1(s_logisimNet5),
               .input2(s_logisimNet4),
               .input3(s_logisimNet10),
               .result(s_logisimNet16));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_2 (.input1(s_logisimNet14),
               .input2(s_logisimNet10),
               .result(s_logisimNet7));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_3 (.input1(s_logisimNet16),
               .input2(s_logisimNet6),
               .result(s_logisimNet8));

   NOR_GATE_4_INPUTS #(.BubblesMask(4'h0))
      GATES_4 (.input1(s_logisimNet6),
               .input2(s_logisimNet4),
               .input3(s_logisimNet10),
               .input4(s_logisimNet5),
               .result(s_logisimNet18));

   NOR_GATE #(.BubblesMask(2'b00))
      GATES_5 (.input1(s_logisimNet5),
               .input2(s_logisimNet10),
               .result(s_logisimNet17));

   XOR_GATE_ONEHOT #(.BubblesMask(2'b00))
      GATES_6 (.input1(s_logisimNet17),
               .input2(s_logisimNet4),
               .result(s_logisimNet9));


   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   FD   m1 (.D(s_logisimNet11),
            .Q(s_logisimNet1),
            .Qn(s_logisimNet10),
            .clk(s_logisimNet0));

   FD   m2 (.D(s_logisimNet12),
            .Q(s_logisimNet2),
            .Qn(s_logisimNet4),
            .clk(s_logisimNet0));

   FD   m3 (.D(s_logisimNet13),
            .Q(s_logisimNet3),
            .Qn(s_logisimNet6),
            .clk(s_logisimNet0));

   FD   m0 (.D(s_logisimNet5),
            .Q(s_logisimNet15),
            .Qn(s_logisimNet5),
            .clk(s_logisimNet0));

endmodule
