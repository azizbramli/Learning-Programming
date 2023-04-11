'''
/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */
'''

import sys

def hanoi(disks, start, end, tmp):
    """ compute Hanoi Towers algorithm """
    if disks > 0:
        hanoi.nb_moves += 1
        hanoi(disks - 1, start, tmp, end)
        print(disks, "\t", start, " -> ", end, " ", tmp)
        hanoi(disks - 1, tmp, end, start)
    return hanoi.nb_moves

if __name__ == '__main__':
    NB_DISKS = int(sys.argv[1])
    hanoi.nb_moves = 0
    print(hanoi(NB_DISKS, 1, 3, 2))
