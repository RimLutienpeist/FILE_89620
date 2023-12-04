module DisplayNumber(
    input        clk,
    input        rst,
    input [15:0] hexs,
    input [ 3:0] points,
    input [ 3:0] LEs,
    output[ 3:0] AN,
    output[ 7:0] SEGMENT
);


wire [31:0] div_resout;
wire [1:0] div_scan;
wire pointW;
wire LEW;
wire [3:0] HEXW;

clkdiv clkdiv_1 (
    .clk(clk),
    .rst(rst),
    .div_res(div_resout)
);

DisplaySync DisplaySync_1(
    .scan(div_scan),
    .hexs(hexs),
    .points(points),
    .LEs(LEs),
    .HEX(HEXW),
    .point(pointW),
    .LE(LEW),
    .AN(AN)
);

assign div_scan = div_resout[18:17];

wire a;
wire b;
wire c;
wire d;
wire e;
wire f;
wire g;
wire p;
wire D0W;
wire D1W;
wire D2W;
wire D3W;
wire pointM;
wire LEM;

MyMC14495 MyMC14495_1(
    .D0(D0W),
    .D1(D1W),
    .D2(D2W),
    .D3(D3W),
    .point(pointM),
    .LE(LEM),
    .a(a),
    .b(b),
    .c(c),
    .d(d),
    .e(e),
    .f(f),
    .g(g),
    .p(p)
);

assign LEM = LEW;
assign pointM = pointW;
assign D0W = HEXW[0];
assign D1W = HEXW[1];
assign D2W = HEXW[2];
assign D3W = HEXW[3];
assign SEGMENT[0] = a ;
assign SEGMENT[1] = b ;
assign SEGMENT[2] = c ;
assign SEGMENT[3] = d ;
assign SEGMENT[4] = e ;
assign SEGMENT[5] = f ;
assign SEGMENT[6] = g ;
assign SEGMENT[7] = p ;

endmodule