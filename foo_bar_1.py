def solution(s):
    capital = '000001'
    blank = '000000'
    alpa = [
        '100000', # a
        '110000', # b
        '100100', # c
        '100110', # d
        '100010', # e
        '110100',
        '110110',
        '110010',
        '010100',
        '010110',
        '101000',
        '111000',
        '101100',
        '101110',
        '101010',
        '111100',
        '111110',
        '111010',
        '011100',
        '011110',
        '101001',
        '111001',
        '010111',
        '101101',
        '101111',
        '101011'
    ] 
    ret = ''
    for c in s:
        if ord('a') <= ord(c) <= ord('z'):
            ret += alpa[ord(c) - ord('a')]
        elif ord('A') <= ord(c) <= ord('Z'):
            ret += capital
            ret += alpa[ord(c) - ord('A')]
        else:
            ret += blank
    return ret
print(solution('code'))
print(solution('Braille'))
print(solution('The quick brown fox jumps over the lazy dog'))
