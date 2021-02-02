s = input()
res = s[0]
cnt = 1
for i in range(1, len(s)):
    if s[i] == s[i-1]:
        cnt += 1
    else:
        res += str(cnt)
        cnt = 1
        res += s[i]
res += str(cnt)
print(res)