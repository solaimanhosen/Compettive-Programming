def take_inputs():
    inputs = []
    while True:
        try:
            line = input()
            inputs.append(line)
        except EOFError:
            break

    return inputs

def process_inputs(inputs):
    idx = 0
    t = int(inputs[idx].strip())
    idx += 1

    for _ in range(t):
        # Skip blank lines
        while idx < len(inputs) and inputs[idx].strip() == "":
            idx += 1

        grid = []
        while idx < len(inputs):
            line = inputs[idx].strip()
            if line[0] in "WL":
                grid.append(line)
                idx += 1
            else:
                break  # queries start

        queries = []
        while idx < len(inputs):
            line = inputs[idx].strip()
            if not line or inputs[idx].strip() == "":
                idx += 1
                break
            if line[0].isdigit():
                parts = line.split()
                if len(parts) == 2:
                    x, y = map(int, parts)
                    queries.append((x, y))
                idx += 1
            else:
                break

        yield grid, queries

def process_grid(grid):
    if not grid:
        return [], []

    rows, cols = len(grid), len(grid[0])
    visited = [[False] * cols for _ in range(rows)]
    lakeIds = [[-1] * cols for _ in range(rows)]
    lakeArea = []

    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]

    def dfs(id, x, y):
        stack = [(x, y)]
        visited[x][y] = True
        lakeIds[x][y] = id
        area = 1

        while stack:
            cx, cy = stack.pop()
            for idx in range(len(dx)):
                nx, ny = cx + dx[idx], cy + dy[idx]
                if is_valid_position(nx, ny, grid):
                    if not visited[nx][ny] and grid[nx][ny] == "W":
                        visited[nx][ny] = True
                        lakeIds[nx][ny] = id
                        area += 1
                        stack.append((nx, ny))

        return area

    id = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == "W" and not visited[i][j]:
                area = dfs(id, i, j)
                lakeArea.append(area)
                id += 1

    return lakeIds, lakeArea

def is_valid_position(x, y, grid):
    return 0 <= x < len(grid) and 0 <= y < len(grid[0])

if __name__ == '__main__':
    inputs = take_inputs()
    results = []

    for grid, queries in process_inputs(inputs):
        lakeIds, lakeArea = process_grid(grid)
        output = []

        for x, y in queries:
            lakeId = lakeIds[x-1][y-1]
            if lakeId == -1:
                output.append("0")
            else:
                output.append(str(lakeArea[lakeId]))

        results.append("\n".join(output))

    print("\n\n".join(results))
