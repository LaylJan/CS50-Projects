from cs50 import *
import sys

num = get_int("Number: ")
tmp = num
odd = 0
even = 0
x = 0
count = 0

while tmp > 0:
    tmp //= 10
    digit = (tmp % 10) * 2
    odd += (digit // 10) + (digit % 10)
    tmp //= 10

tmp = num
even = tmp % 10

while True:
    tmp = tmp // 100
    even = even + (tmp % 10)
    if tmp <= 0:
        break

if not ((odd + even) % 10 == 0):
    print("INVALID")
    sys.exit()

tmp = num

while not (tmp <= 0):
    count += 1
    tmp = tmp // 10

if count == 15:
    tmp = num
    while tmp >= 100:
        tmp = tmp // 10
    if tmp == 34 or tmp == 37:
        print("AMEX")
        sys.exit()

if count == 16:
    tmp = num
    while tmp >= 100:
        tmp = tmp // 10
    if 51 <= tmp <= 55:
        print("MASTERCARD")
        sys.exit()

if count == 13 or count == 16:
    tmp = num
    while tmp >= 10:
        tmp = tmp // 10
    if tmp == 4:
        print("VISA")
        sys.exit()
print("INVALID")
sys.exit()
