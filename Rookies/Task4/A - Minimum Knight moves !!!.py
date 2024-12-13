from collections import deque

all_moves= [(2,1) , (2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]


def check_if_available(x,y):
    return 0 <= y <8 and 0<= x < 8 

def get_position (pos):
    column = ord(pos[0]) - ord('a')
    row = int(pos[1]) - 1


    return column , row 

def moves(start ,end):
    if start == end:
        return 0

    start_x, start_y =get_position(start)
    end_x , end_y = get_position(end)

    queue = deque([(start_x,start_y)])
    visited = [[False for _ in range(8)] for _ in range(8)]

    visited[start_x][start_y] = True

    steps = 0

    while queue:
        for _ in range(len(queue)):
            current_x , current_y = queue.popleft()

            for dx, dy in all_moves:
                new_x, new_y = current_x + dx, current_y + dy

            if new_x == end_x and new_y == end_y:
                return steps + 1
            if check_if_available(new_x, new_y) and not visited[new_x][new_y]:
                visited[new_x][new_y] = True
                queue.append((new_x, new_y))
 

        steps += 1

    return -1



if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")

    T = int(data[0])
    results = []

    for i in range(1, T + 1):
        start, end = data[i].split()
        results.append(moves(start, end)) 

    print("\n".join(map(str, results)))

