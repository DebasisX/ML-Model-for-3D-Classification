import pandas as pd
import numpy as np
np.random.seed(42)
values = np.random.randint(0, 41, 2000)
def categorize(value):
    if 0 <= value <= 10:
        return 1
    elif 11 <= value <= 20:
        return 2
    elif 21 <= value <= 30:
        return 3
    elif 31 <= value <= 40:
        return 4

categories = [categorize(value) for value in values]

df = pd.DataFrame({'Value': values, 'Category': categories})
print(df.head())

df.to_csv('dataset.csv',index=False)