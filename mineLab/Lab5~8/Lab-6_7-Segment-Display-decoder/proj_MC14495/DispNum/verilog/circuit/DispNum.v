/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : DispNum                                                      **
 **                                                                          **
 *****************************************************************************/

module DispNum( AN,
                BTN,
                BTN_X,
                SEGMENT,
                SW );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input [1:0] BTN;
   input [7:0] SW;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output [3:0] AN;
   output       BTN_X;
   output [7:0] SEGMENT;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire [1:0] s_logisimBus0;
   wire [7:0] s_logisimBus10;
   wire [7:0] s_logisimBus12;
   wire [3:0] s_logisimBus7;
   wire       s_logisimNet1;
   wire       s_logisimNet11;
   wire       s_logisimNet13;
   wire       s_logisimNet14;
   wire       s_logisimNet15;
   wire       s_logisimNet16;
   wire       s_logisimNet17;
   wire       s_logisimNet18;
   wire       s_logisimNet19;
   wire       s_logisimNet2;
   wire       s_logisimNet20;
   wire       s_logisimNet21;
   wire       s_logisimNet22;
   wire       s_logisimNet23;
   wire       s_logisimNet24;
   wire       s_logisimNet25;
   wire       s_logisimNet26;
   wire       s_logisimNet3;
   wire       s_logisimNet4;
   wire       s_logisimNet5;
   wire       s_logisimNet6;
   wire       s_logisimNet8;
   wire       s_logisimNet9;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimBus0[1:0]  = BTN;
   assign s_logisimBus12[7:0] = SW;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign AN      = s_logisimBus7[3:0];
   assign BTN_X   = s_logisimNet2;
   assign SEGMENT = s_logisimBus10[7:0];

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // Ground
   assign  s_logisimNet2  =  1'b0;


   // NOT Gate
   assign s_logisimBus7[0] = ~s_logisimBus12[4];

   // NOT Gate
   assign s_logisimBus7[1] = ~s_logisimBus12[5];

   // NOT Gate
   assign s_logisimBus7[2] = ~s_logisimBus12[6];

   // NOT Gate
   assign s_logisimBus7[3] = ~s_logisimBus12[7];

   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   MyMC14495   m0 (.D0(s_logisimBus12[3]),
                   .D1(s_logisimBus12[2]),
                   .D2(s_logisimBus12[1]),
                   .D3(s_logisimBus12[0]),
                   .LE(s_logisimBus0[0]),
                   .a(s_logisimBus10[0]),
                   .b(s_logisimBus10[1]),
                   .c(s_logisimBus10[2]),
                   .d(s_logisimBus10[3]),
                   .e(s_logisimBus10[4]),
                   .f(s_logisimBus10[5]),
                   .g(s_logisimBus10[6]),
                   .p(s_logisimBus10[7]),
                   .point(s_logisimBus0[1]));

endmodule
