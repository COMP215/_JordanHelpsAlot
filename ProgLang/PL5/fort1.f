C fort1.f
C234567
C     FORTRAN example
C     Start text here
      
      real lower, upper, domain, box_size
      integer func_choice, n
      
      print *, "Please enter lower bound:"
      read *, lower
      print *, "Please enter upper bound:"
      read *, upper
      print *, "Please enter function choice:"
      read *, func_choice
      !print *, "Please enter n:"
      !read *, n
      n = 10
      domain = upper - lower
      box_size = domain / n
      
      
      if (func_choice == 1) then
      	call func1(a,b)
      else
      	call func2(a,b)
      end if
      
      end
      
C ----------------------------
C     Subroutine to do something
      subroutine upper_sum1 (upper, lower)
      real upper, lower
      
      
      
      
      atF = -10 / f
      atG = -10 / g
      answer = atG - atF
      print *, 'Value: ', answer, ' between ', f, ' and ', g
      return
      end
C
C ----------------------------
C     Subroutine to do something
      subroutine func1 (f, g)
      real f, g
      real atF, atG, answer
      
      if (f==0) then
      	f = 0.001
      end if
      
      if (g==0) then
      	g = 0.001
      end if
      
      atF = -10 / f
      atG = -10 / g
      answer = atG - atF
      print *, 'Value: ', answer, ' between ', f, ' and ', g
      return
      end
C
C ----------------------------
C     Subroutine
      subroutine func2 (f, g)
      real f, g
      real atF, atG, answer
      atF = f*(f**2-9*f+33)/3
      atG = g*(g**2-9*g+33)/3
      answer = atG - atF
      print *, 'Value: ', answer, ' between ', f, ' and ', g
      return
      end
C
C ----------------------------

