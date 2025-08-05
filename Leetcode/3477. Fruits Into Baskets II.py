from enum import Enum

class Status(Enum):
    FILLED = True
    EMPTY = False

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        unplaced = 0
        basket_status = [Status.EMPTY for _ in range(len(baskets))]
        for i in range(len(fruits)):
            placed = False
            for j in range(len(baskets)):
                if fruits[i] <= baskets[j] and basket_status[j] == Status.EMPTY:
                    basket_status[j] = Status.FILLED
                    placed = True
                    break

            if not placed:
                unplaced += 1

        return unplaced
