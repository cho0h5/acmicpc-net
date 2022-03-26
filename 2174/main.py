import sys

def convert_direction(character):
    if character == 'N':
        return 0
    elif character == 'E':
        return 1
    elif character == 'S':
        return 2
    return 3

A, B = map(int, input().split())
N, M = map(int, input().split())

locations = []
for i in range(N):
    location = input().split()
    locations.append([int(location[0]), int(location[1]), convert_direction(location[2])])

commands = []
for i in range(M):
    command = input().split()
    commands.append((int(command[0]), command[1], int(command[2])))

#  N  |  0
# W E | 3 1
#  S  |  2

for command in commands:
    selector, action, repeat = command

    # prev location
    _x = locations[selector-1][0]
    _y = locations[selector-1][1]

    # perform action
    if action == 'L':
        locations[selector-1][2] -= repeat
        locations[selector-1][2] %= 4
    elif action == 'R':
        locations[selector-1][2] += repeat
        locations[selector-1][2] %= 4
    else:
        if locations[selector-1][2] == 0:
            locations[selector-1][1] += repeat
        elif locations[selector-1][2] == 1:
            locations[selector-1][0] += repeat
        elif locations[selector-1][2] == 2:
            locations[selector-1][1] -= repeat
        else:
            locations[selector-1][0] -= repeat

    # check collision to another robot
    if action == 'F':
        if locations[selector-1][2] % 2 == 0:
            for another_selector in range(len(locations)):
                x, y, _ = locations[another_selector]
                if (_y <= y and y <= locations[selector-1][1]) or (locations[selector-1][1] <= y and y <= _y):
                    min = 1000
                    index = 0
                    if selector != another_selector+1 and x == locations[selector-1][0]:
                        if abs(locations[selector-1][1] - y) < min:
                            min = y
                            index = another_selector + 1

            if min != 1000:
                print("Robot {} crashes into robot {}".format(selector, index))
                sys.exit()
        else:
            for another_selector in range(len(locations)):
                x, y, _ = locations[another_selector]
                if (_x <= x and x <= locations[selector-1][0]) or (locations[selector-1][0] <= x and x <= _x):
                    min = 1000
                    index = 0
                    if selector != another_selector+1 and y == locations[selector-1][1]:
                        if abs(locations[selector-1][0] - x) < min:
                            min = x
                            index = another_selector + 1

            if min != 1000:
                print("Robot {} crashes into robot {}".format(selector, index))
                sys.exit()

    # check collision to wall
    if locations[selector-1][0] < 1 or A < locations[selector-1][0]:
        print("Robot {} crashes into the wall".format(selector))
        sys.exit()
    if locations[selector-1][1] < 1 or B < locations[selector-1][1]:
        print("Robot {} crashes into the wall".format(selector))
        sys.exit()

print("OK")
