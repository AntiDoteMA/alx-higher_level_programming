#!/usr/bin/python3
def best_score(a_dict):
    # Return None if the dictionary is empty or None
    if a_dict is None or len(a_dict) == 0:
        return None

    # Find the key with the maximum value
    best_key = max(a_dict, key=a_dict.get)

    return best_key
