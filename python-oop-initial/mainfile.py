print('outside of class')
class Master_A:
    print('inside of Master_A')
    def __init__(self):
        print('inside of __init__')

    def method_one(self):
        print('I am method one')

    def method_two(self, *args, others):
        print('I am method two')
        for i in args:
            print(i)
        print(others)
    
    def method_three(self):
        self.method_two(2,3, others=5)


def class_level():
    print('I am class level method')
    