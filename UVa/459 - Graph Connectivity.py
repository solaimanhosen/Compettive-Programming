class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n
        self.count = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot == yroot:
            return

        if self.rank[xroot] > self.rank[yroot]:
            self.parent[yroot] = xroot
        elif self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
        else:
            self.parent[yroot] = xroot
            self.rank[xroot] += 1
        self.count -= 1

    def get_count(self):
        return self.count

def charIntMap():
    return {chr(ord('A') + i): i for i in range(26)}

if __name__ == '__main__':
    charInt = charIntMap()
    t = int(input().strip())

    input_lines = []
    while True:
        try:
            line = input()
            input_lines.append(line)
        except EOFError:
            break

    idx = 0
    for test in range(t):
        while idx < len(input_lines) and input_lines[idx].strip() == "":
            idx += 1  # Skip blank lines

        lastNode = input_lines[idx].strip()
        idx += 1
        uf = UnionFind(charInt[lastNode] + 1)

        while idx < len(input_lines):
            edge = input_lines[idx].strip()
            idx += 1
            if edge == "":
                break
            u, v = charInt[edge[0]], charInt[edge[1]]
            uf.union(u, v)

        print(uf.get_count())
        if test < t - 1:
            print()
