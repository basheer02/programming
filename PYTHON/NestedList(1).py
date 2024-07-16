score_list = []
for _ in range(int(input(" Enter no.of Students : "))):
    name = input(" Enter name : ")
    score = float(input(" Enter score of "+name+" : "))
    score_list.append([name, score])
second_highest = sorted(set([score for name, score in score_list]))[1]
print('\n'.join(sorted(
    [name for name, score in score_list if score == second_highest])))