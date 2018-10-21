from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from pyvirtualdisplay import Display

from os import listdir
from os.path import join 

url = 'http://codeforces.com/contest/'

b = webdriver.Firefox('./')
b.get('http://codeforces.com')
for i in listdir('../'):
	a = i.split('.')
	if a[0][0]=='5':
		b.get(url+a[0][:-1]+'/submit/')



