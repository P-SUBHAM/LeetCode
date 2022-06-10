class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = {}
        for ch in magazine:
            mp[ch] = mp.get(ch,0)+1
        for ch in ransomNote:
            if mp.get(ch,0) == 0:
                return False;
            else:
                mp[ch] = mp[ch]-1
        return True