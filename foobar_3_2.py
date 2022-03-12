from collections import deque

def solution(map):
    w, h = len(map[0]), len(map)
    dist = [[[0 for i in range(w)] for j in range(h)] for k in range(2)]
    dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    q = deque()
    
    dist[0][0][0] = 1
    q.append([0, 0, 0])

    while q:
        r, c, flag = q.popleft()
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if nr < 0 or nc < 0 or nr >= h or nc >= w: continue
            if flag and map[nr][nc]: continue
            
            if flag == 0 and map[nr][nc] and dist[1][nr][nc] == 0: 
                q.append([nr, nc, 1])
                dist[1][nr][nc] = dist[0][r][c] + 1

            if map[nr][nc] == 0 and dist[flag][nr][nc] == 0: 
                q.append([nr, nc, flag])
                dist[flag][nr][nc] = dist[flag][r][c] + 1
    ret = int(1e8)
    if dist[0][h - 1][w - 1]: ret = min(ret, dist[0][h - 1][w - 1])
    if dist[1][h - 1][w - 1]: ret = min(ret, dist[1][h - 1][w - 1])
    return ret

print(solution([[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]))
print(solution([[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]))
