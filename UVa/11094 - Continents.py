
dx = [0, -1, 1, 0]
dy = [-1, 0, 0, 1]

def dfs(grid, land, x, y, visited, ids, id):
    stack = [(x, y)]
    visited[x][y] = True
    ids[x][y] = id
    count = 1

    while stack:
        cx, cy = stack.pop()
        for i in range(len(dx)):
            nx, ny = cx + dx[i], cy + dy[i]
            if nx < 0 or nx >= len(grid):
                continue

            if ny < 0:
                ny = len(grid[0]) - 1
            if ny >= len(grid[0]):
                ny = 0

            if grid[nx][ny] == land and not visited[nx][ny]:
                stack.append((nx, ny))
                visited[nx][ny] = True
                ids[nx][ny] = id
                count += 1

    return count

if __name__ == "__main__":
    inputs = []
    while True:
        try:
            line = input().strip()
            inputs.append(line)
        except:
            break

    idx = 0
    while idx < len(inputs):
        while idx < len(inputs) and inputs[idx] == "":
            idx += 1

        if idx == len(inputs):
            break

        row, col = map(int, inputs[idx].split())
        idx += 1

        grid = []
        for _ in range(row):
            grid.append(inputs[idx])
            idx += 1

        curr_x, curr_y = map(int, inputs[idx].split())
        idx += 1
        land = grid[curr_x][curr_y]

        visited = [[False] * col for _ in range(row)]
        ids = [[-1] * col for _ in range(row)]
        id = 0
        areas = []
        for i in range(row):
            for j in range(col):
                if grid[i][j] == land and not visited[i][j]:
                    area = dfs(grid, land, i, j, visited, ids, id)
                    areas.append((area, id))
                    id += 1

        curr_id = ids[curr_x][curr_y]
        max_area = 0
        for i in range(len(areas)):
            if areas[i][1] != curr_id:
                max_area = max(max_area, areas[i][0])

        print(max_area)
