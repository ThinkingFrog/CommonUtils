if __name__ == '__main__':
    n = int(input('Input any positive integer: '))
    matr = [[0 for i in range(n)] for j in range(n)]

    x = 0
    y = 0
    x_dir = 1
    y_dir = 0
    for num in range(1, n ** 2 + 1):
        matr[y][x] = num
        if (x == n - 1 or matr[y][x + 1] != 0) and x_dir == 1:
            x_dir = 0
            y_dir = 1

        elif (x == 0 or matr[y][x - 1] != 0) and x_dir == -1:
            x_dir = 0
            y_dir = -1

        elif (y == n - 1 or matr[y + 1][x] != 0) and y_dir == 1:
            y_dir = 0
            x_dir = -1

        elif (y == 0 or matr[y - 1][x] != 0) and y_dir == -1:
            y_dir = 0
            x_dir = 1

        x += x_dir
        y += y_dir

    for i in range(len(matr)):
        for j in range(len(matr[i])):
            print(matr[i][j], end=" ")
        print()