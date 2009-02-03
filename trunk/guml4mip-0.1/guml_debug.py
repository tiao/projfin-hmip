from os import getenv
from string import replace

def prn(str):
	if getenv("DEBUG"):
		print str
