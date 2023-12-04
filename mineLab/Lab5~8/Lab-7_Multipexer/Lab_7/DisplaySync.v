

module DisplaySync(
    input [ 1:0] scan,
    input [15:0] hexs,
    input [ 3:0] points,
    input [ 3:0] LEs,
    output[ 3:0] HEX,
    output[ 3:0] AN,
    output       point,
    output       LE
);

wire [1:0] Sa;
wire [3:0] D0a;
wire [3:0] D1a;
wire [3:0] D2a;
wire [3:0] D3a;
wire [3:0] Ya;

Mux4to1b4 mux_hexs (
.S(Sa),
.D0(D0a),
.D1(D1a),
.D2(D2a),
.D3(D3a),
.Y(Ya)
);


wire [1:0] Sb;
wire D0b;
wire D1b;
wire D2b;
wire D3b;
wire Yb;

Mux4to1 mux_points (
.S(Sb),
.D0(D0b),
.D1(D1b),
.D2(D2b),
.D3(D3b),
.Y(Yb)
);

wire [1:0] Sc;
wire D0c;
wire D1c;
wire D2c;
wire D3c;
wire Yc;

Mux4to1 mux_LE (
.S(Sc),
.D0(D0c),
.D1(D1c),
.D2(D2c),
.D3(D3c),
.Y(Yc)
);

wire [1:0] Sd;
wire D0d;
wire D1d;
wire D2d;
wire D3d;
wire [3:0] Yd;

Mux4to1b4 mux_AN (
.S(Sd),
.D0(D0d),
.D1(D1d),
.D2(D2d),
.D3(D3d),
.Y(Yd)
);

assign Sa = scan;
assign Sb = scan;
assign Sc = scan;
assign Sd = scan;

assign D0a = hexs[3:0];
assign D1a = hexs[7:4];
assign D2a = hexs[11:8];
assign D3a = hexs[15:12];

assign D0b = points[0];
assign D1b = points[1];
assign D2b = points[2];
assign D3b = points[3];

assign D0c = LEs[0];
assign D1c = LEs[1];
assign D2c = LEs[2];
assign D3c = LEs[3];

assign D0d = 4'b1110;
assign D1d = 4'b1101;
assign D2d = 4'b1011;
assign D3d = 4'b0111;

assign HEX = Ya;
assign point = Yb;
assign LE = Yc;
assign AN = Yd;

endmodule