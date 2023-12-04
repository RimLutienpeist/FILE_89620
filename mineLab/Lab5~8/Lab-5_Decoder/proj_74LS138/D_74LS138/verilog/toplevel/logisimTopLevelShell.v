/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : logisimTopLevelShell                                         **
 **                                                                          **
 *****************************************************************************/

module logisimTopLevelShell(  );

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire       s_A;
   wire       s_B;
   wire       s_C;
   wire       s_G;
   wire       s_G2A;
   wire       s_G2B;
   wire [7:0] s_Y;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_A   = 1'b0;
   assign s_B   = 1'b0;
   assign s_C   = 1'b0;
   assign s_G   = 1'b0;
   assign s_G2A = 1'b0;
   assign s_G2B = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   D_74LS138   CIRCUIT_0 (.A(s_A),
                          .B(s_B),
                          .C(s_C),
                          .G(s_G),
                          .G2A(s_G2A),
                          .G2B(s_G2B),
                          .Y(s_Y));
endmodule
