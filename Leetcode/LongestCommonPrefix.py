class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        strs = sorted(strs)
        output = ""

        for i in range(len(strs[0])):
            piece = [prefix[i] for prefix in strs]
        
            if len(set(piece)) == 1:
                output += piece[0]
            else:
                break
        return output
            

        
            

            
        
