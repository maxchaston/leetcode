'''
Only did it in python to be able to use this cool one liner.
Code golf memory pays off.
'''

def minPartitions(self, n: str) -> int:
        return max(map((lambda x: int(x)), n))
