# Approach 1: Python brute force
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return [pref == x[:len(pref)] for x in words].count(True)