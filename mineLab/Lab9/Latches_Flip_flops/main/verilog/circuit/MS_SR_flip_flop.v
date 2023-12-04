/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : MS_SR_flip_flop                                              **
 **                                                                          **
 *****************************************************************************/

module MS_SR_flip_flop( D,
                        Q,
                        Qbar,
                        clk );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input D;
   input clk;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output Q;
   output Qbar;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire s_logisimNet0;
   wire s_logisimNet1;
   wire s_logisimNet2;
   wire s_logisimNet3;
   wire s_logisimNet4;
   wire s_logisimNet5;
   wire s_logisimNet6;
   wire s_logisimNet7;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimNet2 = D;
   assign s_logisimNet3 = clk;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign Q    = s_logisimNet7;
   assign Qbar = s_logisimNet6;

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // NOT Gate
   assign s_logisimNet0 = ~s_logisimNet3;

   // NOT Gate
   assign s_logisimNet1 = ~s_logisimNet2;

   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   C_SR_latch   CSRll (.C(s_logisimNet0),
                       .Q(s_logisimNet5),
                       .Qbar(s_logisimNet4),
                       .R(s_logisimNet2),
                       .S(s_logisimNet1));

   C_SR_latch   CSRlll (.C(s_logisimNet3),
                        .Q(s_logisimNet7),
                        .Qbar(s_logisimNet6),
                        .R(s_logisimNet4),
                        .S(s_logisimNet5));

endmodule
