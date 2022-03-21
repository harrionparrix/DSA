n="pippxxppiixipi"
# ans=3.14 instead of pi
def replace(n):
    if(len(n)==0):
        return
    ch=n[0]
    rest=n[1:]
    if(ch=="p" and rest[0]=="i"):
        print("3.14",end="")
        replace(rest[1:])
    else:
        print(rest[0],end="")
        replace(rest)

replace(n)