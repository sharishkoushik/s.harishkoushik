if __name__ =="__main__":
    '''
    n = int(raw_input())
    print "n is :", n
    n1 = [raw_input() for i in range (1,n+1)]
    
    n1 = [int(i) for i in n1]
    print n1
    n2 = tuple(n1)
    print hash(n2)
    '''
    '''
    n3 = raw_input().split() 
    n3 = [int(i) for i in n3]
    print hash(tuple(n3)) 
    '''

    '''
    n = 3
    a = []
    for i in range (1, n+1):
        n3 = raw_input().split()
        a.append(n3)
    print a
    '''

    height = map(int, raw_input().split())
    #print width
    print height

