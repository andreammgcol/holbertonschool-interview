#!/usr/bin/python3
# Method that determines if all the boxes can be opened


def canUnlockAll(boxes):

    index = 1
    canOpen = True

    for box in boxes[1:len(boxes)]:
        index += 1
        if len(box) > 0 and index not in box:
            canOpen = False

    return(canOpen)
