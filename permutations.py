def permute(s, ans):
    if len(s) == 0:
        print(ans)
        return

    for i in range(len(s)):
        ch = s[i]
        ros = s[:i] + s[i+1:]
        permute(ros, ans+ch)


s = "ABC"
permute(s, "")
