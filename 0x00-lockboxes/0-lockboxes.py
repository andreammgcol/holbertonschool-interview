#!/usr/bin/python3
# Method that determines if all the boxes can be opened


def canUnlockAll(boxes):

    canOpen = [0]

    for box in canOpen:
        for key in boxes[box]:
            if key not in canOpen and key < len(boxes):
                canOpen.append(key)

    if len(canOpen) == len(boxes):
        return (True)
    else:
        return (False)
