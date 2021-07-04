class Solution:
    # @return an integer
    def reverse(self, x):
        negFlag = 1
        if x < 0:
            negFlag = -1
            strx = str(x)[1:]
        else:
            strx = str(x)

        x = int(strx[::-1])
        
        return 0 if x > pow(2, 31) else x * negFlag