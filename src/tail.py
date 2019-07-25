length_of_tail = int(input().strip())
lines_to_print = []
with open('sample.txt', 'r') as f:
    for line in f:
        line = line.rstrip()
        if not line:
            break
        if len(lines_to_print) == length_of_tail:
            lines_to_print = lines_to_print[1:]
            lines_to_print.append(line)
        elif len(lines_to_print) < length_of_tail:
            lines_to_print.append(line)
        else:
            print("something went wrong")
for line in lines_to_print:
    print(line)
