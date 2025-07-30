
class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y) -> int:
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot == yroot:
            return self.rank[xroot]

        if self.rank[xroot] >= self.rank[yroot]:
            self.parent[yroot] = xroot
            self.rank[xroot] += self.rank[yroot]
            return self.rank[xroot]
        elif self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
            self.rank[yroot] += self.rank[xroot]
            return self.rank[yroot]

if __name__ == '__main__':
    t = int(input().strip())

    for _ in range(t):
        n = int(input().strip())
        lines = []
        idx = 0
        nameId = dict()
        for _ in range(n):
            line = input().strip()
            lines.append(line)

            u, v = line.split()
            if u not in nameId:
                nameId[u] = idx
                idx += 1
            if v not in nameId:
                nameId[v] = idx
                idx += 1

        uf = UnionFind(len(nameId))

        for line in lines:
            u, v = line.split()
            print(uf.union(nameId[u], nameId[v]))
