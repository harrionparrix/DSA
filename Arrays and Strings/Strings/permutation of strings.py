n="ABC"
ans=""

def permute(n,ans):
    if(len(n)==0):
        print(ans)
        return
    ch=n[0]
    rest=n[1:]
    permute(rest,ans)
    permute(rest,ans+ch)

permute(n, ans)