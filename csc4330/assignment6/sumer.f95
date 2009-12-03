! Author: dknowles2@gmail.com (David Knowles)

function Sumer(Mat, Rows, Cols) result(Sum)
  implicit none
  integer, intent(in) :: Rows, Cols
  real :: Mat(Rows, Cols)
  real :: Sum

  integer Row, Col
  Sum = 0.0
  do Row = 1, Rows
     do Col = 1, Cols
        Sum = Sum + Mat(Row, Col)
     end do
  end do

end function Sumer

program Main
  real Mat_1(2, 3)
  Mat_1 = reshape( (/ 1.0, 1.0, 1.0, 1.0, 1.0, 2.0 /), (/ 2, 3 /) )

  print *, Sumer(Mat_1, 2, 3)
end program Main
