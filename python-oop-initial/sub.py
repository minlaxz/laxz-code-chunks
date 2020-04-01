import mainfile
print('SUB MODULE STARTED.')

master_a = mainfile.Master_A()
master_a.method_one()
master_a.method_two(2,3,4, others=10)
master_a.method_three()

mainfile.class_level()
