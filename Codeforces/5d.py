import math

def dist(speed,time,acc):
	return speed*time + 0.5 * acc * (time**2)

def solve(a,b,c):
	d = math.sqrt(b*b - 4*a*c)
	x = (d - b)/(2*a)
	y = (0-d-b)/(2*a)
	return max(x,y) 

def travelTime(distance,speed,acc,maxSpeed):
	tAll = solve(acc,2*speed,-2*distance)
	tMax = (maxSpeed-speed)/acc 
	#print tAll,tMax
	if tMax >= tAll:
		return tAll
	return tMax + (distance-dist(speed,tMax,acc))/maxSpeed

def main():
	acc,maxSpeed = map(float,raw_input().split())
	length,distance,w = map(float,raw_input().split())
	ans = 0.0
	if maxSpeed<=w:
		ans = travelTime(length,0,acc,maxSpeed)
	else:
		tw = w/acc
		#print tw
		dw = dist(0,tw,acc)
		#print dw
		if dw >= distance:
			ans = travelTime(length,0,acc,maxSpeed)
		else:
			ans = tw + 2*travelTime(0.5*(distance-dw),w,acc,maxSpeed) + travelTime(length-distance,w,acc,maxSpeed)
	print '%.9f' % ans

if __name__ == "__main__":
	main()