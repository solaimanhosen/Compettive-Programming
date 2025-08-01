from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]

        result = [[1], [1, 1]]
        for i in range(2, numRows):
            lastRow = result[-1]
            row = [0] * (len(lastRow) + 1)
            for j in range(len(lastRow)):
                row[j] += lastRow[j]
                row[j + 1] += lastRow[j]

            result.append(row)

        return result
