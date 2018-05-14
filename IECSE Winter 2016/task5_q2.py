x1,y1 = map(float,raw_input().split())
x2,y2 = map(float,raw_input().split())
x3,y3 = map(float,raw_input().split())
if x1==x2:
    m3 =
m3 = (y1-y2)/(x1-x2)
m2 = (y3-y1)/(x3-x1)
m1 = (y3-y2)/(x3-x2)

print "3"

x = (y3-y1 + m1*x1 - m3*x3)/(m1-m3)
y = y3 + m3*(x-x3)

print("%0.2f %0.2f\n" % x,y)

x = (y3-y1 + m1*x1 - m3*x3)/(m1-m3)
y = y3 + m3*(x-x3)
print("%0.2f %0.2f\n" % x,y)

x = (y3-y1 + m1*x1 - m3*x3)/(m1-m3)
y = y3 + m3*(x-x3)

print("%0.2f %0.2f\n" % x,y)