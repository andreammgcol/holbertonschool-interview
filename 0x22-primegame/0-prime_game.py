#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """ Method isWinner for Maria and Ben """
    if not nums or x < 1:
        return None
    n = max(nums)
    set_filter = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not set_filter[i]:
            continue
        for j in range(i * i, n + 1, i):
            set_filter[j] = False

    set_filter[0] = set_filter[1] = False
    count = 0
    for i in range(len(set_filter)):
        if set_filter[i]:
            count += 1
        set_filter[i] = count

    p = 0
    for n in nums:
        p += set_filter[n] % 2 == 1
    if p * 2 == len(nums):
        return None
    if p * 2 > len(nums):
        return "Maria"
    return "Ben"
