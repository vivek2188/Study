import random
from math import log, ceil

random.seed(121)

def fixed_exponential_pacing(starting_percent=0.2, step_length=5, inc=2, data_size=1):
    gv, val = list(), float(starting_percent)

    i = 1
    gv.append(val * data_size)
    while(True):
        if val==1:
            break
        val = min(starting_percent * inc ** (i // step_length), 1)
        i += 1
        gv.append(val * data_size)

    return gv

def varied_exponential_pacing(starting_percent, inc, steps, step_length, data_size=1):
    gv = list()

    i = 0
    z_i = sum([(i>step_len_i) for step_len_i in step_length])
    val = min(starting_percent * inc ** z_i, 1)
    gv.append(val * data_size)
    while(True):
        if val==1:
            break
        z_i = sum([(i>step_len_i) for step_len_i in step_length])
        val = min(starting_percent * inc ** z_i, 1)
        i += 1
        gv.append(val * data_size)

    return gv

def single_step_pacing(starting_percent=0.2, step_length=5, data_size=1):
    gv, val = list(), float(starting_percent)

    i = 1
    gv.append(val * data_size)
    while(True):
        if val==1:
            break
        val = min(starting_percent ** (i < step_length), 1)
        i += 1
        gv.append(val * data_size)

    return gv

if __name__=="__main__":
    # FIXED EXPONENTIAL PACING
    print('Fixed Exponential Pacing: ')
    gv = fixed_exponential_pacing(inc=1.5)
    for i, gv_i in enumerate(gv):
        print('-> gv[{}]: {:.2f}'.format(i, gv_i))

    # VARIED EXPONENTIAL PACING
    print('Varied Exponential Pacing: ')
    starting_percent = 0.2
    inc = 1.2
    min_step_len = 3
    max_step_len = 10
    steps = ceil(-log(starting_percent, inc))
    step_length = [random.randint(min_step_len, max_step_len) for i in range(steps)]

    gv = varied_exponential_pacing(starting_percent=starting_percent, inc=inc, steps=steps, step_length=step_length)
    for i, gv_i in enumerate(gv):
        print('-> gv[{}]: {:.2f}'.format(i, gv_i))

    # SINGLE STEP PACING
    print('Single Step Pacing: ')
    gv = single_step_pacing()
    for i, gv_i in enumerate(gv):
        print('-> gv[{}]: {:.2f}'.format(i, gv_i))
