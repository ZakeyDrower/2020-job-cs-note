def checkStr(s:str):
    if len(s) != 8:
        return False
    for i in range(len(s)):
        if s[i]<='0' or s[i] > '9':
            return False
    return True

s, n = input().split(' ')
n = int(n)
check = checkStr(s) and n in range(1, 9)
if check:
    arr = [int(i) for i in s[:n-1]+s[n:]]
    arr.sort()
    print(''.join([str(i) for i in arr]))
else:
    print('error')

# 95137462 2
# 95137462 9
# 951374362 2