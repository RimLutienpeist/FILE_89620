`timescale 1ns / 1ps

module lab9_tb;

  reg C,R,D,S;
  wire QSR,QbSR,QbCSR,QCSR,QbCD,QCD,mQMSD,QbMSD,QMSD,
       QbMSSR,QMSSR,QETD,QbETD;

  main uut ( C,
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
             mQMSD
  );

  initial begin
    C=0; R=0; S=0; D=0; #5;
    C=0; R=0; S=0; D=1; #5;
    C=0; R=0; S=1; D=0; #5;
    C=0; R=0; S=1; D=1; #5;
    C=0; R=1; S=0; D=0; #5;
    C=0; R=1; S=0; D=1; #5;
//    C=0; R=1; S=1; D=0; #5;
//    C=0; R=1; S=1; D=1; #5;
    C=1; R=0; S=0; D=0; #5;
    C=1; R=0; S=0; D=1; #5;
    C=1; R=0; S=1; D=0; #5;
    C=1; R=0; S=1; D=1; #5;
    C=1; R=1; S=0; D=0; #5;
    C=1; R=1; S=0; D=1; #5;
//    C=1; R=1; S=1; D=0; #5;
//    C=1; R=1; S=1; D=1; #5;
    $finish;
  end

endmodule