C fort1.f
C234567
C     FORTRAN example
C     Start text here
      real upper, left_sum, right_sum
      real lower
      integer func_choice
      real right
      real left
      real sumDiff
      real errorM
      integer n
      
      n=1
      errorM=5
      sumDiff=0
      print *, n
      print *, "Please enter lower bound:"
      read *, lower
      print *, "Please enter upper bound:"
      read *, upper
      print *, "Please enter function choice:"
      read *, func_choice
C      print *, "Please enter the error marigin:"
C      read  *, sumDiff
       print *, errorM, sumDiff, lower, upper
       left=left_sum(lower, upper, n)
       right=right_sum(lower, upper, n)
       
       sumDiff=right-left
C       sumDiff= right_sum(lower, upper, n) - left_sum(lower, upper, n)
       sumDiff=abs(sumDiff)
       n=n+1
       print *, "hdjhfskjhvfjvsdhvfhdsv", sumDiff
      do while (sumDiff .gt. errorM) 
C        right=right_sum
C	left=left_sum
        right=right_sum(lower, upper, n)
	left=left_sum(lower, upper, n)
        sumDiff=right-left
C	sumDiff= right_sum(lower, upper, n) - left_sum(lower, upper, n)
        sumDiff=abs(sumDiff)
	n=n+1
        print *, sumDiff, errorM
        if(n==5000) then
	  goto 100
        endif
	
      enddo
100   if (n==5000) then
	print *, "N too big"
      endif
      print *, n, right, left
	      
      end

      real function left_sum(lower, upper, n)
            real domain, box_size, x_marker
	        real lower
            real upper
            integer n, box_count
            print *, "lower", lower
            print *, "upper", upper
            print *, "n", n
            domain = upper - lower
            box_size = domain / n
            box_count = 0
            left_sum = 0.0
            do while (box_count .lt. n)
              x_marker = lower + (box_count * box_size)
              left_sum = left_sum + func1(x_marker) * box_size
              box_count = box_count + 1
              print *, 'x_marker:', x_marker, ' | temp_sum:', left_sum
            end do
            
            return
            end
            
      real function right_sum(lower, upper, n)
            real lower, upper, domain, box_size, x_marker
            integer n, box_count
            
            domain = upper - lower
            box_size = domain / n
            box_count = 0
            right_sum = 0.0
            lower = lower + box_size
            do while (box_count .lt. n)
              x_marker = lower + (box_count * box_size)
              right_sum = right_sum + func1(x_marker) * box_size
              box_count = box_count + 1
              print *, 'x_marker:', x_marker, ' | temp_sum:', right_sum
            end do
            
            return
            end
      
      real function func1(x)
      real x
      func1 = 10.0 / (x ** 2)
      return
      end
      
      real function func2(x)
      real x
      func2 = x**2 - 6*x + 11
      return
      end

