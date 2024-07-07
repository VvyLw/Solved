def is_intersecting(a, b, c, d, e, f, g, h, i, j, k, l):
    # Check if there is separation along the x-axis
    if d < g or j < a:
        return False
    # Check if there is separation along the y-axis
    if e < h or k < b:
        return False
    # Check if there is separation along the z-axis
    if f < i or l < c:
        return False
    # If there is no separation along any axis, the cuboids intersect
    return True

# Example usage
a, b, c, d, e, f = map(int, input().split())
g, h, i, j, k, l = map(int, input().split())

print("Yes" if is_intersecting(a, b, c, d, e, f, g, h, i, j, k, l) else "No")  # Output: False