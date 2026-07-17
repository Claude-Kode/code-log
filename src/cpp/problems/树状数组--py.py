n, m = map(int, input().split()) 
tree = [0] * (n + 1)
arr = []

def lowbit( i : int ) -> int : 
    return i & -i

def update( pos, delta : int ) -> None : 
    i = pos 
    while(i <= n ) :
        tree[i] += delta
        i += lowbit( i ) 

def calSum( l , r : int ) -> int :
    i , j , suml , sumr = (l - 1) , r , 0 , 0 
    while( i > 0 ) :
        i -= lowbit( i )
        suml += tree[i]
    while( j > 0 ) :
        j -= lowbit( j )
        sumr += tree[j] 
    return sumr - suml

num = list( map( int , input().split() ) ) 
for i in range( n ) :
    num = int(input())
    arr.append( num )
    update( i , num )

for _ in range( m ) :
    op = int(input())
    if op == 1 : 
        x , k = map(int, input().split())
        update( x , k )

    if op == 2 : 
        x , y = map(int , input().split())
        print( calSum(x , y) )

