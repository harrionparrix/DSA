n=int(input())
a=[]
sum=int(input())
for i in range(n):
    x=int(input())
    a.append(x)
l=0
r=0
cur=0
for i in range(n):
    if(sum>cur):
        cur+=a[r]
        r+=1
    elif(sum<cur):
        cur=cur-a[l]
        l+=1
if(sum==cur):
    print("Array is from index ",l," to ",r-1)
        