#!/usr/bin/python3
def weight_average(my_list=[]):
    if len(my_list) == 0:
        return 0
    scores = [score * weight for score, weight in my_list]
    total_weight = sum(weight for _, weight in my_list)
    return sum(scores) / total_weight

