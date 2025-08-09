from collections import defaultdict

dx = [0, -1, 1, 0]
dy = [-1, 0, 0, 1]

def bfs(x, y, grid, key, visited):
    stack = [(x, y)]
    visited[x][y] = True
    count = 1
    while stack:
        cx, cy = stack.pop()
        for i in range(len(dx)):
            nx, ny = cx + dx[i], cy + dy[i]
            
            if nx < 0 or nx >= len(grid) or ny < 0 or ny >= len(grid[0]):
                continue
            
            if grid[nx][ny] == key and not visited[nx][ny]:
                stack.append((nx, ny))
                visited[nx][ny] = True
                count += 1
                
    return count

if __name__ == "__main__":
    while True:
        n = int(input().strip())
        if n == 0:
            break

        grid = [[0] * n for _ in range(n)]
        for i in range(n - 1):
            nums = list(map(int, input().strip().split()))
            for j in range(0, len(nums), 2):
                grid[nums[j] - 1][nums[j+1] - 1] = i + 1

        visited = [[False] * n for _ in range(n)]
        partitionSize = defaultdict(int)
        for i in range(n):
            for j in range(n):
                if not visited[i][j]:
                    sz = bfs(i, j, grid, grid[i][j], visited)
                    partitionSize[grid[i][j]] = sz

        if len(partitionSize) == n and sum(1 for i in range(n) if partitionSize[i] == n) == n:
            print("good")
        else:
            print("wrong")
