C fort3.f
C234567
C     Show use of subroutine and function
C     Find x^n
C
      integer x
      integer n
C
      print *, "Enter x, n:"
      read *, x, n
      print *, x, n
C
C     Call subroutine to find and display x^n
      call power1 (x, n)
C
C     Call function to return x^n
      print *, 'In main: ', power2 (x, n)
      end
C
C ----------------------------
C     Subroutine to find f^g
      subroutine power1 (f, g)
      integer f, g
      answer = f ** g
      print *, 'In subroutine: ', answer
      return
      end
C
C ----------------------------
C     Function to return f^g
      real function power2 (f, g)
      integer f, g
      power2 = f ** g
      return
      end
