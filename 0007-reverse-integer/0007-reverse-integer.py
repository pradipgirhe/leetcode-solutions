
class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        sign = -1 if x < 0 else 1
        x = abs(x)

        def helper(x):
            nonlocal rev
            if x == 0:
                return

            digit = x % 10
            rev = rev * 10 + digit
            helper(x // 10)

        helper(x)
        rev *= sign

        if rev < -(2**31) or rev > 2**31 - 1:
            return 0

        return rev
