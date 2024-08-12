import random
# Classification Model
# Accuracy = 96.0 on current dataset.csv
def func(x, y, z):
    res =  23 * x + 2.9 * y - (23 + z)
    if res > 100 and res < 100:
        return 2
    elif res >= 100 :
        return 1
    else:
        return 0
def generate_dataset(num_samples):
    data = []
    for _ in range(num_samples):
        x = random.randint(2, 60)
        y = random.randint(34, 52)
        z = random.randint(78, 232)
        result = round(func(x, y, z), 2) 
        # rounding the values upto two decimal places for simplicity
        data.append([x, y, z, result])
    return data

# Generating 100000 data points
dataset = generate_dataset(100000)

with open("dataset.csv", "w") as file:
    for row in dataset:
        print(row)
        file.write(",".join(map(str, row)) + "\n")
        
file.close()