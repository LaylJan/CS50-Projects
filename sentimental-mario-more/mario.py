import cs50

height = 10
while not (height < 9 and height > 0):
    height = cs50.get_int("Height: ")
for i in range(1, height + 1):
    print(" " * (height - (i)), end="")
    print("#" * (i), end="  ")
    print("#" * (i))
