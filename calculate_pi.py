import random


def generate_pi(number_of_dots):
    dots_in_the_circle = 0
    dots_in_total = 0
    for i in range(number_of_dots):
        x = random.uniform(0,1)
        y = random.uniform(0,1)
        distance = x * x + y * y
        if distance < 1:
            dots_in_the_circle += 1
        dots_in_total += 1

    pi = 4 * dots_in_the_circle / dots_in_total

    return pi


n = 10000000
result = generate_pi(n)
print(result)
