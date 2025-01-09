# Python Brute
class Solution:
    def isPrefixOfWord(self, sentence: str, sw: str) -> int:
        return next((i+1 for i, val in enumerate([sw == x[:len(sw)] for x in sentence.split(' ')]) if val), -1)