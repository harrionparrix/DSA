n="aaabbbcccddddeeee"

l=set(list(n))
print(*list(l))

# def rec(n):
#     if(len(n)==0):
#         return ""
#     ch=n[0]
#     rest=rec(n[1:])
#     if(ch==rest[0]):
#         return rest
#     else:
#         return (ch+rest)
    
# print(rec(n))