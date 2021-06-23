#!/usr/bin/python3


def makeChange(coins, total):
    numCoins = 0
    if total <= 0:
        return numCoins
    coins.sort(reverse=True)
    while (total > 0 and coins):
        n = int(total / coins[0])
        total = total - (coins[0] * n)
        numCoins = numCoins + n
        coins.remove(coins[0])
    if total != 0:
        return -1
    return numCoins
