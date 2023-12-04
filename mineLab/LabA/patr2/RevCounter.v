/** module RevCounter
  * input
  *   clk: A clock signal driven by module clk_1s.
  *   rst: Synchronous reset signal
  *   s: 1 for decrement, 0 for increment
  * output
  *   cnt: a 16-bits register
  *   Rc: rise when the counter reset(i.e. carry will be set), that is, Rc becomes 1 when
  *           increment(s=1 & cnt=F) or decrement(s=0, cnt=0)
 */

//! NOTE: DO NOT CHANGE THE MODULE NAME & PORT NAMES
module RevCounter( 
  input wire clk,
  input wire rst,
  input wire s,
  output reg [15:0] cnt=0,
  output wire Rc
);
    /* Your code here */
  always @(posedge clk) begin
    if (rst) begin
      cnt <= 16'h0;
    end else if (!s) begin
      if (cnt == 16'h0) begin
        cnt <= 16'hFFFF;
      end else begin
        cnt <= cnt - 1;
      end
    end else begin
      if (cnt == 16'hFFFF) begin
        cnt <= 16'h0;
      end else begin
        cnt <= cnt + 1;
      end
    end
  end

  assign Rc = (s & (cnt == 16'hFFFF)) | (!s & (cnt == 16'h0));

endmodule