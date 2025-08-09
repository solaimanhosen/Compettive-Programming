from collections import defaultdict

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def markDice(grid, x, y, id, diceId, visited):
    stack = [(x, y)]
    visited[x][y] = True
    diceId[x][y] = id

    while stack:
        cx, cy = stack.pop()
        for i in range(len(dx)):
            nx, ny = cx + dx[i], cy + dy[i]
            if nx < 0 or nx >= len(grid) or ny < 0 or ny >= len(grid[0]):
                continue

            if (grid[nx][ny] == "*" or grid[nx][ny] == "X") and not visited[nx][ny]:
                stack.append((nx, ny))
                visited[nx][ny] = True
                diceId[nx][ny] = id

def diceDot(grid, x, y, visited):
    stack = [(x, y)]
    visited[x][y] = True

    while stack:
        cx, cy = stack.pop()
        for i in range(len(dx)):
            nx, ny = cx + dx[i], cy + dy[i]
            if nx < 0 or nx >= len(grid) or ny < 0 or ny >= len(grid[0]):
                continue

            if grid[nx][ny] == "X" and not visited[nx][ny]:
                stack.append((nx, ny))
                visited[nx][ny] = True

if __name__ == "__main__":
    caseno = 1
    while True:
        w, h = map(int, input().strip().split())
        if w == 0 and h == 0:
            break

        grid = []
        for _ in range(h):
            grid.append(input().strip())

        diceId = [[-1] * w for _ in range(h)]
        visited = [[False] * len(grid[0]) for _ in range(len(grid))]
        id = 0
        for i in range(h):
            for j in range(w):
                if (grid[i][j] == "*" or grid[i][j] == "X") and not visited[i][j]:
                    markDice(grid, i, j, id, diceId, visited)
                    id += 1

        visited = [[False] * len(grid[0]) for _ in range(len(grid))]
        dices = defaultdict(int)
        for i in range(h):
            for j in range(w):
                if grid[i][j] == "X" and not visited[i][j]:
                    diceDot(grid, i, j, visited)
                    id = diceId[i][j]
                    dices[id] += 1

        print(f"Throw {caseno}")
        print(*sorted(dices.values()))
        print()
        caseno += 1
