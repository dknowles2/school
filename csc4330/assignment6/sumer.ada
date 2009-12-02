with Ada.Text_IO;
with Ada.Float_Text_IO;

procedure Main is
   type Mat_Type is array (Integer range <>, Integer range <>) of Float;
   Mat_1 : Mat_Type(1..2, 1..3) := ((1.0, 1.0, 1.0), (1.0, 1.0, 2.0));

   function Sumer(Mat : in Mat_Type) return Float is
      Sum: Float := 0.0;
   begin
      for Row in Mat'Range(1) loop
         for Col in Mat'Range(2) loop
            Sum := Sum + Mat(Row, Col);
         end loop; -- for Col ...
      end loop; -- for Row ...
      return Sum;
   end Sumer;
begin
   Ada.Float_Text_IO.Put(Sumer(Mat_1));
end Main;
