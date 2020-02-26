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
    # here is the math and reasoning behind it... 
    # if you have the 1st quadrant in the coordinate system and a range of 0 to 1 that you fill with dots using x and y coordinates
    # you will get a perfect square given enough dots, now you expand from 1 quadrant to 4 quadrants and draw a circle with the
    # center point in the center of the coordinate system (0,0), that means that the radius will be 1, keep all that in mind
    # now.... the area of the circle is pi*r*r and the area of the square is (2r)*(2r)....also the area of the circle is the sum
    # of all dots inside the circle and the area of the square is the number of total dots, so whe have those two areas as a given
    # -------------- circle area/square area = circle area/ square area--------------
    # to get the pi: (pi*r*r)/[(2r)*(2r)] = number of dots in the circle / total dots
    #                (pi*r*r)/(4*r*r)  = number of dots in the circle / total dots
    #                pi / 4 = number of dots in the circle / total dots
    #                pi = 4 * number of dots in the circle / total dots
    # to determine if the dot is in the circle you use pitagoras theorem on its coordinates and it has to be smaller than the radius
    # which is 1, also it is critical to use the RANDOM UNIFORM distribution
    return pi


# the higher the n the higer teh precision, however it takes longer to compute
n = 10000000
result = generate_pi(n)
print(result)
