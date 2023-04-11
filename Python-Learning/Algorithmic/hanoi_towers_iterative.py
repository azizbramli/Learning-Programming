'''
/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */
'''

import sys

def hanoi(towers):
    """ compute Hanoi Towers algorithm """
    stack   = []
    steps   = 0
    stack.append(towers)

    while stack:
        action          = stack.pop()
        nb_disks        = action['disks']
        start           = action['s']
        end             = action['e']
        intermediate    = action['i']
        if nb_disks == 1:
            #print(start, " -> ", end)
            steps += 1
        else:
            stack.append({ 'disks' : nb_disks - 1, 's' : intermediate, 'e' : end, 'i': start })
            stack.append({ 'disks' : 1, 's' : start, 'e' : end, 'i': intermediate })
            stack.append({ 'disks' : nb_disks - 1, 's' : start, 'e' : intermediate, 'i': end })
    return steps

def main():
    """ main function """
    nb_disks    = int(sys.argv[1])
    nb_steps    = hanoi({ 'disks' : nb_disks, 's' : 1, 'e' : 3, 'i': 2 })
    print(nb_steps)

if __name__ == '__main__':
    main()
