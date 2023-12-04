/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : main                                                         **
 **                                                                          **
 *****************************************************************************/

module main( C,
             D,
             QCD,
             QCSR,
             QETD,
             QMSD,
             QMSSR,
             QSR,
             QbCD,
             QbCSR,
             QbETD,
             QbMSD,
             QbMSSR,
             QbSR,
             R,
             S,
             mQMSD );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input C;
   input D;
   input R;
   input S;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output QCD;
   output QCSR;
   output QETD;
   output QMSD;
   output QMSSR;
   output QSR;
   output QbCD;
   output QbCSR;
   output QbETD;
   output QbMSD;
   output QbMSSR;
   output QbSR;
   output mQMSD;

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
   assign s_logisimNet0 = D;
   assign s_logisimNet1 = C;
   assign s_logisimNet2 = S;
   assign s_logisimNet3 = R;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign QCD    = s_logisimNet9;
   assign QCSR   = s_logisimNet7;
   assign QETD   = s_logisimNet15;
   assign QMSD   = s_logisimNet12;
   assign QMSSR  = s_logisimNet14;
   assign QSR    = s_logisimNet5;
   assign QbCD   = s_logisimNet8;
   assign QbCSR  = s_logisimNet4;
   assign QbETD  = s_logisimNet16;
   assign QbMSD  = s_logisimNet11;
   assign QbMSSR = s_logisimNet13;
   assign QbSR   = s_logisimNet6;
   assign mQMSD  = s_logisimNet10;

   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   SR_latch   SR (.Q(s_logisimNet5),
                  .Qbar(s_logisimNet6),
                  .R(s_logisimNet3),
                  .S(s_logisimNet2));

   C_SR_latch   CSR (.C(s_logisimNet1),
                     .Q(s_logisimNet7),
                     .Qbar(s_logisimNet4),
                     .R(s_logisimNet3),
                     .S(s_logisimNet2));

   C_D_latch   CS (.C(s_logisimNet1),
                   .D(s_logisimNet0),
                   .Q(s_logisimNet9),
                   .Qbar(s_logisimNet8));

   MS_D_flip_flop   MSD (.D(s_logisimNet0),
                         .Q(s_logisimNet12),
                         .Qbar(s_logisimNet11),
                         .clk(s_logisimNet1),
                         .mid_Q(s_logisimNet10));

   MS_SR_flip_flop   MSSR (.D(s_logisimNet0),
                           .Q(s_logisimNet14),
                           .Qbar(s_logisimNet13),
                           .clk(s_logisimNet1));

   ET_D_flip_flop   ETD (.D(s_logisimNet0),
                         .Q(s_logisimNet15),
                         .Qbar(s_logisimNet16),
                         .clk(s_logisimNet1));

endmodule
