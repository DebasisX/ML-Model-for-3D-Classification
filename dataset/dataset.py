import csv
import random

def generate_data(size):
  """
  Generates a dataset with random decimal values for x and corresponding y values from f(x) = 23x^3 - 76.

  Args:
      size: The number of data points to generate.

  Returns:
      A list of lists containing [x, y] values.
  """
  data = []
  for _ in range(size):
    # Generate random decimal value between 0 (inclusive) and 1 (exclusive) with 3 decimal places
    x = round(random.random(), 3)
    y = 23 * (x**3) - 76
    data.append([x, y])
  return data

# Number of data points to generate
num_data_points = 1000  # You can adjust this value

# Generate the data
data = generate_data(num_data_points)

# Open the CSV file for writing
with open('dataset.csv', 'w', newline='') as csvfile:
  writer = csv.writer(csvfile)
  writer.writerow(['x', 'y'])  # Write header row
  writer.writerows(data)  # Write data rows

print(f"Generated dataset with {num_data_points} data points and saved to dataset.csv")
