from bs4 import BeautifulSoup
import urllib.request as urllib2
import sys,os
import json

def check_log(id):
    with open('test/log.json') as f:
        log = json.load(f)
    if(log['id']==id):
        return True
    with open('test/log.json','w') as f:
        json.dump({'id':id},f)
    return False

def clean():
	#print("Cleaning folders...\n")
	command = "rm ./test/in/*"
	os.system(command)
	command = "rm ./test/out/*"
	os.system(command)


def makeSoup(url):
	response = urllib2.urlopen(url)
	webcontent = response.read()
	#print("Curling page...\n")
	return BeautifulSoup(webcontent,'html.parser')

def generateUrl(code):
	url = "http://www.codeforces.com/problemset/problem/" + str(code[:-1]) + "/" + code[-1].upper()
	#print("Getting problem page...\n")
	return url

def parse(p):
    out = ""
    p = str(p)
    p = p[5:-6]
    i = 0
    while i<len(p):
        if p[i:i+5]=="<br/>":
            out += "\n"
            i += 5
        else:
            out += p[i]
            i += 1
    return out

def gen(res):
	ri = []
	oi = []
	for i in range(len(res)):
		if i%2 == 0:
			ri.append(parse(res[i]))
		else:
			oi.append(parse(res[i]))
	return ri,oi

def filewrite(ri,oi):
	print("Creating testcases...\n")
	basename = "./test/in/"
	for i in range(len(ri)):
		f = basename+str(i)
		file = open(f,"a+")
		file.writelines(ri[i])
	basename = "./test/out/"
	for i in range(len(oi)):
		f = basename+str(i)
		file = open(f,"a+")
		file.writelines(oi[i])

def run(code):
    if not check_log(code):
        clean()
        soup = makeSoup(generateUrl(code))
        res = soup.find_all("pre")
        ri,oi = gen(res)
        filewrite(ri,oi)