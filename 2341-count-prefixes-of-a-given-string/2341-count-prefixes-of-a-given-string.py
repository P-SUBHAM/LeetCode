# Python brute
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return [s[:len(x)] == x for x in words].count(True)