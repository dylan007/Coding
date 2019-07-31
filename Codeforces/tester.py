import get_test	as gt 
import os,sys

def get_file_count(path):
	command = "ls -l " + path + " | wc -l"
	return int(os.popen(command).read())


def generate_output(lang,codename):
	print("Generating Output...\n")
	c = get_file_count("./test/in/") - 1
	basename = "./test/gen_out/"
	if lang == "cpp":
		for i in range(c):
			f = basename + str(i)
			command = "./a.out < ./test/in/" + str(i) + " > ./test/gen_out/" + str(i)
			os.system(command)
	else:
		for i in range(c):
			f = basename + str(i)
			command = "python " + codename + ".py < ./test/in/" + str(i) + " > ./test/gen_out/" + str(i)
			os.system(command) 

def get_lang(code):
	command = "ls " + str(code) + "* -t"
	res = os.popen(command).read()
	res = res.split('\n')
	res = res[:-1]
	return res[0].split('.')[-1]

def check():
	print("Checking files...\n")
	c = get_file_count("./test/in")-1
	for i in range(c):
		command = "diff " + "./test/out/" + str(i) + " ./test/gen_out/" + str(i)
		res = os.popen(command).read()
		if len(res)==0:
                    print("Sample Case " + str(i) + " : " + u'\u2705')
		else:
			filename = "./test/out/" + str(i)
			with open(filename) as f:
				print("--------------------------------------------------------------------")
				print("Sample Case " + str(i) + " : " + u'\u274C')
				print("Required Output : ")
				print("".join(f.readlines()))
			filename = "./test/gen_out/" + str(i)
			with open(filename) as f:
				print("Your Output : ")
				print("".join(f.readlines()))
				print("-------------------------------------------------------------------")

def run():
	code = sys.argv[1]
	gt.run(code)
	lang = get_lang(code)
	generate_output(lang,code)
	check()

if __name__ == "__main__":
	run()