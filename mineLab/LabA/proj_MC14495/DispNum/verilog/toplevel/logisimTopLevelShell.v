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
   wire [3:0] s_AN;
   wire [1:0] s_BTN;
   wire       s_BTN_X;
   wire [7:0] s_SEGMENT;
   wire [7:0] s_SW;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_BTN[0] = 1'b0;
   assign s_BTN[1] = 1'b0;
   assign s_SW[0]  = 1'b0;
   assign s_SW[1]  = 1'b0;
   assign s_SW[2]  = 1'b0;
   assign s_SW[3]  = 1'b0;
   assign s_SW[4]  = 1'b0;
   assign s_SW[5]  = 1'b0;
   assign s_SW[6]  = 1'b0;
   assign s_SW[7]  = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   DispNum   CIRCUIT_0 (.AN(s_AN),
                        .BTN(s_BTN),
                        .BTN_X(s_BTN_X),
                        .SEGMENT(s_SEGMENT),
                        .SW(s_SW));
endmodule
