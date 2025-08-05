def traverse(grid, x, y):
    steps = 0
    pos = dict()
    pos[(x, y)] = steps
    while 0 <= x < len(grid) and 0 <= y < len(grid[0]):
        if grid[x][y] == "N":
            x -= 1
        elif grid[x][y] == "S":
            x += 1
        elif grid[x][y] == "W":
            y -= 1
        elif grid[x][y] == "E":
            y += 1
        steps += 1

        if (x, y) not in pos:
            pos[(x, y)] = steps
        else:
            return f"{pos[(x, y)]} step(s) before a loop of {steps - pos[(x, y)]} step(s)"

    return f"{steps} step(s) to exit"

if __name__ == "__main__":
    while True:
        rows, cols, entry = map(int, input().strip().split())

        if not rows and not cols and not entry:
            break

        grid = []
        for _ in range(rows):
            grid.append(input().strip())

        print(traverse(grid, 0, entry - 1))
