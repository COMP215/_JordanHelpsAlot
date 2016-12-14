C HamHouse.f
C
C   -Jordan Hamilton
C   -Steven Waterhouse
!---------------------------------------------------------------------
C     PROGRAM MAIN()
!---------------------------------------------------------------------
      real upper, left_sum, right_sum
      real lower
      integer func_choice
      real right
      real left
      real newN
      real sumDiff
      real errorM
      integer n
      real domain
      
      n=1
      sumDiff=0

      !Take user input
      print *, "Please enter function choice (1 or 2):"
      read *, func_choice
      if((func_choice/=1) .and. (func_choice/=2)) then
      goto 100
      endif
      print *, "Please enter the error marigin:"
      read  *, errorM
      print *, "Please enter lower bound:"
      read *, lower
      print *, "Please enter upper bound:"
      read *, upper
      
      domain=upper-lower
      left=left_sum(lower, upper, n, domain, func_choice)
      right=right_sum(lower, upper, n, domain, func_choice)
      sumDiff=right-left
      sumDiff=abs(sumDiff)
      n=n+1
      
      !This loop does the work of evaluating sumDiff for different values of n
      do while (sumDiff .gt. errorM) 
        n=n+1
        right=right_sum(lower, upper, n, domain,func_choice)
        left=left_sum(lower, upper, n, domain, func_choice)
        sumDiff=right-left
        sumDiff=abs(sumDiff)
        if(n==5000) then
          goto 100
        endif
      enddo
      
      !Warn user if program drew more than 5000 Riemann boxes
100   if (n==5000) then
        print *, "number of rectangles exceeds 5000"
      endif
      
      newN = n
      
      !Variable print formatting based on value sizes
      if (middle .lt. 99999) then
        write (*,600) "LOWER SUM:", left
        write (*,600) "UPPER SUM:", right
        write (*,600) "RIEMANN BOXES(N):", newN
      else
        write (*,800) "LOWER SUM:", left
        write (*,800) "UPPER SUM:", right
        write (*,800) "RIEMANN BOXES(N):", newN
      endif
      
      !Print format codes
600   Format(A20,F11.5)

800   Format(A20,F20.5)

      
      end
      
C     END OF MAIN()

!---------------------------------------------------------------------

!---------------------------------------------------------------------
C     Function: left_sum()
C       Description: Calculates the lower sum of the area beneath the
C         curve in the given function, according to the given n
C       PRE: lower, upper, domain, n, and func_choice have been set
C       POST: NA
!---------------------------------------------------------------------
      real function left_sum(lower, upper, n, domain, func_choice)
        real upper, lower, domain, box_size, x_marker, temp_lower
        integer n, box_count, func_choice
        box_size = domain / n
        box_count = 0
        temp_lower = lower
        temp_lower = temp_lower + box_size
        temp_left_sum = 0.0
        do while (box_count .lt. n)
          x_marker = lower + (box_count * box_size)
          if(func_choice==1) then
          temp_left_sum = temp_left_sum + func1(x_marker) * box_size
          else
          temp_left_sum = temp_left_sum + func2(x_marker) * box_size
          endif
          box_count = box_count + 1
        enddo
            left_sum=temp_left_sum
            return
            end

C     END OF left_sum()

!---------------------------------------------------------------------
            
!---------------------------------------------------------------------
C     Function: right_sum()
C       Description: Calculates the upper sum of the area beneath the
C         curve in the given function, according to the given n
C       PRE: lower, upper, domain, n, and func_choice have been set
C       POST: NA
!---------------------------------------------------------------------
      real function right_sum(lower, upper, n, domain, func_choice)
          real upper, lower, domain, box_size, x_marker, temp_lower
          integer n, box_count, func_choice
          box_size = domain / n
          box_count = 0
          temp_lower = lower
          temp_lower = temp_lower + box_size
          temp_right_sum = 0.0
          do while (box_count .lt. n)
            x_marker = temp_lower + (box_count * box_size)
            if(func_choice==1) then

            temp_right_sum = temp_right_sum + func1(x_marker) * box_size
            else
            temp_right_sum = temp_right_sum + func2(x_marker) * box_size
            endif
            box_count = box_count + 1
          enddo
              right_sum = temp_right_sum
              return
              end
              
C     END OF right_sum()

!---------------------------------------------------------------------
      
!---------------------------------------------------------------------
C     Function: func1()
C       Description: Returns y-value of f(x)=10/x^2 at given x value
!---------------------------------------------------------------------
      real function func1(x)
      real x
      if (x==0) then !Catches evaluation of zero for x
        x = 0.0001
        print *, "Solutions approximated, values undefined (0 division)"
      endif
      func1 = 10.0 / (x ** 2)
      return
      end
      
!---------------------------------------------------------------------
C     Function: func2()
C       Description: Returns y-value of f(x)=x^2-6x+11 at given x value
!---------------------------------------------------------------------
      real function func2(x)
      real x
      func2 = x**2 - 6*x + 11
      return
      end

