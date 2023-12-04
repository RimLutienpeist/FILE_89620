/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : recu_lab4                                                    **
 **                                                                          **
 *****************************************************************************/

module recu_lab4( I0,
                  I1,
                  I2,
                  res );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input I0;
   input I1;
   input I2;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output res;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire [7:0] s_logisimBus10;
   wire       s_logisimNet0;
   wire       s_logisimNet1;
   wire       s_logisimNet2;
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
   assign s_logisimNet4 = I0;
   assign s_logisimNet5 = I1;
   assign s_logisimNet6 = I2;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign res = s_logisimNet2;

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // Power
   assign  s_logisimNet3  =  1'b1;


   // Ground
   assign  s_logisimNet8  =  1'b0;


   /*******************************************************************************
   ** Here all normal components are defined                                     **
   *******************************************************************************/
   NAND_GATE_4_INPUTS #(.BubblesMask(4'h0))
      GATES_1 (.input1(s_logisimBus10[3]),
               .input2(s_logisimBus10[5]),
               .input3(s_logisimBus10[6]),
               .input4(s_logisimBus10[7]),
               .result(s_logisimNet2));


   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   D_74LS138   m0 (.A(s_logisimNet4),
                   .B(s_logisimNet5),
                   .C(s_logisimNet6),
                   .G(s_logisimNet3),
                   .G2A(s_logisimNet8),
                   .G2B(s_logisimNet8),
                   .Y(s_logisimBus10[7:0]));

endmodule
