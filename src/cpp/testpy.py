# my first q by py !!!
def check( test, k  ) : 
    return nums[test] > k 
n, m = map(int, input().split() ) 
nums = [] 
for i in range (n) : 
    temp = int( input().split() )
    nums.append( temp )
# nums.extend(list(map(int, input().split()))) 

for i in range( m ) :
    k = int( input() ) 
    l = 0 ; r = n - 1 ; ans = -1 
    while l <= r :    
        mid = (l + r) // 2
        if check(mid , k) :
            l = mid + 1  
        else :
            r = mid - 1 ; ans = mid
    print(ans)
          
arr = (1 , n) 
for i in range( n ) : 
    if ( arr[i] == i ) :
        print( "hello world " )
    