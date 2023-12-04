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
   wire s_C;
   wire s_D;
   wire s_QCD;
   wire s_QCSR;
   wire s_QETD;
   wire s_QMSD;
   wire s_QMSSR;
   wire s_QSR;
   wire s_QbCD;
   wire s_QbCSR;
   wire s_QbETD;
   wire s_QbMSD;
   wire s_QbMSSR;
   wire s_QbSR;
   wire s_R;
   wire s_S;
   wire s_mQMSD;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_C = 1'b0;
   assign s_D = 1'b0;
   assign s_R = 1'b0;
   assign s_S = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   main   CIRCUIT_0 (.C(s_C),
                     .D(s_D),
                     .QCD(s_QCD),
                     .QCSR(s_QCSR),
                     .QETD(s_QETD),
                     .QMSD(s_QMSD),
                     .QMSSR(s_QMSSR),
                     .QSR(s_QSR),
                     .QbCD(s_QbCD),
                     .QbCSR(s_QbCSR),
                     .QbETD(s_QbETD),
                     .QbMSD(s_QbMSD),
                     .QbMSSR(s_QbMSSR),
                     .QbSR(s_QbSR),
                     .R(s_R),
                     .S(s_S),
                     .mQMSD(s_mQMSD));
endmodule
