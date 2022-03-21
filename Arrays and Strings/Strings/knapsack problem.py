wt=[2,3,5,4]
val=[1,2,6,5]

w=8
n=len(wt)

def knapsack(wt,val,w,n):
    if(w==0 or n==0):
        return 0
    if(wt[n-1]<=w):
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1))
    elif(wt[n-1]>w):
        return knapsack(wt,val,w,n-1);

profit=knapsack(wt,val,w,n)

print(profit)

