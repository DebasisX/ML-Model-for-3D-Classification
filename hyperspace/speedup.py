import math

# Load dataset
def load_dataset(filename, num_samples):
    with open(filename, "r") as file:
        return [list(map(float, line.strip().split(','))) for line in file.readlines()[:num_samples]]

# Distance function
def distance(model, i, x, y, z):
    return math.sqrt(pow(abs(x - model[i][0][1]), 2) + pow(abs(y - model[i][1][1]), 2) + pow(abs(z - model[i][2][1]), 2))

# Extend model ranges
def extend(model, i, x, y, z):
    model[i][0][1] = max(model[i][0][1], x)
    model[i][0][0] = min(model[i][0][0], x)
    model[i][1][1] = max(model[i][1][1], y)
    model[i][1][0] = min(model[i][1][0], y)
    model[i][2][1] = max(model[i][2][1], z)
    model[i][2][0] = min(model[i][2][0], z)

# Train the model
def train_model(data):
    model = []
    outputs = []
    
    for pair in data:
        x, y, z, result = pair
        added = False
        
        for i in range(len(model)):
            if len(model) == 0 or result not in outputs: 
                model.append([[x, x], [y, y], [z, z], result])
                outputs.append(result)
                added = True
                break
            
            if model[i][0][1] is not None and model[i][1][1] is not None and model[i][2][1] is not None:
                if (model[i][0][0] <= x <= model[i][0][1] and
                    model[i][1][0] <= y <= model[i][1][1] and
                    model[i][2][0] <= z <= model[i][2][1]):
                    
                    res = model[i][3]
                    if res != result:
                        range_for_xlu = (x + model[i][0][0]) / 2
                        range_for_xul = (x + model[i][0][1]) / 2
                        range_for_ylu = (y + model[i][1][0]) / 2
                        range_for_yul = (y + model[i][1][1]) / 2
                        range_for_zlu = (z + model[i][2][0]) / 2
                        range_for_zul = (z + model[i][2][1]) / 2
                        
                        split1 = [[model[i][0][0], range_for_xlu], [model[i][1][1], range_for_ylu], [model[i][2][1], range_for_zlu], res]
                        split2 = [[range_for_xul, model[i][0][1]], [range_for_yul, model[i][1][0]], [range_for_zul, model[i][2][0]], res]
                        split3 = [[range_for_xlu, x], [range_for_ylu, y], [range_for_zlu, z], result]
                        split4 = [[x, range_for_xul], [y, range_for_yul], [z, range_for_zul], result]
                        
                        model.append(split1)
                        model.append(split2)
                        model.append(split3)
                        model.append(split4)
                        model.pop(i)
                        added = True
                        break
                else:
                    min_distance = float('inf')
                    min_index = None
                    
                    for index, point in enumerate(model):
                        if result == point[3] and not (point[0][1] is None or point[1][1] is None or point[2][1] is None):
                            temp_distance = distance(model, index, x, y, z)
                            if temp_distance < min_distance:
                                min_distance = temp_distance
                                min_index = index
                    
                    if min_index is None:
                        min_index = i
                    
                    extend(model, min_index, x, y, z)
                    added = True
                    break
            else:
                for j in model:
                    if j[3] == result:
                        j[0][1] = max(j[0][1], x)
                        j[0][0] = min(j[0][0], x)
                        j[1][1] = max(j[1][1], y)
                        j[1][0] = min(j[1][0], y)
                        j[2][1] = max(j[2][1], z)
                        j[2][0] = min(j[2][0], z)
                        break
                added = True
                break
        
        if not added:
            model.append([[x, x], [y, y], [z, z], result])
            outputs.append(result)

    return model

# Calculate accuracy
def accuracy(model, data):
    acc = 0
    total = len(data)
    for i in data:
        x, y, z, result = i
        for j in model:
            if (j[0][0] <= x <= j[0][1] and
                j[1][0] <= y <= j[1][1] and
                j[2][0] <= z <= j[2][1]):
                if j[3] == result:
                    acc += 1
                break
    return (acc / total) * 100

# Main execution
print("Enter I/O: ")
inp = int(input())
out = int(input())

train_data = load_dataset("dataset.csv", inp)
test_data = load_dataset("dataset.csv", inp)

model = train_model(train_data)
print("Data Loaded and Model Trained")

# I have the ranges of the model and would like to export the ranges as a csv
print("Number of Ranges:", len(model))
print("Model Accuracy:", accuracy(model, test_data))

import csv

# Function to save the model to a CSV file
def save_model_to_csv(model, filename):
    # Define the header for the CSV file
    header = ['X_min', 'X_max', 'Y_min', 'Y_max', 'Z_min', 'Z_max', 'Result']
    
    # Open the file in write mode
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        
        # Write the header
        writer.writerow(header)
        
        # Write each range of the model to the file
        for entry in model:
            row = [entry[0][0], entry[0][1], entry[1][0], entry[1][1], entry[2][0], entry[2][1], entry[3]]
            writer.writerow(row)

# Save the model to a CSV file
save_model_to_csv(model, "model_ranges.csv")
print("Model ranges exported to model_ranges.csv")
