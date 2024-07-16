#import pandas as pd
#from openpyxl import load_workbook
#
#password = [5353, 2900, 9918, 6814, 5678, 6921, 8105, 5127, 5254, 7588, 1970, 5192, 9315, 6239, 6205, 9358, 6399, 4454, 3603, 5853, 2429, 6583, 1994, 6181, 2039, 7397, 6989, 7805, 3961, 9190, 1721,1483, 2545, 4912, 8843, 6835, 8881]

#
#file_path = 'unit list_1.xlsx'
#
##cols = [2,3,4]
##
#df = pd.read_excel(file_path)
#
#df['password'] = password
#
#df.to_excel(file_path, index=False)
#
#print(df['password'])
##unit = pd.read_excel(file_path,usecols=c)
#
#data = df.values.tolist()
#
#data.remove(data[0])
#
#dic = {}
#
#for i, j in enumerate(password):
#    dic[data[i][2]] = str(j)
#    #data[i][2] = str(j)
#
#print(dic)

#import random
#
#all_numbers = list(range(1000, 10000))
#
## Shuffle the list
#random.shuffle(all_numbers)
#
#def generate_unique_numbers(how_many):
#    if how_many > len(all_numbers):
#        print("Not enough unique numbers available.")
#        return []
#    return [all_numbers.pop() for _ in range(how_many)]
#
## Example usage: Generate 10 unique 4-digit numbers
#unique_numbers = generate_unique_numbers(6)
#print(unique_numbers)