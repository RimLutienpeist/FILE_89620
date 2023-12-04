module Mux4to1b4(
    input  [1:0] S,
    input  [3:0] D0,
    input  [3:0] D1,
    input  [3:0] D2,
    input  [3:0] D3,
    output reg [3:0] Y
);

always@(*)
begin
    case(S)
        2'b00:begin
            Y = D0;
        end
        2'b01:begin
            Y = D1;
        end
        2'b10:begin
            Y = D2;
        end
        2'b11:begin
            Y = D3;
        end
    endcase
end

endmodule



