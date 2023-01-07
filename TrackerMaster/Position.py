import random
import time
from math import sqrt
#Test code from here
#0/0        1920/0
#0/1080     1920/1080
import pyautogui
time.sleep(2)
testpointX, testpointY = pyautogui.position()
print(testpointX, testpointY)
d = 1920
p = 0
q = 1080
ra = sqrt(testpointX*testpointX+testpointY*testpointY)
rb = sqrt((1920-testpointX)*(1920-testpointX)+testpointY*testpointY)
rc = sqrt(testpointX*testpointX+(1080-testpointY)*(1080-testpointY))
print (ra, rb, rc)
#Test code up to here
#d = input("distance from a to b")
#p = input("x distance from a to c")
#q = input("y distance from a to c")
print ("Position:")
x = 1/(2*d) * (ra * ra - rb * rb) + 0.5 * d
y = q - sqrt(rc * rc - ((1 / (2*d) * (ra * ra - rb * rb) + 0.5 * d - p) * (1 / (2*d) * (ra * ra - rb * rb) + 0.5 * d - p))) #Maybe change later, minus may brake shit
print (x, y) 