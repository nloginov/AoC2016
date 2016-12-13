from itertools import ifilter
data = 'L5, R1, L5, L1, R5, R1, R1, L4, L1, L3, R2, R4, L4, L1, L1, R2, R4, R3, L1, R4, L4, L5, L4, R4, L5, R1, R5, L2, R1, R3, L2, L4, L4, R1, L192, R5, R1, R4, L5, L4, R5, L1, L1, R48, R5, R5, L2, R4, R4, R1, R3, L1, L4, L5, R1, L4, L2, L5, R5, L2, R74, R4, L1, R188, R5, L4, L2, R5, R2, L4, R4, R3, R3, R2, R1, L3, L2, L5, L5, L2, L1, R1, R5, R4, L3, R5, L1, L3, R4, L1, L3, L2, R1, R3, R2, R5, L3, L1, L1, R5, L4, L5, R5, R2, L5, R2, L1, L5, L3, L5, L5, L1, R1, L4, L3, L1, R2, R5, L1, L3, R4, R5, L4, L1, R5, L1, R5, R5, R5, R2, R1, R2, L5, L5, L5, R4, L5, L4, L4, R5, L2, R1, R5, L1, L5, R4, L3, R4, L2, R3, R3, R3, L2, L2, L2, L1, L4, R3, L4, L2, R2, R5, L1, R2'

(x, y) = (0, 0)
(dx, dy) = (0, 1)

history = set((x, y))
found_second_answer = False

for cmd, count in ((token[0], int(token[1:])) for token in data.split(', ')):
  (dx, dy) = (-dy, dx) if cmd == 'L' else (dy, -dx)
  new_blocks = [(x + dx*c, y + dy*c) for c in range(1, count+1)]
  
  if not found_second_answer:
    answer = next(ifilter(lambda e: e in history, new_blocks), None)
  
    if answer:
      print "Second Answer: %d" % (abs(answer[0]) + abs(answer[1]))
      found_second_answer = True
    
    history.update(new_blocks)
    
  (x, y) = new_blocks[-1]

print "First Answer: %d" % (abs(x) + abs(y))
