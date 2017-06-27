class Palindrome:
    @staticmethod
    def is_palindrome(word):
        flag = 0
        some_word = word[::-1]
        print "some_word is :", some_word
        new_word = some_word.lower()
        print "new_word is :", new_word
        for i in range(0, int(len(word)/2)):
            print "i is : ", i
            print "word[0] is :", word[i]
            print "new_word[0] is :", new_word[0]
            if ((word[i] == new_word[i])):
                print "word[0] is :", word[0]
                print "new_word[0] is :", new_word[0]
                flag = 1
            else:
                flag = 0
                break

        if flag == 1:
            print "palindrome"
        else:
            print "Not a Palindrome"

pal = Palindrome()
pal.is_palindrome('Deleveled')
