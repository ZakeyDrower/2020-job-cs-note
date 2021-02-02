# machien : 1 file per hour
#   file:
#       word$timestamp$info
#   find max(count(word)) && count(word)

# file list
files = ['file1', 'file2', ... ]
word_dic = {}
for fn in files:
    lines = readlines(fn, 'r') # read lines
    for line in lines:
        word = (line.split['$'])[0]
        if word in word_dic:
            word_dic[word] = word_dic[word] + 1
        else:
            word_dic[word] = 1

[mc, mword] = [0, '']
for key in word_dic:
    if word_dic[key] > mc:
        mc = word_dic[key]
        mword = key
print(mword, mc, ' ')
