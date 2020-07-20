#!/usr/bin/python3
# Method that determines if all the boxes can be opened


def canUnlockAll(boxes):

    countOpenedBoxes = 1
    numBoxes = len(boxes)
    canOpen = False
    tmpKeys = [*range(numBoxes)]
    tmpKeys = tmpKeys[1:len(tmpKeys)]

    for key in tmpKeys:
        for box in boxes:
            if key in box:
                countOpenedBoxes += 1
                break

    canOpen = countOpenedBoxes == numBoxes
    return(canOpen)
