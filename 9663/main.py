n = int(input())

def checkmate(q1, q2):
    if q1[0] == q2[0]:
        return True
    if q1[1] == q2[1]:
        return True
    if q1[0] + q1[1] == q2[0] + q2[1]:
        return True
    if q1[0] - q1[1] == q2[0] - q2[1]:
        return True
    return False

def rec(n, step, queens):
    if n == step:
        result = 0
        for new_queen in range(1, n + 1):
            flag = True
            for prev_queen in queens:
                if checkmate(prev_queen, (new_queen, step)):
                    flag = False
            result += 1 if flag else 0
        return result

    result = 0
    for new_queen in range(1, n + 1):
        flag = True
        for prev_queen in queens:
            if checkmate(prev_queen, (new_queen, step)):
                flag = False
        if flag:
            new_queens = [(new_queen, step)]
            new_queens.extend(queens)
            result += rec(n, step + 1, new_queens)
    return result

print(rec(n, 1, []))