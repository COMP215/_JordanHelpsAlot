C fort1.f
C234567
C     FORTRAN example
C     Start text here
      
      real lower, upper, domain, box_size, test
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

      end
            
      
      real function left_sum(lower, upper, n)
            real lower, upper, domain, box_size, left_sum, x_marker
            integer n, box_count
            
            domain = upper - lower
            box_size = domain / n
            box_count = 0
            left_sum = 0
            do while (box_count .lt. n)
              x_marker = lower + (box_count * box_size)
              left_sum = left_sum + func1(x_marker) * box_size
              box_count = box_count + 1
              print *, 'x_marker:', x_marker, ' | temp_sum:', left_sum
            end do
            
            return
            end
            
      real function right_sum(lower, upper, n)
            real lower, upper, domain, box_size, right_sum, x_marker
            integer n, box_count
            
            domain = upper - lower
            box_size = domain / n
            box_count = 0
            right_sum = 0
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
      real x, func1
      func1 = 10 / (x ** 2)
      return
      end
      
      real function func2(x)
      real x, func2
      func2 = x**2 - 6*x + 11
      return
      end


