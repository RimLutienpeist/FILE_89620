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
   wire s_Qa;
   wire s_Qb;
   wire s_Qc;
   wire s_Qd;
   wire s_Rc;
   wire s_clk;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_clk = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   Counter4b   CIRCUIT_0 (.Qa(s_Qa),
                          .Qb(s_Qb),
                          .Qc(s_Qc),
                          .Qd(s_Qd),
                          .Rc(s_Rc),
                          .clk(s_clk));
endmodule
