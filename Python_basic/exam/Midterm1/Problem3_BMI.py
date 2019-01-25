def bmi(m, h):
    h *= 0.01
    BMI = m/(h**2)
    if BMI < 15.0:
        print('VSU')
    elif BMI < 16.0:
        print('SUN')
    elif BMI < 18.5:
        print('UND')
    elif BMI < 25.0:
        print('NOR')
    elif BMI < 30.0:
        print('OVE')
    elif BMI < 35.0:
        print('MOV')
    elif BMI < 40.0:
        print('SOV')
    else:
        print('VSO')
    






m = eval(input())
h = eval(input())

bmi(m, h)
