with Ada.Text_IO;
use Ada.Text_IO;

procedure Hello_Loop Is
   N : Integer;
begin
   N := 10;
   for I in reverse 1..N loop
      Put_Line(Integer'Image(I));
      N := N - 1;
   end loop;
end;
