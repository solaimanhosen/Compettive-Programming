
class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot == yroot:
            return

        if self.rank[xroot] >= self.rank[yroot]:
            self.parent[yroot] = xroot
            self.rank[xroot] += self.rank[yroot]
        elif self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
            self.rank[yroot] += self.rank[xroot]

    def get_largest_chain(self):
        max_rank = 0
        for i in range(len(self.parent)):
            max_rank = max(max_rank, self.rank[i])

        return max_rank

if __name__ == '__main__':
    while True:
        line = input()
        if not line or len(line.strip()) == 0:
            continue

        n, r = map(int, line.strip().split())
        if n == 0 and r == 0:
            break

        uf = UnionFind(n)
        animalId = {input().strip(): i for i in range(n)}

        for _ in range(r):
            u, v = map(lambda x: animalId[x], input().strip().split())
            uf.union(u, v)

        print(uf.get_largest_chain())
