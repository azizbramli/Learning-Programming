'''
/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */
'''

G_CONSTANT = 6.67408 * (10 ** -11)

def newton_gravitation_law(m_1, m_2, distance):
    """ return force between m1 and m2 """
    return G_CONSTANT * m_1 * m_2 / (distance * distance)

def main():
    """ main function """
    print("Mass 1 in kg: ")
    m_1         = float(input())
    print("Mass 2 in kg: ")
    m_2         = float(input())
    print("Distance in meters: ")
    distance    = float(input())
    print(f"Force between m1 and m2: {newton_gravitation_law(m_1, m_2, distance):.1f} N.")

if __name__ == '__main__':
    main()
