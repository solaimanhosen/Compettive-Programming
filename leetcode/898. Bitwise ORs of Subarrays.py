class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        curr = set()
        final = set()

        for x in arr:
            curr = {x | y for y in curr} | {x}
            final |= curr

        return len(final)
