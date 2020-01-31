import sys

if len(sys.argv) <= 1 or len(sys.argv) == 3:
    print ('FORMAT: python3 tail.py [-option VALUE] FILENAME')
    sys.exit(1)

length_of_tail = 10
file_name = ''
if len(sys.argv) > 2:
    filename = sys.argv[3]
    try:
        length_of_tail = int(sys.argv[2])
    except:
        print('The length of the tail wasn\'t a number')
        sys.exit(1)

    if length_of_tail <= 0:
        print('Please provide a number greater than or equal to 1')
        sys.exit(1)
else:
    filename = sys.argv[1]

file_lines = []
with open(filename, 'r') as f:
    for line in f:
        file_lines.append(line)
        print(line)

print(file_lines[-1:-(length_of_tail)])