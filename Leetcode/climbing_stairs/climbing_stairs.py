from math import factorial
class Solution:
    def climbStairs(self, n: int) -> int:
        num_solutions=0
        for i in range(n, int(n/2-0.5), -1):
            ones = n - ((n-i) * 2)
            twos = n-i
            num_solutions += factorial(ones+twos)/(factorial(ones)*factorial(twos))
        return int(num_solutions)
    



if __name__ == "__main__":
    s = Solution()
    while True:
        print(s.climbStairs(int(input())))