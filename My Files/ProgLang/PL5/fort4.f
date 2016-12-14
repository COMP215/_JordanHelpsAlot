C fort4.f
C Determine if an array of integers is a "palindrome"
C234567
      common /GLOBAL/ MAX
      integer array (5)
      MAX = 5 

      print *,"Enter values:"
 100  format (I5)
      do 50 i = 1, MAX, 1
         read (5, 100) array(i)
   50 continue
C
C     Print out the array
      do 51 i = 1, MAX, 1
         write (6, 100) array(i)
   51 continue
C
C     Call subroutine to determine if palindrome
      call palin (array, MAX)
      end
C
C -------------------------------------------------------
C
C     Palindrome subroutine
      subroutine palin (stuff, MAX)
      integer stuff(MAX)
C
      real middle
      integer imiddle
      integer right
C
      middle = MAX / 2.0
      imiddle = MAX / 2
      if (middle .gt. imiddle) then
         imiddle = imiddle + 1
      endif

      right = MAX
      do 50 i = 1, imiddle, 1
         if (stuff(i) .ne. stuff(right)) then
            print *, "Not a palindrome"
            return
         else
            right = right - 1
         endif
  50  continue
      print *, "PALINDROME"
      return
      end
