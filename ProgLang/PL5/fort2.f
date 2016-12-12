C fort2.f
C234567
C     Declarations come before data (constants)
C     Declare an integer; if not declared, radius would be a real by default
      integer radius
C
C     Make a constant
      data pi/3.141592654/
C
  500 print *, "Enter radius:"
      read (5, 100) radius
  100 format (I5)
      area = pi * radius ** 2
  200 format ("Area of a circle with radius", I4, " is: ", F10.2)
      write (6, 200) radius, area
C
C     See if user wants to try again
      print *, "Type in '1' if you wish to go again: "
      read (5, 100) input
      if (input .eq. 1) then
         goto 500
      else
         print *, "Done!"
      endif
      end
