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
   wire [1:0] s_op;
   wire [3:0] s_res;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_A[0]  = 1'b0;
   assign s_A[1]  = 1'b0;
   assign s_A[2]  = 1'b0;
   assign s_A[3]  = 1'b0;
   assign s_B[0]  = 1'b0;
   assign s_B[1]  = 1'b0;
   assign s_B[2]  = 1'b0;
   assign s_B[3]  = 1'b0;
   assign s_op[0] = 1'b0;
   assign s_op[1] = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   ALU   CIRCUIT_0 (.A(s_A),
                    .B(s_B),
                    .Cout(s_Cout),
                    .op(s_op),
                    .res(s_res));
endmodule
