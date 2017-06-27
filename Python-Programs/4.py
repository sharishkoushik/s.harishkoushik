import re 
fo = open("ip", "r")
str1 = fo.read(100)
matchObj = re.search(r'[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}', str1,re.M|re.I)

print matchObj.group() 
if matchObj:
    print "matched"

fo.close()
