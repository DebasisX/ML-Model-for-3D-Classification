import math
import time

def load_dataset(filename, num_samples):
    with open(filename, "r") as file:
        data = [list(map(float, line.strip().split(','))) for line in file.readlines()[:num_samples]]
    return data

# Calculating Euclidean distance for multiple features
def distance(features1, features2):
    return math.sqrt(sum((features1[i] - features2[i])**2 for i in range(len(features1))))

# Extending the range of the model
def extend_range(model, i, features):
    for j in range(len(features)):
        model[i][j] = [min(model[i][j][0], features[j]), max(model[i][j][1], features[j])]

# Training
def train_model(ls, num_features):
    model = []
    outputs = []

    for pair in ls:
        features = pair[:-1]
        result = pair[-1]
        added = False

        for i in range(len(model)):
            if model[i][-1] == result:
                if all(model[i][j][0] <= features[j] <= model[i][j][1] for j in range(num_features)):
                    added = True
                    break
        if not added:
            min_distance = float('inf')
            min_index = None

            for i in range(len(model)):
                if model[i][-1] == result:
                    temp_distance = distance([features[j] for j in range(num_features)], [model[i][j][0] + model[i][j][1] / 2 for j in range(num_features)])
                    if temp_distance < min_distance:
                        min_distance = temp_distance
                        min_index = i
            if min_index is not None:
                extend_range(model, min_index, features)
            else:
                model.append([[f, f] for f in features] + [result])
                outputs.append(result)

    return model

# Determining the accuracy
def calculate_accuracy(model, ls, num_features):
    correct = 0
    total = len(ls)

    for i in ls:
        features = i[:-1]
        result = i[-1]

        for j in model:
            if all(j[k][0] <= features[k] <= j[k][1] for k in range(num_features)):
                if j[-1] == result:
                    correct += 1
                break

    return (correct / total) * 100

inp = int(input("Enter no. of training samples: "))
out = int(input("Enter no. of test samples: "))
num_features = int(input("Enter number of features: "))

train_data = load_dataset("dataset.csv", inp)
test_data = load_dataset("dataset.csv", out)
t1 = time.time()

model = train_model(train_data, num_features)
print("Model Trained")

accuracy = calculate_accuracy(model, test_data, num_features)

print(f"Model Accuracy: {accuracy:.2f}%")
t2 = time.time()
print('Time: {} seconds'.format((t2 - t1)))
