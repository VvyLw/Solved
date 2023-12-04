def calculate_area(rectangles):
    x_coordinates = set()
    y_coordinates = set()

    for rect in rectangles:
        x_coordinates.add(rect[0])
        x_coordinates.add(rect[1])
        y_coordinates.add(rect[2])
        y_coordinates.add(rect[3])

    x_coordinates = sorted(list(x_coordinates))
    y_coordinates = sorted(list(y_coordinates))

    total_area = 0

    for i in range(len(x_coordinates) - 1):
        for j in range(len(y_coordinates) - 1):
            x1, x2 = x_coordinates[i], x_coordinates[i + 1]
            y1, y2 = y_coordinates[j], y_coordinates[j + 1]

            for rect in rectangles:
                if rect[0] <= x1 and rect[1] >= x2 and rect[2] <= y1 and rect[3] >= y2:
                    total_area += (x2 - x1) * (y2 - y1)
                    break

    return total_area

# 入力を受け取る
N = int(input())
rectangles = []

for _ in range(N):
    A, B, C, D = map(int, input().split())
    rectangles.append((A, B, C, D))

# 面積を計算
area = calculate_area(rectangles)

# 結果を出力
print(area)
