import collections
class Solution:
    def isValid(self, s: str) -> bool:
        st = deque()
        for b in s:
            if len(st) == 0:
                st.append(b)
            else:
                if b in ['(','[','{']:
                    st.append(b)
                else:
                    if b == ')':
                        if len(st) == 0 or st[-1] != '(':
                            return False
                        else:
                            st.pop()
                    elif b == ']':
                        if len(st) == 0 or st[-1] != '[':
                            return False
                        else:
                            st.pop()
                    else:
                        if len(st) == 0 or st[-1] != '{':
                            return False
                        else:
                            st.pop()
        return len(st) == 0