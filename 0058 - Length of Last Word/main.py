# 58. Length of Last Word

'''
Quite an easy one.
Probably because I chose to do it in python.
Such is life for these code-golf style questions.
'''
import re
def lengthOfLastWord(s):
    s = re.sub(r"\s+", " ", s, flags=re.UNICODE).strip()
    return len(s.split()[-1])

lengthOfLastWord("   fly me   to   the moon  ")
