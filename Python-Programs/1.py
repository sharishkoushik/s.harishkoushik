class Human:
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

    def perform_math_task(self, operation, *args):
        print "%s did a math opration and the result is %f" % (self.name, operation(*args))

def add(a, b):
    return a + b

harish = Human("harish", "male")
harish.perform_math_task(add, 3, 4)
