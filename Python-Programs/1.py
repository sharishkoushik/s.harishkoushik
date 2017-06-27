import sets

magic_chars = sets.Set('abracadabra')
print "magic_chars is : ", magic_chars
poppins_chars = sets.Set('supercalifragilisticexpialidocious')
print "poppins_chars is :", poppins_chars
print ''.join(magic_chars & poppins_chars)
x = 'xyxxyy hejyxeh e '
print '|'+x.strip('he')+'|'
str1 = ['a','b','c','d','e']
print '-'.join(str1)
