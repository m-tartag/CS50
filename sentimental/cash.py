from cs50 import get_float


def change():

    counter = 0
    cents = 0

    while(cents <= 0):
        cents = get_float("Enter change: ") * 100

    while(cents >= 0):
        if cents >= 25:
            cents -= 25
            counter += 1
        elif cents >= 10:
            cents -= 10
            counter += 1
        elif cents >= 5:
            cents -= 5
            counter += 1
        elif cents >= 1:
            cents -= 1
            counter += 1
        else:
            print(counter)
            break


change()
