'''
Rewrote in python to avoid the weird C issues I was having.
What a waste of time.
Still wasn't working until I cleared the stack at the beginning of the isValid function.
I guess it wasn't reinitialising the class on new runs?
'''

class Solution:
    bracket_count = 0;
    square_count = 0;
    curly_count = 0;
    stack = []
    def isValid(self, s: str) -> bool:
        self.stack.clear()
        if (s[0] in ['}', ')', ']']):
            return False
        self.change_count(s[0])
        for c in s[1:]:
            if c != '{' and c != '(' and c != '[' and c != self.closed(self.peek()):
                return False
            self.change_count(c)
        return self.bracket_count == 0 and self.square_count == 0 and self.curly_count == 0

    def peek(self) -> str:
        if (self.stack):
            return self.stack[-1]
        return 'x'
    
    def closed(self, c: str) -> str:
        if c=='(':
            return ')'
        if c=='{':
            return '}'
        if c=='[':
            return ']'

    def change_count(self, c: str) -> None:
        if c=='(':
            self.bracket_count+=1
            self.stack.append(c)
        if c=='{':
            self.curly_count+=1
            self.stack.append(c)
        if c=='[':
            self.square_count+=1
            self.stack.append(c)
        if c==')':
            self.bracket_count-=1
            self.stack.pop()
        if c=='}':
            self.curly_count-=1
            self.stack.pop()
        if c==']':
            self.square_count-=1
            self.stack.pop()


