def exchange(grade):
    scores = { 'A': 4.0, 'B': 3.0, 'C': 2.0, 'D': 1.0, 'F': 0.0 }
    return scores[grade[0]] + (0.5 if grade[-1] == '+' else 0.0)

points = 0
scores = 0
for _ in range(20):
    name, score, grade = input().split()
    if grade == 'P': continue
    points += float(score) * exchange(grade)
    scores += float(score)
print('%.6f'%(points/scores))