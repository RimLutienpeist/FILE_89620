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
   wire [3:0] s_A;
   wire [3:0] s_B;
   wire       s_Cout;
   wire       s_Ctrl;
   wire [3:0] s_S;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_A[0] = 1'b0;
   assign s_A[1] = 1'b0;
   assign s_A[2] = 1'b0;
   assign s_A[3] = 1'b0;
   assign s_B[0] = 1'b0;
   assign s_B[1] = 1'b0;
   assign s_B[2] = 1'b0;
   assign s_B[3] = 1'b0;
   assign s_Ctrl = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   AddSub4b   CIRCUIT_0 (.A(s_A),
                         .B(s_B),
                         .Cout(s_Cout),
                         .Ctrl(s_Ctrl),
                         .S(s_S));
endmodule
