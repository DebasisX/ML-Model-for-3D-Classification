import math

# Function to calculate Euclidean distance
def distance(model, i, data_point):
    return math.sqrt(sum(pow(abs(data_point[j] - model[i][j][1]), 2) for j in range(len(data_point) - 1)))

def accuracy(model, test_data):
    acc = 0
    total = len(test_data)
    
    for data_point in test_data:
        result = data_point[-1]
        
        for j in model:
            if j[0][1] is not None:
                if all(j[k][0] <= data_point[k] <= j[k][1] for k in range(len(data_point) - 1)):
                    res = j[-1]
                    if res == result:
                        acc += 1
                    break
    
    return (acc / total) * 100 


# Function to extend the range of the model for a specific data point
def extend(model, i, data_point):
    for j in range(len(data_point) - 1):
        if data_point[j] > model[i][j][1]:
            model[i][j][1] = data_point[j]
        elif data_point[j] < model[i][j][0]:
            model[i][j][0] = data_point[j]
print("Enter Output size and Learning rate: ")
out = int(input())
lr = int(input())
file = open("dataset.csv", "r")
test_data = [list(map(float, line.split(','))) for line in file.readlines()[out:]]
file.close()
acc = []
inp = 2
while inp <= 1000: 
    # Load data from the file
    
    
    
    file = open("dataset.csv", "r")
    ls = [list(map(float, line.split(','))) for line in file.readlines()[:inp]]
    file.close()

    # Initialize the model and outputs
    model = []
    outputs = []

    # Perform initial training
    for data_point in ls:
        result = data_point[-1]
        
        for i in range(len(model) + 1):
            i -= 1
            
            if len(model) == 0 or result not in outputs:
                model.append([[data_point[j], None] for j in range(len(data_point) - 1)] + [result])
                outputs.append(result)
                break

            # Check if all ranges are defined in the model
            if all(model[i][j][1] is not None for j in range(len(data_point) - 1)):
                if all(model[i][j][0] <= data_point[j] <= model[i][j][1] for j in range(len(data_point) - 1)):
                    res = model[i][-1]
                    
                    if res != result:
                        # Resolve conflict by splitting into ranges
                        split_ranges = []
                        for j in range(len(data_point) - 1):
                            lu = abs((data_point[j] + model[i][j][0]) / 2)
                            ul = abs((data_point[j] + model[i][j][1]) / 2)
                            split_ranges.append((lu, ul))

                        splits = [
                            [[model[i][j][0], split_ranges[j][0]] for j in range(len(data_point) - 1)] + [res],
                            [[split_ranges[j][1], model[i][j][1]] for j in range(len(data_point) - 1)] + [res],
                            [[split_ranges[j][0], data_point[j]] for j in range(len(data_point) - 1)] + [result],
                            [[data_point[j], split_ranges[j][1]] for j in range(len(data_point) - 1)] + [result]
                        ]

                        model += splits
                        model.remove(model[i])
                        print("SPLITTED")
                    break
                else:
                    # Extend the range of the nearest matching result
                    min_distance = float('inf')
                    min_index = None

                    for index, point in enumerate(model):
                        if result == point[-1] and all(point[j][1] is not None for j in range(len(data_point) - 1)):
                            temp_distance = distance(model, index, data_point)

                            if temp_distance < min_distance:
                                min_distance = temp_distance
                                min_index = index

                    if min_index is None:
                        min_index = i

                    extend(model, min_index, data_point)
                    print("EXTENDED")
                    break
            else:
                # Define the upper limit of the respective variables
                for j in model:
                    if j[-1] == result:
                        for k in range(len(data_point) - 1):
                            if data_point[k] >= j[k][0]:
                                j[k][1] = data_point[k]
                            else:
                                j[k][1] = j[k][0]
                                j[k][0] = data_point[k]
                        break
                break

    print("Data Loaded")
    acc.append([accuracy(model, test_data), inp])
    inp += 10 # learning rate
# Testing

acc.sort()

print("Lowest Model Accuracy, at I inputs: ", acc[-1])