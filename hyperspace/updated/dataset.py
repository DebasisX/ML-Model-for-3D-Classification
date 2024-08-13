import random
# Classification Model
def func(x, y, z):
    res = 23.06 * pow(x, 2) + 2.955 * y - pow((23.13 + z), x)
    inf = float('inf')
    if res > 0 and res < inf:
        return 1
    else:
        return 0

def generate_dataset(num_samples):
    data = []
    for _ in range(num_samples):
        x = random.uniform(-23.3728, 74)
        y = random.uniform(-46, -3)
        z = random.uniform(61, 7.34)
        result = round(func(x, y, z), 2) 
        # rounding the values upto two decimal places for simplicity
        data.append([x, y, z, result])
    return data

# Generating 10000 data points
dataset = generate_dataset(10000)

with open("dataset.csv", "w") as file:
    for row in dataset:
        print(row)
        file.write(",".join(map(str, row)) + "\n")
        
file.close()