module top_module (
    input p1a, p1b, p1c, p1d, p1e ,p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );

    wire and2ab;
    wire and2cd;
    wire and1abc;
    wire and1def;

    assign and2ab = p2a&p2b;
    assign and2cd = p2c&p2d;
    assign and1abc = p1a&p1b&p1c;
    assign and1def = p1d&p1e&p1f;

    assign p2y = and2ab | and2cd;
    assign p1y = and1abc | and1def;

endmodule